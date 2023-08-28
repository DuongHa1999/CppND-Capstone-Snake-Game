#include "user.h"
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

User::User(string name, int score, string time)
{
    this->name_ = name;
    this->score_ = score;
    this->time_ = time;
}

string User::GetUserName()
{

    return name_;
}

int User::GetUserScore()
{
    return score_;
}

string User::GetUserGameTime()
{
    return time_;
}

void User::SetUserGameTime(string time)
{
    this->time_ = time;
}

void User::SetUserName(string name)
{
    this->name_ = name;
}

void User::SetUserScore(int score)
{
    this->score_ = score;
}

