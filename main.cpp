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
    a.insert(card(line[0], line.substr(2)));
  }
  cardFile1.close();


  while (getline (cardFile2, line) && (line.length() > 0)){
    b.insert(card(line[0], line.substr(2)));
  }
  cardFile2.close();
  
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

  return 0;
}
