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

// print tree data pre-order
/*void BST::printPreOrder() const {
    if (root) {
        printPreOrder(root);
    }
}

// recursive helper for printPreOrder()
void BST::printPreOrder(Node *n) const {
    if(!n) return;

    cout << n->info;

    if (n->left) {
        cout << " ";
        printPreOrder(n->left);
    }
    if (n->right) {
        cout << " ";
        printPreOrder(n->right);
    }
}

// print tree data in-order, with helper
void BST::printInOrder() const {
    printInOrder(root);
}
void BST::printInOrder(Node *n) const {
    if (!n) {
        return;
    }
    // Print left subtree
    if (n->left) {
        printInOrder(n->left);
        cout << " ";
    }
    
    // Print current node
    cout << n->info;
    
    // Print right subtree
    if (n->right) {
        cout << " ";
        printInOrder(n->right);
    }
}

// prints tree data post-order, with helper
void BST::printPostOrder() const {
    if(root)
    printPostOrder(root);
}

void BST::printPostOrder(Node *n) const {
    if(!n) return;
    
    // Print left subtree
    if (n->left) {
        printPostOrder(n->left);
        cout << " ";
    }
    
    // Print right subtree
    if (n->right) {
        printPostOrder(n->right);
        cout << " ";
    }
    
    // Print current node
    cout << n->info;
}*/

/*int BST::sum() const {
    return sum(root); 
}

// recursive helper for sum
int BST::sum(Node *n) const {
    if(!n) return 0;
    return n->info + sum(n->left) + sum(n->right);
}

// return count of values
int BST::count() const {
    return count(root);
}

// recursive helper for count
int BST::count(Node *n) const {
    if (!n) return 0;
    return 1 + count(n->left) + count(n->right);
}*/

// IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
// Parameters:
// int value: the value to be found
// Node* n: the node to start with (for a recursive call)
// Whenever you call this method from somewhere else, pass it
// the root node as "n"
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

void BST :: iterator :: operator--() {
    it = he->getPredecessorNode(it->info);
}






void BST :: iterator :: operator++() {
    it = he->getSuccessorNode(it->info);
}




card& BST :: iterator :: operator*() 
{
    return it->info;
}

BST::iterator::iterator(Node* node, BST* bst) : it(node), he(bst){}

BST::iterator BST::begin() {
    if(!root) return iterator(NULL, this);
    Node* curr = root;
    while(curr && curr->right) {
        curr = curr->right;
    }
    return iterator(curr, this);
}
BST::iterator BST::end() {
    return iterator(nullptr, this);
}
BST::iterator BST::rbegin() {
    if(!root) return iterator(NULL, this);
    Node* curr = root;
    while(curr && curr->left) {
        curr = curr->left;
    }
    return iterator(curr, this);
}
BST::iterator BST::rend() {
    return iterator(NULL, this);
}
bool operator!=(const BST::iterator &a, const BST::iterator &b) {
    return !(a.info == b.info);
}