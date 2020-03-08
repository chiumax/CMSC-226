/*
invmenu.cpp
CMSC 226, CRN 35481, Dr. Kuijt
Max C.

Inventory Module
*/

#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  int userInput;
  bool exitMenu = false;

  // Menu exits on user input "5"
  while (exitMenu == false) {
    cout << "Serendipity Booksellers" << endl
         << "Inventory Database" << endl
         << "1. Look Up a Book" << endl
         << "2. Add a Book" << endl
         << "3. Edit a Book's Record" << endl
         << "4. Delete a Book" << endl
         << "5. Return to the Main Menu" << endl
         << endl
         << "Enter Your Choice: ";
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
      break;
    case 5:
      // EXIT HERE
      cout << "You selected item 5" << endl;
      exitMenu = true;
      break;
    default:
      cout << "Please enter a number in the range 1-5" << endl;
      break;
    }
  }
  cout << "Menu exited" << endl;
}
