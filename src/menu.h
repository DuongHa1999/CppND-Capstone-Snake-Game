#include <iostream>
#include "user.h"
#include <vector>

using std::vector;

class Menu
{

public:
    Menu(){};

    void SaveUser(User *user);
    void Play();
    void History();
    void UserManual();
    void ManageNewUser(User *user);
    void Run();
    void DumpDataToFile(User *user);
    void RetriveDataFromFile();
    void temp_print_vector_of_object_pointers(vector<User *> v);
    static bool  = false;

private:
    User *user;
    vector<User *> v_user;
};