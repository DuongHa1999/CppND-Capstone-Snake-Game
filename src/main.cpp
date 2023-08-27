#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "menu.h"
#include <string>
#include <vector>
#include <fstream>
#include <dirent.h>
#include <unistd.h>
#include <sstream>
#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
#include <set>
#include "data.h"
#include "snake.h"

int main()
{
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  bool start_game;
  int user_score;
  start_game = false;
  std::map<string, int> actual_user_map;
  std::string actual_user_name;
  // Snake tempSnake;
  bool quit_game_flag = false;

  while (true)
  {

    while (start_game == false)
    {
      Menu gm;

      if (gm.quit_game_flag == true)
      {
        return 0;
      }

      start_game = gm.InitManager();
    }
    start_game = false;
    User *newuser = new User();
    Data *newdm = new Data();
    // Snake newsnake;
    newuser->SetUserName();
    // tempSnake.head_total_distance = 0;

    std::cout << "begin the game" << std::endl;

    Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);

    Controller controller;
    Game game(kGridWidth, kGridHeight);
    game.Run(controller, renderer, kMsPerFrame);

    std::cout << "INFO. Game has terminated successfully!\n\n";

    std::cout << "-----------------------------------" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    actual_user_name = newuser->GetUserName();
    std::cout << " User Name  ::  " << actual_user_name << std::endl;
    std::cout << "Score: " << game.GetScore() << "\n";
    user_score = game.GetScore();
    std::cout << "Size: " << user_score << "\n";
    // std::cout << "Snake head travel ::" << tempSnake.head_total_distance << std::endl;

    actual_user_map.insert(std::make_pair(actual_user_name, user_score));
    newdm->WriteGameHistoryMap(actual_user_map);
  }
  return 0;
}