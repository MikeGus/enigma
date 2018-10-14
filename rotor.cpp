#include "rotor.h"


Rotor::Rotor(std::istream& stream): pos(0)
{
    stream.read(set, ALPHABET_SIZE);
}


char Rotor::rotate()
{
    ++pos %= ALPHABET_SIZE;
    return set[pos];
}

unsigned Rotor::getPos() const
{
    return pos;
}

char Rotor::getValue() const
{
    return ALPHABET[pos];
}

char Rotor::getNext(char input) const
{
    return set[input - ALPHABET[0]];
}


char Rotor::getPrev(char input) const
{
    for (unsigned i = 0; i < ALPHABET_SIZE; ++i) {
        if (input == set[i]) {
            return ALPHABET[i];
        }
    }
    return -1;
}


void Rotor::setPos(unsigned pos)
{
    this->pos = pos;
}

void Rotor::setValue(char val)
{
    for (unsigned i = 0; i < ALPHABET_SIZE; ++i) {
        if (val == ALPHABET[i]) {
            pos = i;
        }
    }
}
