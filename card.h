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
    bool operator==(const Card& other);
    bool operator<(const Card& other);
    bool operator>(const Card& other);
    friend ostream& operator<<(ostream& out, const Card& c);

    private:
    char suit;
    char value; 
    
    
}
#endif
