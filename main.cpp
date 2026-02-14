// This file should implement the game using a custom implementation of a BST (based on your earlier BST implementation)
#include <iostream>
#include <fstream>
#include <string>
#include "card.h"
#include "card_list.h"
//Do not include set in this file

using namespace std;

int main(int argv, char** argc){
  
  BST a;
  BST b;
  if(argv < 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  if (cardFile1.fail() || cardFile2.fail() ){
    cout << "Could not open file " << argc[2];
    return 1;
  }

  //Read each file
  while (getline (cardFile1, line) && (line.length() > 0)){
    a.insert(card(line[0], line[2]));
  }
  cardFile1.close();


  while (getline (cardFile2, line) && (line.length() > 0)){
    b.insert(card(line[0], line[2]));
  }
  cardFile2.close();
  
  bool found = true;

while(found) {
    found = false;

    
    for(auto p = a.begin(); p != a.end(); ) {
        if(b.contains(*p)) {
            cout << "Alice picked matching card " << *p << endl;
            card temp = *p;
            p++;
            a.remove(temp);
            b.remove(temp);
            found = true;
            break;
        }
        else {
            ++p;
        }
    }

    
    for(auto q = b.begin(); q != b.end(); ) {
        if(a.contains(*q)) {
            cout << "Bob picked matching card " << *q << endl;
            card temp = *q;
            q++;
            a.remove(temp);
            b.remove(temp);
            found = true;
            break;
        }
        else {
            ++q;
        }
    }
}
cout << "Alice's cards:\n";
for(auto it = a.begin(); it != a.end(); ++it) {
    cout << *it;
}

cout << "Bob's cards:\n";
for(auto it = b.begin(); it != b.end(); ++it) {
    cout << *it;
}

  return 0;
}
