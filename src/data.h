#ifndef DATA_H
#define DATA_H

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
#include "user.h"

using std::string;
using std::vector;

typedef struct
{
    string user_name;
    int user_score;
    string user_time;
} user_data;

class Data
{

public:
    Data(){};
    ~Data(){};
    vector<user_data> ReadGameHistory();
    void WriteGameHistory(User *user);
    void DisplaySortedUsers(vector<user_data> data_list);
private:
    // vector<user_data> user_list;
};

#endif