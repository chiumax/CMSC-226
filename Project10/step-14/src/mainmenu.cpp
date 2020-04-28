/*
mainmenu.cpp
CMSC 226, CRN 35481, Dr. Kuijt
Max C.

Main Menu Module
*/
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

#include "../header_files/all.h"

using namespace std;

// Global Variables

BookData book;
BookFile file("../inventory.txt");

int main() {
  int userInput;
  bool exitMenu = false;

  // Menu exits on user input "4"
  while (exitMenu == false) {
    cout << endl;
    cout << "Serendipity Booksellers" << endl
         << "1. Cashier Module" << endl
         << "2. Inventory Database Module" << endl
         << "3. Report Module" << endl
         << "4. Exit" << endl
         << endl
         << "Enter your choice: ";

    cin >> userInput;
    cin.ignore();

    switch (userInput) {
    case 1:
      cout << "You selected item 1" << endl;
      cashier();
      break;
    case 2:
      cout << "You selected item 2" << endl;
      invMenu();
      break;
    case 3:
      cout << "You selected item 3" << endl;
      reports();
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
