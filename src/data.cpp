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

std::map<string, int> Data::ReadGameHistoryMap()
{

  string line;
  string user_name;
  int user_score;
  std::map<string, int> users_map;
  std::map<string, int>::iterator it;
  const std::string gameDataDirectory{"../data"};

  std::ifstream filestream(gameDataDirectory + "/" + "game_record.txt");

  if (filestream.is_open())
  {
    while (std::getline(filestream, line))
    {

      std::istringstream linestream(line);
      while (linestream >> user_name >> user_score)
      {

        users_map.insert(std::make_pair(user_name, user_score));
      }

      //return v_user_name;
    }
    filestream.close();
    std::cout << "finishing reading file ..." << std::endl;
    return users_map;
  }
  else
  {
    std::ofstream outfile("game_record.txt");
    std::cout << "RECORD file does not exist. New is created." << std::endl;
  }
}

//-------------------------------------------------------------------------------------------//

void Data::WriteGameHistoryMapSorted(std::map<string, int> aux_map)
{

  std::ofstream dataFile;

  dataFile.open("game_record.txt", std::ios::in | std::ios::out | std::ios::app);
  if (!dataFile.is_open())
  {
    std::cout << " not possible to open file" << std::endl;
  }
  else
  {
    std::map<string, int> sorted_aux_map;

    typedef std::function<bool(std::pair<std::string, int>, std::pair<std::string, int>)> Comparator;

    Comparator compFunctor =
        [](std::pair<std::string, int> elem1, std::pair<std::string, int> elem2) {
          return elem1.second > elem2.second;
        };

    // Declaring a set that will store the pairs using above comparision logic
    std::set<std::pair<std::string, int>, Comparator> sorted_map(
        aux_map.begin(), aux_map.end(), compFunctor);

    // Iterate over a set using range base for loop
    // It will display the items in sorted order of values
    int ii = 1;
    for (std::pair<std::string, int> element : sorted_map)
    {
      dataFile << ii << ". user : " << element.first << ", score : " << element.second << "\n";
      ii++;
    }

    dataFile.close();
  }
}

//-------------------------------------------------------------------------------------------//

void Data::WriteGameHistoryMap(std::map<string, int> users_map)
{

  std::map<string, int>::iterator it;

  std::ofstream dataFile;

  dataFile.open("game_record.txt", std::ios::in | std::ios::out | std::ios::app);
  if (!dataFile.is_open())
  {
    std::cout << " not possible to open file" << std::endl;
  }
  else
  {

    for (it = users_map.begin(); it != users_map.end(); it++)
    {

      dataFile << (*it).first << " " << (*it).second << "\n";
    }

    dataFile.close();
  }
}

//-------------------------------------------------------------------------------------------//

void Data::DisplaySortedUsers(std::map<string, int> aux_map)
{

  std::cout << "called :: " << __FUNCTION__ << "   size  ::" << aux_map.size() << std::endl;
  std::map<string, int> sorted_aux_map;

  typedef std::function<bool(std::pair<std::string, int>, std::pair<std::string, int>)> Comparator;

  Comparator compFunctor =
      [](std::pair<std::string, int> elem1, std::pair<std::string, int> elem2) {
        return elem1.second > elem2.second;
      };

  // Declaring a set that will store the pairs using above comparision logic
  std::set<std::pair<std::string, int>, Comparator> sorted_map(
      aux_map.begin(), aux_map.end(), compFunctor);

  // Iterate over a set using range base for loop
  // It will display the items in sorted order of values
  int ii = 1;
  // while(ii<11){

  for (std::pair<std::string, int> element : sorted_map)
  {
    std::cout << ii << ". user : " << element.first << ", score : " << element.second << std::endl;
    ii++;
    if (ii > 10)
      break;
  }
}

//-------------------------------------------------------------------------------------------//
