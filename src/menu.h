#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "game.h"
#include "user.h"
#include <vector>
#include <memory>

using std::vector;

class Menu
{

public:
    Menu(){};
    ~Menu(){};

    void SaveUser(User *user);
    void Play();
    void GameLevel();
    void History();
    void UserManual();
    void ManageNewUser(User *user);
    void Run();

private:
    std::unique_ptr<User> user_;
};

#endif