// card_list.cpp
// Author: Isabella Cerrillos, Haasini Yakkala
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

CardBST::Node* CardBST::getMin(Node* n) const{
    if(!n){
        return nullptr;
    }
    while(n->left){
        n = n->left;
    }
    return n;
}

CardBST::Node* CardBST::getMax(Node* n) const{
    if(!n){
        return nullptr;
    }
    while(n->right){
        n = n->right;
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

CardBST::Node* CardBST::getSuccessorNode(Node* r) const{
    if(!r) return nullptr;
    Node* result = nullptr;
    if(r->right){
        result = getMin(r->right);
    }else{
        Node* p = r->parent;
        while(p && r == p->right){
            r = p;
            p = p->parent;
        }
        result = p;
    }
    return result;
}
CardBST::Node* CardBST::getPredecessorNode(Node* r)const{
    if(!r) return nullptr;
    Node* result = nullptr;
    if(r->left){
        result = getMax(r->left);
    }else{
        Node* p = r->parent;
        while(p && r == p->left){
            r = p;
            p = p->parent;
        }
        result = p;
    }
    return result;
}
bool CardBST::remove(Card c){
   Node *curr = getNodeFor(c,root);
   if (!curr) return false;
   if (curr->left && curr->right){
    Node* successor = getSuccessorNode(curr);
    curr->card = successor->card;
    curr = successor;
   }
   Node* child = nullptr;
   if (curr->left){
    child = curr->left;
   } else {
    child = curr->right;
   }
   if(child){
    child->parent = curr->parent;
   }
   if(!curr->parent){
    root = child;
   } else if (curr == curr->parent->left){
    curr->parent->left = child;
   } else {
    curr->parent->right = child;
   }
   delete curr;
   return true;
}


Card& CardBST::iterator::operator*(){
    return curr->card;
}
CardBST::iterator CardBST::begin(){
    return iterator(getMin(root), this);
}
CardBST::iterator CardBST::end(){
    return iterator(nullptr, this);
}
CardBST::iterator CardBST::rbegin(){
    return iterator(getMax(root), this);
}
CardBST::iterator CardBST::rend(){
    return iterator(nullptr, this);
}
CardBST::iterator& CardBST::iterator::operator++(){
    curr = rtree->getSuccessorNode(curr);
    return *this;
}
CardBST::iterator& CardBST::iterator::operator--(){
    curr = rtree->getPredecessorNode(curr);
    return *this;
}
bool CardBST::iterator::operator!=(const iterator& other) const{
    return curr != other.curr;
}
bool CardBST::iterator::operator==(const iterator& other) const{
    return curr == other.curr;
}

void playGame(CardBST& alice, CardBST& bob){
    bool common = true;

  while (common) {
    common = false;

    for (auto it = alice.begin(); it != alice.end(); ++it) {
      if (bob.contains(*it)) {
        Card c = *it;
        cout << "Alice picked matching card " << c << endl;
        alice.remove(c);
        bob.remove(c);
        common = true;
        break;  
      }
    }
    if (!common) break; 

    common = false;

    for (auto it = bob.rbegin(); it != bob.rend(); --it) {
      Card c = *it;
      if (alice.contains(*it)) {
        Card c = *it;
        cout << "Bob picked matching card " << c << endl;
        alice.remove(c);
        bob.remove(c);
        common = true;
        break;  
      }
    }  
  }

  cout << "\nAlice's cards:" << endl;
  alice.printInOrder();
  cout << "\nBob's cards:" << endl;
  bob.printInOrder();
}

