// card_list.h
// Author: Yifei Zheng
// All class declarations related to defining a BST that represents a player's hand

#ifndef CARD_LIST_H
#define CARD_LIST_H

#include <iostream>
#include "card.h"
using namespace std;

class BST {
struct Node {
	card info;
	Node *left, *right, * parent;
	// useful constructor:
    Node(card c) : info(c), left(0), right(0), parent(0) { }
};
 public:
 
    // ctor, dtor, insert and one print method already done in intbst.cpp:
    BST();                   // constructor
    ~BST();                  // destructor
    //bool insert(int value);     // insert value; return false if duplicate
    //void printPreOrder() const; // prints tree data pre-order to cout

    // 8 METHODS YOU MUST IMPLEMENT in intbst.cpp:
    //void printInOrder() const;       // print tree data in-order to cout
    //void printPostOrder() const;     // print tree data post-order to cout
    //int sum() const;                 // sum of all values
    //int count() const;               // count of values
    //bool contains(int value) const;  // true if value is in tree

    // THESE ARE HARDER! DO THESE LAST
    int getPredecessor(card value) const;       // returns the predecessor value of the given value or 0 if there is none
    int getSuccessor(card value) const;         // returns the successor value of the given value or 0 if there is none
    bool remove(card value);                    // deletes the Node containing the given value from the tree


    class iterator {
    private:
        Node* it;
        BST* he;
    public:
        iterator(Node* node, BST* bst);
        iterator operator++(int);
        iterator& operator++();
        iterator& operator--();      
        iterator operator--(int);
        card& operator*() ;
        bool operator!=(const iterator &other) const ;
        
        friend class BST;
    };
    iterator begin();
    iterator end();
    iterator rbegin();
    iterator rend();

    void print(card c);
    bool insert(card c);
    bool contains(card c) const;

 private:

    // just one instance variable (pointer to root node):
    Node *root;

    // recursive utility functions for use by public methods above
    Node* getNodeFor(card value, Node* n) const; // IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
    void clear(Node *n); // for destructor
    bool insert(card value, Node *n); // note overloading names for simplicity
    //void printPreOrder(Node *n) const;
    //void printInOrder(Node *n) const;
    //void printPostOrder(Node *n) const;
    //int sum(Node *n) const;
    //int count(Node *n) const;

    // these should be used by getPredecessor and getSuccessor, and ONE of them should be used by remove
    Node* getSuccessorNode(card value) const;   // returns the Node containing the successor of the given value
    Node* getPredecessorNode(card value) const; // returns the Node containing the predecessor of the given value 
};





#endif
