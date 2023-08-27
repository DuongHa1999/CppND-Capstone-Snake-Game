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

    void SetUserName();
    void SetUserScore();
    void SetUserGameTime();
    float GetHeadDistance();

private:
    string user_name;
    int user_score;
    string user_game_time;
    float user_snake_head_travel_distance;
    //vector<User*> v_user;
};
