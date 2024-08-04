#ifndef LOGINDATA_HPP
#define LOGINDATA_HPP
#include <string>
#include <vector>

using std::string;
using std::vector;
class loginData
{
//public:
    string password;
    string username;
    string score{"0"};
    string fname{"user_database.txt"};
    string delimiter{"<=>"};
    
    
    
    vector<string> usernameSignin;
    vector<string> passwordSignin;
    
    
public:
    int accountIndex;
    vector<string> scoreSignin;
    bool loginStatus{false}; //represent login status
    vector<string> userData;
    loginData(); // this function is non function for now
    ~loginData();
    
    void signin(); // function to signin
    int login();
    void readUsername();
    void readPassword();
    void readScore();
    void updateScore(vector<string> score);
};

#endif // LOGINDATA_HPP
