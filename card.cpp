// card.cpp
// Author: Yifei Zheng
// Implementation of the classes defined in card.h

#include "card.h"

card::card(char suit, char num) {
    switch(suit) {
        case 'h':
            this->suit = hearts;
            break;
        case 's':
            this->suit = spades;
            break;
        case 'c':
            this->suit = clubs;
            break;
        case 'd':
            this->suit = diamonds;
            break;
    }
    switch(num) {
        case 'a':
            this->number = 1;
            break;
        case 'j':
            this->number = 11;
            break;
        case 'q':
            this->number = 12;
            break;
        case 'k':
            this->number = 13;
            break;

        default:
            this->number = num - '0';
    }
}


card::suits card::getSuit() {
    return suit;
}
int card::getNum() {
    return number;

}

bool operator==(const card &a, const card &other) {
    return a.suit == other.suit && a.number == other.number;
}



bool operator<(const card &a, const card &other) {
    if (a.suit != other.suit)
        return a.suit < other.suit;

    return a.number < other.number;
}



bool operator>(const card &a, const card &other) {
    return !(a < other);
}



ostream& operator<<(ostream& os, const card &other) {
    switch(other.suit) {
        case card ::suits :: hearts:
            os << 'h' ;
            break;
        case card ::suits :: spades:
            os << 's' ;
            break;
        case card ::suits :: clubs:
            os << 'c' ;
            break;
        case card ::suits :: diamonds:
            os << 'd' ;
            break;
    }

    os << ' ';

        switch(other.number) {
        case 1:
            os << 'a' ;
            break;
        case 11:
            os << 'j' ;
            break;
        case 12:
            os << 'q' ;
            break;
        case 13:
            os << 'k' ;
            break;

        default:
            os << other.number;
    }
    os << endl;
    return os;
}
