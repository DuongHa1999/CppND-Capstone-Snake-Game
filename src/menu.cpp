#include "menu.h"
#include "data.h"
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "SDL.h"
#include <vector>
#include <fstream>
#include <dirent.h>
#include <unistd.h>
#include <sstream>
#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
#include <set>
#include <iostream>

void Menu::SaveUser(User *user)
{
    //     Data *newdm = new Data();
    // std::unique_ptr<Data> data = std::make_unique<Data>();
    // std::map<string, int> actual_user_map;
    // actual_user_map.insert(std::make_pair(user->GetUserName(), user->GetUserScore()));
    // data->WriteGameHistoryMap(actual_user_map);
    std::unique_ptr<Data> data = std::make_unique<Data>();
    data->WriteGameHistoryMap(user);
}

void Menu::UserManual()
{
    std::cout << "\n ================================ \n";
    std::cout <<   "|     Snake game User Manual     |\n";
    std::cout <<   " ================================ \n";
    std::cout <<   "|       Up    : Go up            |\n";
    std::cout <<   "|       Down  : Go down          |\n";
    std::cout <<   "|       Left  : Turn left        |\n";
    std::cout <<   "|       Right : Turn right       |\n";
    std::cout <<   "|       Esc   : Back             |\n";
    std::cout <<   "'================================'\n";
}

void Menu::GameLevel()
{

}

void Menu::History()
{
    Data data;
    vector<user_data> game_history;
    game_history = data.ReadGameHistory();
    if (game_history.size() > 0)
    {
        data.DisplaySortedUsers(game_history);
    }
}

void Menu::Play()
{
    constexpr std::size_t kFramesPerSecond{60};
    constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
    constexpr std::size_t kScreenWidth{640};
    constexpr std::size_t kScreenHeight{640};
    constexpr std::size_t kGridWidth{32};
    constexpr std::size_t kGridHeight{32};

    Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
    Controller controller;
    Game game(kGridWidth, kGridHeight);
    game.Run(controller, renderer, kMsPerFrame);
    std::cout << "Game has terminated successfully!\n";
    std::cout << "Score: " << game.GetScore() << "\n";
    std::cout << "Size: " << game.GetSize() << "\n";
}

void Menu::Run()
{
    int option = 0;
    // Menu menu;

    while (option != 5)
    {
        std::cout << "\033[2J\033[1;1H";
        std::cout << "\n ======================================== \n";
        std::cout <<   "|     Snake game management program      |\n";
        std::cout <<   " ======================================== \n";
        std::cout <<   "|         Enter 1: Play                  |\n";
        std::cout <<   "|         Enter 2: Game level            |\n";
        std::cout <<   "|         Enter 3: User manual           |\n";
        std::cout <<   "|         Enter 4: History               |\n";
        std::cout <<   "|         Enter 5: Exit game             |\n";
        std::cout <<   "'========================================'\n";
        std::cout <<   "|      ==>";
        std::cin >> option;
        if (option != 1 && option != 2 && option != 3 && option != 4 && option != 5)
        {
            std::cout << "Error: This option is not available, please re-enter!";
        }
        else
        {
            switch (option)
            {
            case 1: /* Play */
            {
                string name;
                user_ = std::make_unique<User>();
                std::cout << "\n ======================================== \n";
                std::cout <<   "|                 Add User               |\n";
                std::cout <<   " ======================================== \n";
                std::cout <<   "|      ==>";
                std::cin>>name;
                user_->SetUserName(name);
                this->Play();
                this->SaveUser(user_.get());
                break;
            }
            case 2: /* Game level */
            {
                this->GameLevel();
                break;
            }
            case 3: /* User manual */
            {
                this->UserManual();
                break;
            }
            case 4: /* History */
            {
                this->History();
                break;
            }
            default: /* Exit */
            {
                std::cout << "==>The program has stopped, thank you for using!\n";
                break;
            }
            }
            if (option != 5)
            {
                std::cout << "==>Press Enter to continues...!\n";
                getchar(); /* Wait screen */
                getchar();
            }
        }
    }
}
