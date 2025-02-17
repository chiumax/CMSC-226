/*
invmenu.cpp
CMSC 226, CRN 35481, Dr. Kuijt
Max C.

Inventory Module
*/

#include <iomanip>
#include <iostream>

#include "invmenu.h"

using namespace std;

int invMenu() {
  int userInput;
  bool exitMenu = false;

  // Menu exits on user input "5"
  while (exitMenu == false) {
    cout << endl;
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
      lookUpBook();
      break;
    case 2:
      addBook();
      break;
    case 3:
      editBook();
      break;
    case 4:
      deleteBook();
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
  cout << "Menu exited" << endl << endl;
}

void lookUpBook() { cout << "You selected Look Up Book." << endl; }

void addBook() { cout << "You selected Add Book." << endl; }

void editBook() { cout << "You selected Edit Book." << endl; }

void deleteBook() { cout << "You selected Delete Book." << endl; }