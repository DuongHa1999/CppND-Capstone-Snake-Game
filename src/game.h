#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"

class Game
{
public:
    enum class game_level
    {
        Easy      = 1,
        Difficult = 2
    };
    Game(std::size_t grid_width, std::size_t grid_height);
    void Run(Controller const &controller, Renderer *renderer,
             std::size_t target_frame_duration);
    int GetScore() const;
    int GetSize() const;
    void Pause();
    void Wall();
    void SpeedUp();
    void SpeedDown();
    void SetGameLevel(game_level level);
    friend class Controller;

protected:
    bool wall_; // wall around the game screen

private:
    Snake snake;
    SDL_Point food;
    bool pause_;
    bool poison_;
    bool slow_;

    std::random_device dev;
    std::mt19937 engine;
    std::uniform_int_distribution<int> random_w;
    std::uniform_int_distribution<int> random_h;

    int score{0};

    void PlaceFood();
    void Update(Renderer *renderer, int level);
    game_level level_;
};

#endif