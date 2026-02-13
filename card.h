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
    // getter and setter functions
    // operator overloading
    
    

    private:
    char suit;
    char value; 

    char getSuit() const;
    char getValue() const;
    
    
};
ostream& operator<<(ostream& out, const Card& c);
bool operator==(const Card& lhs, const Card& rhs);
bool operator<(const Card& lhs, const Card& rhs);
bool operator>(const Card& lhs, const Card& rhs);
#endif
