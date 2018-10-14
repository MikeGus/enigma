#ifndef ROTOR_H
#define ROTOR_H

#include <iostream>
#include "utils.h"

class Rotor
{
public:
    Rotor(std::istream &stream);
    char rotate();
    unsigned getPos() const;
    char getValue() const;
    char getNext(char input) const;
    char getPrev(char input) const;

    void setPos(unsigned pos);
    void setValue(char val);

private:
    unsigned pos;
    char set[ALPHABET_SIZE];

};

#endif // ROTOR_H
