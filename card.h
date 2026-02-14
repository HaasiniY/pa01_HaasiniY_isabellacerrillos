// card.h
// Author: Isabella Cerrillos, Haasini Yakkala
// All class declarations related to defining a single card go here

#ifndef CARD_H
#define CARD_H

#include <iostream>
using namespace std; 

class Card{
    public: 
    Card(char s, char val );

    char getSuit() const;
    char getValue() const;
    int getSuitNum(char c) const;
    int getLetterNum(char val) const;

    private:
    char suit;
    char value;   
    
};
ostream& operator<<(ostream& out, const Card& c);
bool operator==(const Card& lhs, const Card& rhs);
bool operator<(const Card& lhs, const Card& rhs);
bool operator>(const Card& lhs, const Card& rhs);
#endif
