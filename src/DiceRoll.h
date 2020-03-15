#ifndef DICEROLL_H
#define DICEROLL_H

#include <string>
#include <iostream>
#include "kp-lib/CPP/Result.h"
#include "kp-lib/C/lib.h"

class DiceRoll
{
private:
    unsigned int count;
    unsigned int die_size;
    int modifier;
    Result<int> last_result;
    bool ready;

    int perform_roll();
public:
    Result<int> roll(std::string input);
    Result<int> roll();
    DiceRoll();
    DiceRoll(unsigned int p_count, unsigned int p_die_size, int p_modifier);
};


#endif