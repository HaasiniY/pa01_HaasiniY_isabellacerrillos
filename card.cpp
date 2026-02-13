// card.cpp
// Authors: Isabella Cerrrilos, Haasini Yakkala 
// Implementation of the classes defined in card.h
#include "card.h"
#include <iostream>
using namespace std;

Card::Card(char s, char val) : suit(s), value(val){}

char Card::getSuit() const{
    return suit;
}

char Card::getValue() const{
    return value;
}

bool operator==(const Card& lhs, const Card& rhs){

}
bool operator<(const Card& lhs, const Card& rhs){

}
bool operator>(const Card& lhs, const Card& rhs){

}
ostream& operator<<(ostream& out, const Card& c){

    return out;
}