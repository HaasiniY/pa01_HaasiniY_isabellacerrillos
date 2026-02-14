// card.h
// Author: Isabella Cerrillos, Haasini Yakkala
// All class declarations related to defining a single card go here

#ifndef CARD_H
#define CARD_H

#include <iostream>
using namespace std; 

class Card{
    public: 
    Card(char s, string val );

    char getSuit() const;
    string getValue() const;
    int getSuitNum(char c) const;
    int getLetterNum(string val) const;

    private:
    char suit;
    string value;   
    
};
ostream& operator<<(ostream& out, const Card& c);
bool operator==(const Card& lhs, const Card& rhs);
bool operator<(const Card& lhs, const Card& rhs);
bool operator>(const Card& lhs, const Card& rhs);
#endif


