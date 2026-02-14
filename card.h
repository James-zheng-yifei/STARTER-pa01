// card.h
// Author: Yifei Zheng
// All class declarations related to defining a single card go here

#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <vector>
using namespace std;



class card {
    public:
        enum suits {
            clubs,
            diamonds,
            spades,
            hearts,
        };
        card(char suit, string num);
        enum suits getSuit();
        int getNum();
    
        enum suits suit;
        int number;
};

bool operator==(const card &a, const card &other);
bool operator<(const card &a, const card &other) ;
bool operator>(const card &a, const card &other) ;
ostream& operator<<(ostream& os, const card &other) ;



#endif
