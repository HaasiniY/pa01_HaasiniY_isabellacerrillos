// This file should implement the game using a custom implementation of a BST (based on your earlier BST implementation)
#include <iostream>
#include <fstream>
#include <string>
#include "card.h"
#include "card_list.h"
//Do not include set in this file

using namespace std;

int main(int argv, char** argc){
  if(argv < 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }

  CardBST alice;
  CardBST bob;
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;
  char suit;
  string value;

  if (cardFile1.fail() || cardFile2.fail() ){
    cout << "Could not open file " << argc[2];
    return 1;
  }

  //Read each file
  while (getline (cardFile1, line) && (line.length() > 0)){
    suit = line[0];
    value = line[2];
    if(line.length()>3){
      value+=line[3];
    }
    alice.insert(Card(suit, value));
  }
  cardFile1.close();


  while (getline (cardFile2, line) && (line.length() > 0)){
    suit = line[0];
    value = line[2];
    if(line.length()>3){
      value+=line[3];
    }
    bob.insert(Card(suit, value));
  }
  cardFile2.close();


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

cout << "Alice's cards:" << endl;
  for (auto it = alice.begin(); it != alice.end(); ++it){
    cout << *it << endl;
  }
  cout << "Bob's cards:" << endl;
  for (auto it = bob.rbegin(); it != bob.rend(); --it){
    cout << *it << endl;
  }

  return 0;
}
