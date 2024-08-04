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
    
    
    
    vector<string> usernameSignin; // store the collection of username
    vector<string> passwordSignin; // store the collection of password
    
    
public:
    int accountIndex; // store the position of account
    vector<string> scoreSignin; // store the collection of score
    bool loginStatus{false}; //represent login status
    loginData(); // this function is non functional for now
    ~loginData();
    
    void signin(); // function to signin
    int login(); // function to login
    void readUsername(); // read username on database and push it into private vector<string> usernameSignin;
    void readPassword(); // read username on database and push it into private vector<string> passwordSignin;
    void readScore(); // read username on database and push it into public vector<string> scoreSignin;
    void updateScore(vector<string> score);// update score
};

#endif // LOGINDATA_HPP
