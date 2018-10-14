#include "reflector.h"

Reflector::Reflector(std::istream& stream)
{
    for (unsigned i = 0; i < PAIR_NUMBER; ++i) {
        stream.get(set[i].first);
        stream.get(set[i].second);
    }
}

char Reflector::reflect(char input) const {
    for (unsigned i = 0; i < PAIR_NUMBER; ++i) {
        if (set[i].first == input) {
            return set[i].second;
        } else if (set[i].second == input){
            return set[i].first;
        }
    }
    return -1;
}
