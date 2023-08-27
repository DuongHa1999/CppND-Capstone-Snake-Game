#include <iostream>
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
    void History();
    void UserManual();
    void ManageNewUser(User *user);
    void Run();

private:
    //     User *user;
    std::unique_ptr<User> user_;
    vector<User *> v_user;
};