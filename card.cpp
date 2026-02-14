// card.cpp
// Authors: Isabella Cerrrilos, Haasini Yakkala 
// Implementation of the classes defined in card.h
#include "card.h"
#include <iostream>
using namespace std;

Card::Card(char s, string val) : suit(s), value(val) {}

char Card::getSuit() const {
    return suit;
}

string Card::getValue() const {
    return value;
}

int Card::getSuitNum(char c) const {
    if (c == 'c') return 0;
    else if (c == 'd') return 1;
    else if (c == 's') return 2;
    else if (c == 'h') return 3;
    return -1;
}

int Card::getLetterNum(string val) const {
    if (val == "a") return 1;
    if (val == "j") return 11;
    if (val == "q") return 12;
    if (val == "k") return 13;
    if (val == "10") return 10;

    if (val.length() == 1 && val[0] >= '2' && val[0] <= '9') {
        return val[0] - '0';
    }

    return -1; 
}

bool operator==(const Card& lhs, const Card& rhs) {
    return lhs.getSuit() == rhs.getSuit() &&
           lhs.getValue() == rhs.getValue();
}

bool operator<(const Card& lhs, const Card& rhs) {
    int lhsSuit = lhs.getSuitNum(lhs.getSuit());
    int rhsSuit = rhs.getSuitNum(rhs.getSuit());

    if (lhsSuit != rhsSuit)
        return lhsSuit < rhsSuit;

    return lhs.getLetterNum(lhs.getValue()) <
           rhs.getLetterNum(rhs.getValue());
}

bool operator>(const Card& lhs, const Card& rhs) {
    return rhs < lhs; 
}

ostream& operator<<(ostream& out, const Card& c) {
    out << c.getSuit() << " " << c.getValue();
    return out;
}