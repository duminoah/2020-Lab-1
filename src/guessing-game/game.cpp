#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main()
{
    srand(time(0));
    int rand_number = (rand()%100)+1;
    int user_input;
    cout << "Guess the random number generated: ";
    for(int i = 0;i < 5;i++)
    {
        cin >> user_input;
        cout << endl;
        if(user_input == rand_number)
            {
            cout << "You Win";
            break;
        }
        else if(user_input < rand_number && i != 4)
            {
                cout << "Guess Higher: ";
            }
        else if(user_input > rand_number && i != 4)
            {
                cout << "Guess Lower: ";
            }
        if(i == 4)
        {
           cout <<"You Lose";
        }
    }
}
