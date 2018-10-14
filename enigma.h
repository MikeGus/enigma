#ifndef ENIGMA_H
#define ENIGMA_H

#include "rotor.h"
#include "reflector.h"
#include <memory>
#include <string>

class Enigma
{
public:
    Enigma();
    char encode(char input);
    std::string encode(std::string& input);

    char decode(char input);

private:
    char rightStraight(char input);
    char middleStraight(char input);
    char leftStraight(char input);
    char reflect(char input);
    char leftReverse(char input);
    char middleReverse(char input);
    char rightReverse(char input);
    char finalizeReverse(char input);

    std::shared_ptr<Rotor> right;
    std::shared_ptr<Rotor> middle;
    std::shared_ptr<Rotor> left;
    std::shared_ptr<Reflector> reflector;

    unsigned middleShiftPosition;

    char rightStartingValue;
    char middleStartingValue;
    char leftStartingValue;
};

#endif // ENIGMA_H
