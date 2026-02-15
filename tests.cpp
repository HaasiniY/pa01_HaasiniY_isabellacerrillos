#include "card_list.h"
#include "card.h"
#include <iostream>
using namespace std;

void testInsert();
void testContains();
void testGame();
void testInsert();
void testRemove();
void testIterator();
void testPrintInOrder();

int main() {
    cout << "\n========Tests for insert()========\n";
    testInsert();

    cout << "\n========Tests for contains()========\n";
    testContains();

    cout << "\n========Tests for remove()========\n";
    testRemove();

    cout << "\n========Tests for printInOrder()========\n";
    testPrintInOrder();

    cout << "\n========Tests for iterator========\n";
    testIterator();

    cout << "\n========Tests for playGame========\n";
    testGame();

    return 0;
}

void testInsert() {
    CardBST bst1;
    bst1.insert(Card('h', "10"));
    cout <<"\nbst1 (empty) after inserting h 10:\n"; 
    bst1.printInOrder();

    bst1.insert(Card('s', "5"));
    cout <<"bst1 after inserting s 5:\n"; 
    bst1.printInOrder();

    CardBST bst2;
    bst2.insert(Card('h', "10"));
    bst2.insert(Card('c', "3"));
    bst2.insert(Card('d', "12"));
    bst2.insert(Card('s', "7"));
    cout <<"\nbst2 (empty) after inserting h 10, c 3, d 12, s 7:\n"; 
    bst2.printInOrder();

    bst2.insert(Card('h', "10")); 
    cout <<"bst2  after inserting duplicate h 10:\n"; 
    bst2.printInOrder();

    CardBST bst3;
    bst3.insert(Card('s', "5"));
    bst3.insert(Card('s', "4"));
    bst3.insert(Card('s', "3"));
    bst3.insert(Card('s', "2"));
    cout <<"\nbst 3 (empty) after inserting s 5, s 4, s 3, s 2:\n"; 
    bst3.printInOrder();
}
void testContains() {
    CardBST bst1;

    cout << "\nEmpty tree bst1 contains h 10? " << (bst1.contains(Card('h', "10")) ? "true" : "false") << endl;

    bst1.insert(Card('s', "8"));
    cout << "\nEmpty tree bst1 after adding s 8:\n";
    bst1.printInOrder();
    cout << "Single node tree bst1 contains s 8? " << (bst1.contains(Card('s', "8")) ? "true" : "false") << endl;
    cout << "Single node tree bst1 contains s 9? " << (bst1.contains(Card('s', "9")) ? "true" : "false") << endl;

    bst1.insert(Card('d', "3"));
    bst1.insert(Card('c', "12"));
    cout << "\nbst1 after adding d 3, c 12:\n";
    bst1.printInOrder();
    cout << "Multiple node tree contains d 3? " << (bst1.contains(Card('d', "3")) ? "true" : "false") << endl;

    cout << "Multiple node tree contains h q? "<< (bst1.contains(Card('h', "q")) ? "true" : "false") << endl;
}
void testRemove() {
    CardBST empty; 
    cout <<"\nRemoving c 4 from empty tree:\n";
    empty.remove(Card('c',"4"));
    cout << (empty.remove(Card('c', "4")) ? "Removed" : "Not Found") << endl;

    CardBST bst;
    bst.insert(Card('s', "3"));
    bst.insert(Card('d', "5"));  
    bst.insert(Card('h', "7"));   
    bst.insert(Card('c', "a"));  
    bst.insert(Card('d', "10"));  
    bst.insert(Card('s', "k"));  
    bst.insert(Card('h', "q"));
    cout << "\nInitial bst:\n";
    bst.printInOrder();

    cout << "\nRemoving leaf node c a:\n";
    cout << (bst.remove(Card('c', "a")) ? "Removed" : "Not Found") << endl;
    bst.printInOrder();
    cout << "\nRemoving root node s 3 \n";
    cout << (bst.remove(Card('s', "3")) ? "Removed" : "Not Found") << endl;
    bst.printInOrder();
    cout << "\nRemoving node d 5 with one child:\n";
    cout << (bst.remove(Card('d', "5")) ? "Removed" : "Not Found") << endl;
    bst.printInOrder();
    cout << "\nRemoving nonexistent node s 9:\n";
    cout << (bst.remove(Card('s', "9")) ? "Removed" : "Not Found") << endl;
    bst.printInOrder();

    cout << "\nRemoving remaining nodes:\n";
    bst.remove(Card('d', "10"));
    bst.remove(Card('s', "k"));
    bst.remove(Card('h', "7"));
    bst.remove(Card('h', "q"));
    cout << "Final empty tree:\n";
    bst.printInOrder();
}

void testPrintInOrder(){
    cout << "\nPrinting empty tree:\n";
    CardBST bst1;
    bst1.printInOrder();

    cout << "\nPrinting single node tree:\n";
    bst1.insert(Card('h', "2"));
    bst1.printInOrder();

    cout << "\nPrinting multiple node tree:\n";
    bst1.insert(Card('h', "5"));
    bst1.insert(Card('h', "3"));
    bst1.printInOrder();

    cout << "\nPrinting multiple node tree after removing h 3:\n";
    bst1.remove(Card('h', "3"));
    bst1.printInOrder();

     cout << "\nPrinting larger tree:\n";
    CardBST bst2;
    bst2.insert(Card('s', "2"));
    bst2.insert(Card('s', "3"));
    bst2.insert(Card('s', "4"));
    bst2.insert(Card('s', "5"));
    bst2.insert(Card('s', "6"));
    bst2.printInOrder();
}

