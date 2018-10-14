#include <iostream>
#include "enigma.h"

int main()
{
    Enigma enigma;
    std::string msg("DOZSWBRQJC");
    std::cout << enigma.encode(msg);
    return 0;
}
