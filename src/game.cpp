#include "game.h"
#include <iostream>
#include "SDL.h"
#include <thread>
#include <chrono>
#include <future>

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : snake(grid_width, grid_height, &score),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width)),
      random_h(0, static_cast<int>(grid_height))
{
    PlaceFood();
}

void Game::Run(Controller const &controller, Renderer *renderer,
             std::size_t target_frame_duration)
{
    Uint32 title_timestamp = SDL_GetTicks();
    Uint32 frame_start;
    Uint32 frame_end;
    Uint32 frame_duration;
    int frame_count = 0;
    bool running = true;

    while (running)
    {
        frame_start = SDL_GetTicks();

        // Input, Update, Render - the main game loop.
        controller.HandleInput(running, snake, *this);
        Update(renderer);
        renderer->Render(snake, food, &wall_, &poison_, &slow_);

        frame_end = SDL_GetTicks();

        // Keep track of how long each loop through the input/update/render cycle
        // takes.
        frame_count++;
        frame_duration = frame_end - frame_start;

        // After every second, update the window title.
        if (frame_end - title_timestamp >= 1000)
        {
            renderer->UpdateWindowTitle(score, frame_count, &wall_, &poison_, &slow_);
            frame_count = 0;
            title_timestamp = frame_end;
        }

        // If the time for this frame is too small (i.e. frame_duration is
        // smaller than the target ms_per_frame), delay the loop to
        // achieve the correct frame rate.
        if (frame_duration < target_frame_duration)
        {
            SDL_Delay(target_frame_duration - frame_duration);
        }
    }
}

void TimerThread(Snake *snake, bool *option, int time_s)
{
    float pre_speed = 0.1 + 0.01*(snake->size-1);
    std::this_thread::sleep_for(std::chrono::seconds(time_s));
    *option = false;
    snake->speed = pre_speed;
}

void Game::PlaceFood()
{
    int x, y;
    while (true)
    {
        x = random_w(engine);
        y = random_h(engine);
        // Check that the location is not occupied by a snake item before placing
        // food.
        if (!snake.SnakeCell(x, y))
        {
            food.x = x;
            food.y = y;
            return;
        }
    }
}

void Game::Update(Renderer *renderer)
{
    if (this->pause_ == true)
    {
        renderer->SetPauseTitle();
        return;
    };

    if (!snake.alive)
    {
        return;
        // renderer->~Renderer();
    }

    snake.Update(&wall_);

    int new_x = static_cast<int>(snake.head_x);
    int new_y = static_cast<int>(snake.head_y);

    std::random_device rd;  // Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(1, 10);

    // Check if there's food over here
    if (food.x == new_x && food.y == new_y)
    {
        score++;
        PlaceFood();
        // Grow snake and increase speed.
        snake.GrowBody();

        if(score > 20 || level_ == game_level::Difficult)
        {
            wall_ = true;
            if (dis(gen) <= 2)
            {
                poison_ = true;
                // resolves 3 seconds later
                std::thread poisonTimer(TimerThread, &snake, &poison_, 3);
                poisonTimer.detach();
            }
        }
        else
        {
            snake.speed += 0.01;
        }
        if (dis(gen) <= 3)
        {
            slow_ = true;
            // resolves 10 seconds later
            std::thread slowTimer(TimerThread, &snake, &slow_, 10);
            slowTimer.detach();
            snake.speed = 0.05;
        }
    }
}

void Game::Wall()
{
    this->wall_ ? this->wall_ = false : this->wall_ = true;
}

void Game::Pause()
{
    this->pause_ ? this->pause_ = false : this->pause_ = true;
}

void Game::SetWall(bool wall)
{
    this->wall_ = wall;
}

void Game::SetGameLevel(game_level level)
{
    level_ = level;
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }