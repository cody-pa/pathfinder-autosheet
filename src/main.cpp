#include <iostream>
#include "DiceRoll.h"

using namespace std;

int main()
{
    srand(time(0));
    
    DiceRoll roll;
    cout << "Input a roll >> ";
    string input;
    std::getline(cin, input);
    roll.roll(input);
    return 0;
}