void testIterator() {
    cout<< "\nEmpty tree tests:\n";
    CardBST bst1;
    if (bst1.begin() == bst1.end()){
        cout << "begin() same as end() in empty tree\n";
    } else {
        cout << "begin() NOT same as end() in empty tree\n";
    }
    if (bst1.rbegin() == bst1.rend()){
        cout << "rbegin() same as rend() in empty tree\n";
    } else {
        cout << "rbegin() NOT same as rend() in empty tree\n";
    }

    cout<< "\nSingle node tree tests:\n";
    bst1.insert(Card('h', "k"));
    auto it = bst1.begin();
    cout << "Single node: " << *it << endl;
    ++it;
    if (it == bst1.end()){
        cout << "Single increment reaches end\n";
    } else { 
        cout << "Single increment does NOT reach end\n";
    }
    auto it2 = bst1.begin(); 
    --it2;
    if (it2 == bst1.rend()){
        cout << "Single decrement reaches rend\n";
    } else { 
        cout << "Single decrement does NOT reach rend\n";
    }

    cout<< "\nMultiple node tree tests:\n";
    CardBST bst2;
    bst2.insert(Card('h', "10"));
    bst2.insert(Card('d', "5"));
    bst2.insert(Card('s', "a"));
    cout << "Printed tree:\n";
    bst2.printInOrder();
    cout << "Forward traversal:\n";
    for (auto i = bst2.begin(); i != bst2.end(); ++i)
        cout << *i << endl;

    cout << "Reverse traversal:\n";
    for (auto i = bst2.rbegin(); i != bst2.rend(); --i)
        cout << *i << endl;

    cout << "\nIncrementation safety tests:\n";
    auto it3 = bst2.begin();
    while (it3 != bst2.end()) {
    ++it3;
    }
    cout << (it3 == bst2.end() ? "Reached end after full iteration" : "Did not reach end after full iteration") << endl;

    cout << "Incrementing past end?:\n";
    ++it3;
    cout << (it3 == bst2.end() ? "Safe increment past end" : "Error incrementing past end") << endl;

    cout << "\nDecrementation safety tests:\n";
    auto rit = bst2.rbegin();
    while (rit != bst2.rend()) {
    --rit;
    }
    cout << (rit == bst2.rend() ? "Reached rend after full decremenation" : "Did not reach end after full decrementation") << endl;

    cout << "Decrementing past rend?:\n";
    --rit;
    cout << (rit == bst2.rend() ? "Safe increment past rend" : "Error incrementing past rend") << endl;

    cout << "\nIterator comparison tests:\n";

    auto ita = bst2.begin();
    auto itb = bst2.begin();
    auto itc = bst2.begin();
    ++itc;

    cout << (ita == itb ? "ita == itb works\n" : "ita == itb failed\n");
    cout << (ita != itc ? "ita != itc works\n" : "ita != itc failed\n");
    // Move both forward and compare again
    ++ita;
    ++itb;

    cout << (ita == itb ? "After increment, ita == itb works\n" 
                        : "After increment, ita == itb failed\n");

}

void testGame() {

    cout << "\nTesting for common cards\n";

    CardBST alice1;
    CardBST bob1;

    alice1.insert(Card('s',"5"));
    alice1.insert(Card('h',"9"));
    alice1.insert(Card('d',"k"));

    bob1.insert(Card('c',"2"));
    bob1.insert(Card('h',"9"));   
    bob1.insert(Card('d',"k"));   

    cout << "\nAlice's initial hand:\n";
    alice1.printInOrder();
    cout << "Bob's initial hand:\n";
    bob1.printInOrder();

    cout << "\n--START GAME--\n";
    playGame(alice1, bob1);
    cout << "--END GAME--\n";

    cout << "\nTesting for one empty hand:\n";
    CardBST alice2;
    CardBST bob2;

    alice2.insert(Card('s',"3"));
    alice2.insert(Card('h',"7"));

    cout << "\nAlice's initial hand:\n";
    alice2.printInOrder();
    cout << "Bob's intial empty hand':\n";
    bob2.printInOrder();

    cout << "\n--START GAME--\n";
    playGame(alice2, bob2);
    cout << "--END GAME--\n";

    cout << "\nTesting for no common cards:\n";

    CardBST alice3;
    CardBST bob3;

    alice3.insert(Card('s',"4"));
    alice3.insert(Card('h',"6"));
    alice3.insert(Card('d',"8"));

    bob3.insert(Card('c',"2"));
    bob3.insert(Card('c',"10"));
    bob3.insert(Card('c',"q"));

    cout << "\nAlice's initial hand:\n";
    alice3.printInOrder();
    cout << "Bob's initial hand:\n";
    bob3.printInOrder();

    cout << "\n--START GAME--\n";
    playGame(alice3, bob3);
    cout << "--END GAME--\n";
}
