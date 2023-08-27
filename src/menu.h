#include <iostream>
#include "user.h"
#include <vector>

using std::vector;

class Menu
{

public:
    Menu()
    {

        std::cout << " " << std::endl;
    };

    void ManageNewUser(User *user);
    bool InitManager();
    void DumpDataToFile(User *user);
    void RetriveDataFromFile();
    void temp_print_vector_of_object_pointers(vector<User *> v);
    static bool quit_game_flag;

private:
    User *user;
    vector<User *> v_user;
};