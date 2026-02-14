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

int Card::getSuitNum(char c) const{
    if(c == 'c'){
        return 0;
    }
    else if(c == 's'){
        return 1;
    }
    else if(c == 's'){
        return 2;
    }
    else if(c == 'h'){
        return 3;
    }
    else{
        return -1;
    }
}

int Card::getLetterNum(char val) const{
    if(val >= 2 && val <=9){
        return val - '0';
    }
    else if(val == 'a'){
        return 1;
    }
    else if(val == 'j'){
        return 10;
    }
    else if(val == 'q'){
        return 11;
    }
    else if(val == 'k'){
        return 12;
    }
    return -1;
}


bool operator==(const Card& lhs, const Card& rhs){
    if((lhs.getSuitNum(lhs.getSuit()) != rhs.getSuitNum(rhs.getSuit())) 
    || (lhs.getValue() != rhs.getValue())){
        return false;
    }
    return true;
}
bool operator<(const Card& lhs, const Card& rhs){
    if(lhs.getSuitNum(lhs.getSuit()) < rhs.getSuitNum(rhs.getSuit())) {
        return true;
    }
    if(lhs.getSuitNum(lhs.getSuit()) == rhs.getSuitNum(rhs.getSuit())) {
        if(lhs.getLetterNum() < rhs.getLetterNum()){
            return true;
        }
    }
    return false;
}
bool operator>(const Card& lhs, const Card& rhs){
    if(lhs.getSuitNum(lhs.getSuit()) > rhs.getSuitNum(rhs.getSuit())) {
        return true;
    }
    if(lhs.getSuitNum(lhs.getSuit()) == rhs.getSuitNum(rhs.getSuit())) {
        if(lhs.getLetterNum() > rhs.getLetterNum()){
            return true;
        }
    }
    return false;
}
ostream& operator<<(ostream& out, const Card& c){
    out<< c.getSuit() << " "<< c.getValue() << endl;
    return out;
}