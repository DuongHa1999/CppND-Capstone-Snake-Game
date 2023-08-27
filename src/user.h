#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <vector>
#include "snake.h"

using std::string;

class User
{

public:
    User() { std::cout << "--- New User --- " << std::endl; };
    User(string, int, string);
    ~User(){};
    Snake newsnake();

    string GetUserName();
    int GetUserScore();
    string GetUserGameTime();

    void SetUserName(string name);
    void SetUserScore(int score);
    void SetUserGameTime(string time);

private:
    string name_;
    int score_;
    string time_;
};

#endif