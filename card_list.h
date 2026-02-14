// card_list.h
// Author: Your name
// All class declarations related to defining a BST that represents a player's hand

#ifndef CARD_LIST_H
#define CARD_LIST_H
#include "card.h"
#include <iostream>
using namespace std;

class CardBST{
    public:
        CardBST();
        ~CardBST();

        void printInOrder() const;
        //void printReverseOrder() const;
        
        bool contains(Card c) const;
        bool remove(Card c);
    


        class iterator;

        iterator begin();
        iterator end();
        iterator rbegin();
        iterator rend();
        void insert(Card c);
    private:

        struct Node{
            Card card;
            Node* parent;
            Node* left;
            Node* right;
        
            Node(Card c, Node* p = nullptr) : card(c), parent(p){
                left = right = nullptr;
            }
        };
        Node* root;
        void printInOrder(Node* r) const;
        Node* getSuccessorNode(Node* r) const;
        Node* getPredecessorNode(Node* r) const;
        Node* getMin(Node* r) const;
        Node* getMax(Node* r) const;
        Node* getNodeFor(Card c, Node* r) const;
        void insert(Card c, Node* root);
        void clear(Node* r);        

    };

    class CardBST::iterator{
        public:
            iterator(CardBST::Node* pcurr = nullptr, CardBST* ptree = nullptr) : curr(pcurr), rtree(ptree){}

            Card operator*();
            iterator& operator++();
            iterator& operator--();
        private:
            CardBST::Node* curr;
            CardBST* rtree;
    };


#endif
