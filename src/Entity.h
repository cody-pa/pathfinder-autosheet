#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include "Trait.h"
#include "DiceRoll.h"

using std::vector;

class Entity
{
private:
    vector<Trait> traits;
public:
    virtual void modify_roll(DiceRoll& roll) = 0;
    virtual int STR() = 0;
    virtual int DEX() = 0;
    virtual int CON() = 0;
    virtual int INT() = 0;
    virtual int WIS() = 0;
    virtual int CHA() = 0;
};

#endif