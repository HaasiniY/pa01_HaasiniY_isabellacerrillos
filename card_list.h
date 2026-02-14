// card_list.h
// Author: Your name
// All class declarations related to defining a BST that represents a player's hand

#ifndef CARD_LIST_H
#define CARD_LIST_H

#include <iostream>
using namespace std;

class CardBST{
    public:
        CardBST();
        ~CardBST();

        void printInOrder() const;
        void printReverseOrder() const;

        class iterator;

        iterator begin();
        iterator end();
        iterator rbegin();
        iterator rend();
        void erase(Card C);

    private:

        struct Node{
            
        }




}

#endif
