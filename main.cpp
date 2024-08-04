#include <iostream>
#include <cstring>
#include <random>
#include "loginData.hpp"
using std::cin;
using std::cout;
using std::endl;

void HighLow(int chance,int win, int lose, int stageStart, int stageEnd, int accountIndex)
{
    loginData user;
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> hilo(stageStart, stageEnd);
    
    int number = hilo(rng);
    user.readScore();
    int score = stoi(user.scoreSignin[accountIndex]);
    
    int guess;
    
    for(int i = chance; i > 0; i--)
    {
        
        cout << "Guess your number : " ;
        cin >> guess;
        
        if (guess > number)
        {
            cout << "Too High" << endl;
        }
        if (guess < number)
        {
            cout << "Too Low" << endl;
        }
        if (guess == number)
        {
            score += win;
            cout << "Congrats You Won\n" << "Your Score is : " << score << endl;
            break;
        }
    }
    if (guess == number)
    {
        user.scoreSignin[accountIndex] = std::to_string(score);
    }
    else
    {
        score -= lose;
        cout << "You Lose\n" << "your Score is : " << score << endl;
        user.scoreSignin[accountIndex] = std::to_string(score);
    }
    user.updateScore(user.scoreSignin);
    
}

int main(int argc, char **argv)
{
    loginData user;
    
    cout << "Welcome into HiLoJudol\n";
    cout << "Are you new?? ";
    std::string choice;
    cin >> choice;
    if (choice == "yes")
    {
        user.signin();
        cout << "Welcome, please login with your account\n";
        user.login();
    }
    else if (choice == "no")
    {
        user.login();
    }
    else 
    {
        cout << "Error input .. bzztt.. only accept yes or no bzzt...\n";
        return 0;
    }
    
    
    if (user.loginStatus == true)
    {
        user.readScore();
        cout << "Welcome your score is : " << user.scoreSignin[user.accountIndex] << endl;
        cout << "Pick a Difficulty : \n1. Easy (Win +1 || Lose -1)\n2. Normal (Win +10 || Lose -15)\n3. Hard (Win +100 || Lose -120)\n4. Impossible (Win +1000 || Lose -1200)\n";
        int choice;
        cin >> choice;
        switch(choice)
        {
            case 1 :
                HighLow(15, 1, 1, 0, 50, user.accountIndex);
                break;
            case 2 :
                HighLow(10, 10, 15, 0, 190, user.accountIndex);
                break;
            case 3 :
                HighLow(10, 100, 120, 0, 1430, user.accountIndex);
                break;
            case 4 :
                HighLow(5, 1000, 1200, -1823, 5730, user.accountIndex);
                break;
        }
    }
    // TODO: ADD A HIGH LOW GAME AND CALCULATE IT SCORE
    
    
    
	return 0;
}
