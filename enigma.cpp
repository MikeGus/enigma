#include "enigma.h"
#include <fstream>

Enigma::Enigma()
{
    std::ifstream rightRotorInitializer("right_rotor.enig");
    right = std::make_shared<Rotor>(Rotor(rightRotorInitializer));
    std::ifstream middleRotorInitializer("middle_rotor.enig");
    middle = std::make_shared<Rotor>(Rotor(middleRotorInitializer));
    std::ifstream leftRotorInitializer("left_rotor.enig");
    left = std::make_shared<Rotor>(Rotor(leftRotorInitializer));
    std::ifstream reflectorInitializer("reflector.enig");
    reflector = std::make_shared<Reflector>(Reflector(reflectorInitializer));
    std::ifstream generalSettings("general_settings.enig");
    generalSettings >> middleShiftPosition >> rightStartingValue >> middleStartingValue >> leftStartingValue;

    right.get()->setValue(rightStartingValue);
    middle.get()->setValue(middleStartingValue);
    left.get()->setValue(leftStartingValue);
}

char Enigma::encode(char input)
{
    return finalizeReverse(
                rightReverse(
                middleReverse(
                leftReverse(
                reflect(
                leftStraight(
                middleStraight(
                rightStraight(input))))))));
}

std::string Enigma::encode(std::string& input)
{
    std::string result;
    for (auto& symbol : input) {
        result.push_back(encode(symbol));
    }
    return result;
}

char Enigma::rightStraight(char input)
{
    right.get()->rotate();
    if (right.get()->getPos() == middleShiftPosition) {
        middle.get()->rotate();
    }

    char transformedInput = ALPHABET[(ALPHABET_SIZE + (right.get()->getValue() - ALPHABET[0]) + (input - ALPHABET[0])) % ALPHABET_SIZE];
    return right.get()->getNext(transformedInput);
}

char Enigma::middleStraight(char input)
{
    char transformedInput = ALPHABET[(ALPHABET_SIZE + (input - ALPHABET[0]) + middle.get()->getValue() - right.get()->getValue()) % ALPHABET_SIZE];
    return middle.get()->getNext(transformedInput);
}

char Enigma::leftStraight(char input)
{
    char transformedInput = ALPHABET[(ALPHABET_SIZE + (input - ALPHABET[0]) + left.get()->getValue() - middle.get()->getValue()) % ALPHABET_SIZE];
    return left.get()->getNext(transformedInput);
}

char Enigma::reflect(char input)
{
    char transformedInput = ALPHABET[(ALPHABET_SIZE + input - left.get()->getValue()) % ALPHABET_SIZE];
    return reflector.get()->reflect(transformedInput);
}

char Enigma::leftReverse(char input)
{
    char transformedInput = ALPHABET[(ALPHABET_SIZE + (input - ALPHABET[0]) + (left.get()->getValue() - ALPHABET[0])) % ALPHABET_SIZE];
    return left.get()->getPrev(transformedInput);
}

char Enigma::middleReverse(char input)
{
    char transformedInput = ALPHABET[(ALPHABET_SIZE + (input - ALPHABET[0]) - (left.get()->getValue() - middle.get()->getValue())) % ALPHABET_SIZE];
    return middle.get()->getPrev(transformedInput);
}

char Enigma::rightReverse(char input)
{
    char transformedInput = ALPHABET[(ALPHABET_SIZE + (input - ALPHABET[0]) - (middle.get()->getValue() - right.get()->getValue())) % ALPHABET_SIZE];
    return right.get()->getPrev(transformedInput);
}

char Enigma::finalizeReverse(char input)
{
    return ALPHABET[(ALPHABET_SIZE + input - right.get()->getValue()) % ALPHABET_SIZE];
}

char Enigma::decode(char input)
{

    return input;
}
