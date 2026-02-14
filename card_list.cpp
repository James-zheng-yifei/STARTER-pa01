// card_list.cpp
// Author: Yifei Zheng
// Implementation of the classes defined in card_list.h

#include "card_list.h"

// intbst.cpp
// Implements class IntBST
// Yifei Zheng 1/30/2026

#include <vector>
#include <iostream>
using std::cout;
using std::vector;
using namespace std;

// constructor sets up empty tree
BST::BST() : root(nullptr){}

// destructor deletes all nodes
BST::~BST() {
    clear(root);
}

// recursive helper for destructor
void BST::clear(Node *n) {
    if(!n) return;
    clear(n->left);
    clear(n->right);
    delete n;
}

// insert value in tree; return false if duplicate
bool BST::insert(card value) {
    if (!root) {
        root = new Node(value);
        return true;
    }
    return insert(value, root);
}

// recursive helper for insert (assumes n is never 0)

bool BST::insert(card value, Node* n) {
    if (value == n->info) return false;

    if (value < n->info) {
        if (n->left)
            return insert(value, n->left);
        n->left = new Node(value);
        return true;
    } else {
        if (n->right)
            return insert(value, n->right);
        n->right = new Node(value);
        return true;
    }
}


BST::Node* BST::getNodeFor(card value, Node* n) const{
    if(!n) return nullptr;
    if(n->info == value) return n;
    if(value < n->info) return getNodeFor(value, n->left);
    else return getNodeFor(value, n->right);
}

// returns true if value is in the tree; false if not
bool BST::contains(card value) const {
    return getNodeFor(value, root) != nullptr;
}

// returns the Node containing the predecessor of the given value
BST::Node* BST::getPredecessorNode(card value) const{
    Node* curr = root;
    Node* predecessor = nullptr;

    while (curr) {
        if (value > curr->info) {
            predecessor = curr;
            curr = curr->right;
        } else if (value < curr->info) {
            curr = curr->left;
        } else {
            break;
        }
    }

    if (!curr) return nullptr;

    if (curr->left) {
        curr = curr->left;
        while (curr->right)
            curr = curr->right;
        return curr;
    }

    return predecessor;
}


// returns the predecessor value of the given value or 0 if there is none
/*card BST::getPredecessor(card value) const{
    Node* p = getPredecessorNode(value);
    return p ? p->info : 0;
}*/

// returns the Node containing the successor of the given value
BST::Node* BST::getSuccessorNode(card value) const{
    Node* curr = root;
    Node* successor = nullptr;

    while (curr) {
        if (value < curr->info) {
            successor = curr;
            curr = curr->left;
        } else if (value > curr->info) {
            curr = curr->right;
        } else {
            break;
        }
    }

    if (!curr) return nullptr;

    if (curr->right) {
        curr = curr->right;
        while (curr->left)
            curr = curr->left;
        return curr;
    }

    return successor;
}

// returns the successor value of the given value or 0 if there is none
/*card BST::getSuccessor(card value) const{
    Node* s = getSuccessorNode(value);
    return s ? s->info : 0;
}*/

// deletes the Node containing the given value from the tree
// returns true if the node exist and was deleted or false if the node does not exist
bool BST::remove(card value){
    Node* parent = nullptr;
    Node* curr = root;
    
    
    while (curr && curr->info != value) {
        parent = curr;
        if (value < curr->info)
            curr = curr->left;
        else
            curr = curr->right;
    }
    
    if (!curr) return false; 
    
    
    if (curr->left && curr->right) {
        
        Node* predParent = curr;
        Node* pred = curr->left;
        
        while (pred->right) {
            predParent = pred;
            pred = pred->right;
        }
        
        
        curr->info = pred->info;
        
        
        if (predParent == curr) {
            
            predParent->left = pred->left;
        } else {
            predParent->right = pred->left;
        }
        
        delete pred;
    }
    
    else {
        Node* child = (curr->left) ? curr->left : curr->right;
        
        if (!parent) {
            
            root = child;
        } else if (parent->left == curr) {
            parent->left = child;
        } else {
            parent->right = child;
        }
        
        delete curr;
    }
    
    return true;
    
}

BST::iterator& BST::iterator::operator--() {
    it = he->getPredecessorNode(it->info);
    return *this;
}

BST::iterator BST::iterator::operator--(int) {
    iterator temp = *this;
    --(*this);
    return temp;
}






BST::iterator BST::iterator::operator++(int) {
    iterator temp = *this;   
    ++(*this);               
    return temp;             
}

BST::iterator& BST::iterator::operator++() {
    it = he->getSuccessorNode(it->info);
    return *this;
}




card& BST :: iterator :: operator*() 
{
    return it->info;
}

BST::iterator::iterator(Node* node, BST* bst) : it(node), he(bst){}

BST::iterator BST::begin() {
    if(!root) return iterator(nullptr, this);

    Node* curr = root;
    while(curr->left) {
        curr = curr->left;
    }
    return iterator(curr, this);
}
BST::iterator BST::end() {
    return iterator(nullptr, this);
}
BST::iterator BST::rbegin() {
    if(!root) return iterator(nullptr, this);

    Node* curr = root;
    while(curr->right) {
        curr = curr->right;
    }
    return iterator(curr, this);
}
BST::iterator BST::rend() {
    return iterator(NULL, this);
}
bool  BST::iterator::operator!=(const iterator &other) const {
    return it != other.it;
}

void playGame(BST &a, BST &b) {
    bool found = true;

    while (found) {

    


    for (auto it = a.begin(); it != a.end(); ++it) {
        if (b.contains(*it)) {

            cout << "Alice picked matching card " << *it;

            b.remove(*it);
            a.remove(*it);

            found = true;
            break;
        }
    }

    if (!found) break;

    found = false;


    for (auto it = b.rbegin(); it != b.rend(); --it) {
        if (a.contains(*it)) {

            cout << "Bob picked matching card " << *it;

            a.remove(*it);
            b.remove(*it);

            found = true;
            break;
        }
    }

    if (!found) break;
}
cout << endl;
cout << "Alice's cards:\n";
for(auto it = a.begin(); it != a.end(); ++it) {
    cout << *it;
}
cout << endl;

cout << "Bob's cards:\n";
for(auto it = b.begin(); it != b.end(); ++it) {
    cout << *it;
}
}