#include <iostream>
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

using std::string;
using std::vector;

//-------------------------------------------------------------------------------------------//
user_data MakeUserData(string name, int score, string time)
{
    user_data user = {name, score, time};
    return user;
}

vector<user_data> Data::ReadGameHistory()
{
    string line;
    string user_name;
    int user_score;
    string user_time;
    vector<user_data> user_list;
    const std::string gameDataDirectory{"../history"};

    std::ifstream filestream(gameDataDirectory + "/" + "game_history.txt");

    if (filestream.is_open())
    {
        while (std::getline(filestream, line))
        {

            std::istringstream linestream(line);
            while (linestream >> user_name >> user_score >> user_time)
            {
                user_list.push_back(MakeUserData(user_name,user_score,user_time));
            }
        }
        filestream.close();
        std::cout << "==>Finishing reading file ..." << std::endl;
    }
    else
    {
        std::ofstream outfile("game_history.txt");
        std::cout << "==>Error: Can not find the game_history.txt file!"<< std::endl;
        std::cout << "==>The history for this game does not exist ...!" << std::endl;
    }

    return user_list;
}

//-------------------------------------------------------------------------------------------//

void Data::WriteGameHistory(User *user)
{
    const std::string gameDataDirectory{"../history"};

    std::ofstream filestream(gameDataDirectory + "/" + "game_history.txt", std::ios::in | std::ios::out | std::ios::app);

    if (!filestream.is_open())
    {
        std::cout << " ==>Error: Can not open the file!" << std::endl;
    }
    else
    {
        filestream << user->GetUserName() << " " << user->GetUserScore() << " " << user->GetUserGameTime() << "\n";
        filestream.close();
    }
}

//-------------------------------------------------------------------------------------------//

void Data::DisplaySortedUsers(vector<user_data> data_list)
{
    typedef std::function<bool(user_data, user_data)> Comparator;

    Comparator compFunctor =
        [](user_data elem1, user_data elem2)
    {
        return elem1.user_score > elem2.user_score;
    };

    std::set<user_data, Comparator> sorted_map(
        data_list.begin(), data_list.end(), compFunctor);

    int i = 1;
    for (auto element : sorted_map)
    {
        std::cout << i << ". user : " << element.user_name << ", score : " << element.user_score << ", time : " << element.user_time << std::endl;
        i++;
        if (i > 10)
            break;
    }
}

//-------------------------------------------------------------------------------------------//
