// This file should implement the game using the std::set container class
// Do not include card_list.h in this file
#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <set>
#include "card.h"

using namespace std;

int main(int argv, char** argc){
  if(argv < 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);

  set<Card>alice_hand;
  set<Card>bob_hand;

  string line;
  char suit;
  string value;

  

  if (cardFile1.fail() || cardFile2.fail() ){
    cout << "Could not open file " << argc[2];
    return 1;
  }

  while (getline (cardFile1, line) && (line.length() > 0)){
    suit = line[0];
    value = line[2];
    if(line.length()>3){
      value+=line[3];
    }
    alice_hand.insert(Card(suit, value));
  }
  cardFile1.close();


  while (getline (cardFile2, line) && (line.length() > 0)){
    suit = line[0];
    value = line[2];
    if(line.length()>3){
      value+=line[3];
    }
    bob_hand.insert(Card(suit, value));
  }
  cardFile2.close();
bool cardsInCommon = true;

while (cardsInCommon) {
    cardsInCommon = false;

    for (auto it = alice_hand.begin(); it != alice_hand.end(); ++it) {
        Card c = *it;
        if (bob_hand.count(c)) {
            cout << "Alice picked matching card " << c << endl;
            alice_hand.erase(c);
            bob_hand.erase(c);
            cardsInCommon = true;
            break;  
        }
    }

    if (!cardsInCommon) break; 

    cardsInCommon = false;

    for (auto it = bob_hand.rbegin(); it != bob_hand.rend(); ++it) {
        Card c = *it;
        if (alice_hand.count(c)) {
            cout << "Bob picked matching card " << c << endl;
            alice_hand.erase(c);
            bob_hand.erase(c);
            cardsInCommon = true;
            break;  
        }
      
    }
  
  }
cout << "Alice's cards:" << endl;
  for (Card c : alice_hand){
    cout << c << endl;
  }
  cout << "Bob's cards:" << endl;
  for (Card c : bob_hand){
    cout << c << endl;
  }
return 0;

}


 /* string aliceMatch = "Alice picked a matching card ";
  string bobMatch = "Bob picked a matching card ";
  bool aliceTurn = true;
  bool bobTurn = false;
  while(true){
  while (aliceTurn){
    for(auto x = alice_hand.begin(); x != alice_hand.end(); ++x){
       for(auto it = bob_hand.rbegin(); it != bob_hand.rend(); ++it){
        if(*x==*it){
          if (aliceTurn){
          cout << aliceMatch << *x;
          alice_hand.erase(*x);
          aliceTurn = false;
          bobTurn = true; 
        }
      }
    }
    } 
  }
  while (bobTurn){
    for(auto x = bob_hand.rbegin(); x != bob_hand.rend(); ++x){
       for(auto it = alice_hand.begin(); it != alice_hand.end(); ++it){
        if(*x==*it){
          if (bobTurn){
          cout << bobMatch << *x;
          bob_hand.erase(*x);
          aliceTurn = true;
          bobTurn = false; 
        }
      }
    }
    } 
  }
  if(!aliceTurn && !bobTurn){
    break;
  }
  }
  cout << "Alice's cards" << endl;
  for (Card c : alice_hand){
    cout << c << endl;
  }
  cout << "Bob's cards" << endl;
  for (Card c : bob_hand){
    cout << c << endl;
  }
  return 0;
}
*/