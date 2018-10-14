#ifndef REFLECTOR_H
#define REFLECTOR_H

#include <iostream>
#include <utility>
#include "utils.h"

const unsigned PAIR_NUMBER = ALPHABET_SIZE / 2;

class Reflector
{
public:
    Reflector(std::istream& stream);
    char reflect(char input) const;

private:
    std::pair<char, char> set[PAIR_NUMBER];
};

#endif // REFLECTOR_H
