// card.h
// Author: Isabella Cerrillos, Haasini Yakkala
// All class declarations related to defining a single card go here

#ifndef CARD_H
#define CARD_H
class Card{
    public: 
    Card(char s, char val );
    // getter and setter functions
    // operator overloading
    private:
    char suit;
    char value; 
    //c1 == c2
    bool operator==(const Card& lhs, const Card& rhs);
}
#endif
