#include <iostream>
#include <cassert>
#include <cstring>
#include <string>
#include "card_list.h"
#include "card.h"
using namespace std;





    void testInsert() {

        BST t1;
        t1.insert(card('c',"3"));
        assert(t1.contains(card('c',"3")));

        BST t2;
        t2.insert(card('h',"a"));
        assert(t2.contains(card('h',"a")));

        BST t3;
        t3.insert(card('c',"3"));
        t3.insert(card('c',"5"));
        t3.insert(card('c',"1"));
        assert(t3.contains(card('c',"5")));

        BST t4;
        t4.insert(card('s',"7"));
        t4.insert(card('s',"7"));  
        int count = 0;
        for(auto it = t4.begin(); it != t4.end(); ++it)
            count++;
        assert(count == 1);

        BST t5;
        for(int i=2;i<=9;i++)
            t5.insert(card('h', string(1, '0' + i)));
        assert(t5.contains(card('h',"5")));
    }

    void testContains() {

    
        BST t1;
        assert(!t1.contains(card('c',"3")));

        
        BST t2;
        t2.insert(card('c',"3"));
        assert(t2.contains(card('c',"3")));

        
        assert(!t2.contains(card('c',"4")));

        
        BST t3;
        t3.insert(card('h',"a"));
        t3.insert(card('s',"5"));
        t3.insert(card('d',"j"));
        assert(t3.contains(card('s',"5")));

        
        assert(!t3.contains(card('c',"2")));
    }

    void testRemove() {

    
        BST t1;
        t1.remove(card('c',"3"));   

        
        BST t2;
        t2.insert(card('c',"3"));
        t2.remove(card('c',"3"));
        assert(!t2.contains(card('c',"3")));

        
        BST t3;
        t3.insert(card('c',"3"));
        t3.insert(card('c',"5"));
        t3.remove(card('c',"5"));
        assert(!t3.contains(card('c',"5")));

        
        BST t4;
        t4.insert(card('c',"3"));
        t4.insert(card('c',"5"));
        t4.insert(card('c',"4"));
        t4.remove(card('c',"5"));
        assert(!t4.contains(card('c',"5")));

        
        t4.remove(card('s',"9"));
    }



    void testIterator() {

    BST t1;
    assert(t1.begin() == t1.end());
    assert(t1.rbegin() == t1.rend());

    BST t2;
    t2.insert(card('c',"3"));
    auto it = t2.begin();
    if(it != t2.end()) { 
        assert(*it == card('c',"3"));
    }
    ++it;
    assert(it == t2.end());

    BST t3;
    t3.insert(card('c',"3"));
    t3.insert(card('c',"5"));
    t3.insert(card('c',"1"));

    auto i = t3.begin();
    if(i != t3.end()) assert(*i == card('c',"1"));
    ++i;
    if(i != t3.end()) assert(*i == card('c',"3"));
    ++i;
    if(i != t3.end()) assert(*i == card('c',"5"));

    auto r = t3.rbegin();
    if(r != t3.rend()) assert(*r == card('c',"5"));
    ++r;
    if(r != t3.rend()) assert(*r == card('c',"3"));

    auto a = t3.begin();
    auto b = t3.begin();
    assert(a == b);
    ++b;
    assert(a != b);
}

    void testPlayGame() {
 
        BST a;
        BST b;
        a.insert(card('c',"3"));
        b.insert(card('c',"3"));
        playGame(a,b);
        assert(!a.contains(card('c',"3")));
        assert(!b.contains(card('c',"3")));

        BST a2;
        BST b2;
        b2.insert(card('c',"3"));
        playGame(a2,b2);

        BST a3;
        BST b3;
        a3.insert(card('c',"3"));
        b3.insert(card('d',"4"));
        playGame(a3,b3);
        assert(a3.contains(card('c',"3")));
        assert(b3.contains(card('d',"4")));
    }

int main() {
    testInsert();
    testContains();
    testRemove();
    testIterator();
    testPlayGame();
    return 0;
}