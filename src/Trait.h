#ifndef TRAIT_H
#define TRAIT_H

#include "DiceRoll.h"

class Trait
{
public:
    virtual void modify(DiceRoll& roll);
}

#endif