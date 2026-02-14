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
  
  auto p = a.begin();
  auto q = b.rbegin();
  while(p != a.end() && q != b.end()) {
  for(auto p = a.begin(); p != a.end(); ) {
    if(b.contains(*p)) {
        cout << "Alice picked matching card " << *p;
        card temp = *p;
        p++;
        a.remove(temp);
        b.remove(temp);
        break;
    }
    else {
        ++p;
    }
}
  for(q = b.begin(); q != b.end(); ) {
      if(a.contains(*q)) {
        cout << "Bob picked matching card " << *q;
        card temp = *q;
        q++;
        a.remove(temp);
        b.remove(temp);
        break;
    }
    else {
      ++q;
    }
  }
}
  return 0;
}
