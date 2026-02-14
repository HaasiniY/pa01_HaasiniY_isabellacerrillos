// card_list.cpp
// Author: Your name
// Implementation of the classes defined in card_list.h

#include "card_list.h"
#include <iostream>
using namespace std;

CardBST::CardBST(){
    root = nullptr;
}
CardBST::~CardBST(){
    clear(root);
    root = nullptr;
}

void CardBST::printInOrder() const{
    printInOrder(root);
}
void CardBST::printInOrder(Node* n) const{
    if(!n){
        return;
    }
    printInOrder(n->left);
    cout << n->card << endl;
    printInOrder(n->right);
}

bool CardBST::contains(Card c) const{
    Node* newNode = getNodeFor(c,root);
    if(!newNode){
        return false;
    }
    return true;
}

CardBST::Node* CardBST::getNodeFor(Card c, Node* r) const{
    if(!r){
        return nullptr;
    }
    if(c == r->card){
        return r;
    }
    if(c < r->card){
        return getNodeFor(c, r->left);
    }else{
        return getNodeFor(c, r->right);
    }
}
/*
Card CardBST::successor(Card c) const{
    
}

Card CardBST::predecessor(Card c) const{
    Card pred = predec
}
*/

CardBST::Node* CardBST::getMin(Node* n) const{
    if(!n){
        return nullptr;
    }
    while(n->left){
        n = n->left;
    }
    return n;
}

void CardBST::clear(Node* root){
    if(!root){
        return;
    }
    clear(root->left);
    clear(root->right);
    delete root;
}
void CardBST::insert(Card n){
    if(!root){
        root = new Node(n, nullptr);
        return;
    }
    insert(n, root);
}

void CardBST::insert(Card new_card, Node* n){
    if(new_card == n->card) return;
    if(new_card < n->card){
        if(!n->left){
            n->left = new Node(new_card);
            n->left->parent = n;
            return;
        } else{
            return insert(new_card, n->left);
        }
    } else{
        if(!n->right){
            n->right = new Node(new_card);
            n->right->parent = n;
            return;
        }else{
            return insert(new_card, n->right);
        }
    }
}
/*
IntBST::Node* IntBST::getPredecessorNode(int value) const{

     Node *curr = getNodeFor(value, root);

    if(!curr) return nullptr;

    if (curr->left){

        Node *r = curr->left;

        while(r->right){

            r=r->right;

        }

        return r;

    }

    Node *p = curr->parent;

    while (p && curr == p->left){

        curr = p;

        p = p->parent;

    }

    return p;

}



// returns the predecessor value of the given value or 0 if there is none

int IntBST::getPredecessor(int value) const{

   Node* predecessor = getPredecessorNode(value);

    if (!predecessor) return 0;

    return predecessor->info;

}
*/