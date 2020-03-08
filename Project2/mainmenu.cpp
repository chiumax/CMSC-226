/*
mainmenu.cpp
CMSC 226, CRN 35481, Dr. Kuijt
Max C.

Main Menu Module
*/

#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  int userInput;
  bool exitMenu = false;

  // Menu exits on user input "4"
  while (exitMenu == false) {
    cout << "Serendipity Booksellers" << endl
         << "1. Cashier Module" << endl
         << "2. Inventory Database Module" << endl
         << "3. Report Module" << endl
         << "4. Exit" << endl
         << endl
         << "Enter your choice: ";

    cin >> userInput;

    switch (userInput) {
    case 1:
      cout << "You selected item 1" << endl;
      break;
    case 2:
      cout << "You selected item 2" << endl;
      break;
    case 3:
      cout << "You selected item 3" << endl;
      break;
    case 4:
      cout << "You selected item 4" << endl;
      // EXIT HERE
      exitMenu = true;
      break;
    default:
      cout << "Please enter a number in the range 1-4" << endl;
      break;
    }
  }
}
