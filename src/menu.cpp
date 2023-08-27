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

void Menu::SaveUser(User *user)
{
    Data *newdm = new Data();
    std::map<string, int> actual_user_map;
    actual_user_map.insert(std::make_pair(user->GetUserName(), user->GetUserScore()));
    newdm->WriteGameHistoryMap(actual_user_map);
}

void Menu::UserManual()
{
        std::cout << "\n ================================ \n";
        std::cout <<   "|     Snake game User Manual     |\n";
        std::cout <<   " ================================ \n";
        std::cout <<   "|       Up    : Go up            |\n";
        std::cout <<   "|       Down  : G0 down          |\n";
        std::cout <<   "|       Left  : Turn left        |\n";
        std::cout <<   "|       Right : Turn right       |\n";
        std::cout <<   "|       Esc   : Exit game        |\n";
        std::cout <<   "'================================'\n";
}

void Menu::History()
{
    Data data;
    std::map<string, int> recorded_users;
    recorded_users = data.ReadGameHistoryMap();
    if (recorded_users.size() > 0)
    {
        data.DisplaySortedUsers(recorded_users);
    }
    else
    {
        std::cout << "The history for this game does nor exist ...!" << std::endl;
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
        std::cin.clear();
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
        if(option != 1 && option != 2 && option != 3 && option != 4)
        {
            std::cout << "Error: This option is not available, please re-enter!";
        }
        else
        {
            switch (option)
            {
                case 1: /* Play */
                {
                    User *newuser = new User();
                    newuser->SetUserName();
                    this->Play();
                    this->SaveUser(newuser);
                    break;
                }
                case 2: /* Game level */
                {
//                     this.GameLevel();
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
            if(option != 5)
            {
                system("pause"); /* Wait screen */
            }
        }
    }
}

void Menu::ManageNewUser(User *user)
{

    user->SetUserName();
}

void Menu::DumpDataToFile(User *user)
{

    std::cout << "call the function " << __FUNCTION__ << std::endl;

    std::cout << "user ::  " << user->GetUserName() << " :: " << user->GetUserScore() << " :: " << user->GetUserGameTime() << std::endl;
}

void Menu::temp_print_vector_of_object_pointers(vector<User *> v_user)
{

    int v_user_size = v_user.size();

    for (int i = 0; i < v_user_size; i++)
    {
        std::cout << "----------------------------------------------------------------" << std::endl;
        std::cout << "user vector::  " << v_user[i]->GetUserName() << std::endl;
    }
}
