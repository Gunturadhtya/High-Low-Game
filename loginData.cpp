#include "loginData.hpp"
#include <iostream>
#include <fstream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::vector;
loginData::loginData()
{
}

loginData::~loginData()
{
}

int loginData::login()
{
    readUsername();
    readPassword();
    //readScore();
    
    cout << "Username : ";
    cin >> username;
    cout << "Password : ";
    cin >> password;
    
    int vecSize = usernameSignin.size();
    for (int i = 0; i < vecSize; i++)
    {
        if((username == usernameSignin[i]) and (password == passwordSignin[i]))
        {
            cout << "Login Successfull at index : " << i << endl;
            accountIndex = i;
            loginStatus = true;
            return(0);
        }
    }
    cout << "Login Failed .. " << endl;
    return 0;
}

void loginData::signin()
{
    cout << "Make a new account \n";
    cout << "Username : ";
    cin >> username;
    cout << "Password : ";
    cin >> password;
    fstream userSignIn;
    
    userSignIn.open(fname, fstream::app);
    userSignIn << username << delimiter << password << delimiter << score << delimiter;
    userSignIn << "\n";
    userSignIn.close();
}

void loginData::readUsername()
{
    fstream readFile(fname);
    string data;
    
    size_t pos = 0;
    string token;
    while(getline(readFile, data))
    {
        while((pos = data.find(delimiter)) != string::npos)
        {
            token = data.substr(0, pos);
            usernameSignin.push_back(token);
            data.erase(0, data.length());
        }
    }
}

void loginData::readPassword()
{
    fstream readFile(fname);
    string data;
    
    size_t pos = 0;
    string token;
    while(getline(readFile, data))
    {
        while((pos = data.find(delimiter)) != string::npos)
        {
            data.erase(0, pos + delimiter.length());
            pos = data.find(delimiter);
            
            token = data.substr(0, pos);
            passwordSignin.push_back(token);
            data.erase(0, data.length());
        }
    }
}

void loginData::readScore()
{
    fstream readFile(fname);
    string data;
    
    size_t pos = 0;
    string token;
    while(getline(readFile, data))
    {
        while((pos = data.find(delimiter)) != string::npos)
        {
            for (int i = 0; i < 2; i++)
            {
                data.erase(0, pos + delimiter.length());
                pos = data.find(delimiter);
            }
            
            token = data.substr(0, pos);
            scoreSignin.push_back(token);
            data.erase(0, data.length());
            
        }
    }
}

void loginData::updateScore(vector<string> score)
{
    std::ofstream readFile;
    
    readUsername();
    readPassword();
    
    readFile.open(fname);
    
    int row = usernameSignin.size();
    for(int i = 0; i < row; i++)
    {
        readFile << usernameSignin[i] << delimiter << passwordSignin[i] << delimiter << score[i] << delimiter << '\n';
    }
    readFile.close();
}