#include "user.h"
#include <iostream>
#include <string>
#include<ctime>
#include<vector>

using std::string;
using std::vector;


User::User(string user_name, int user_score, string user_game_time){

    std::cout<<"--- New User --- "<< std::endl;

    this->user_name = user_name;
    this->user_score = user_score;
    this->user_game_time = user_game_time;
}

string User::GetUserName(){

    return user_name;
}

int User::GetUserScore(){

    
    return user_score;
}

string User::GetUserGameTime(){
    return user_game_time;
}

void User::SetUserGameTime(){
    //current date/time on local machine
    time_t now = time(0);
    //convert to char
    char* dt = ctime(&now);
    user_game_time = dt;
    std::cout << "game time ::: "<< user_game_time;
    
}    

void User::SetUserName(){
    
    string user_name;
    std::cout<<"User NAME :::  ";
    std::cin >> user_name;
    this->user_name = user_name;
}

void User::SetUserScore(){
    int user_score;
    std::cout<< "User game score :::  ";
    std::cin >> user_score;
    this->user_score = user_score;

}

float User::GetHeadDistance(){

    
}




