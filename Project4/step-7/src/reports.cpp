/*
reports.cpp
CMSC 226, CRN 35481, Dr. Kuijt
Max C.

Reports Module
*/
#include <iomanip>
#include <iostream>
#include <string>

#include "../header_files/all.h"

using namespace std;

void reports() {
  int userInput;
  bool exitMenu = false;

  // Menu exits on user input "7"
  while (exitMenu == false) {
    cout << endl;
    cout << "Serendipity Booksellers" << endl
         << "Reports" << endl
         << "1. Inventory Listing" << endl
         << "2. Inventory Wholesale Value" << endl
         << "3. Inventory Retail Value" << endl
         << "4. Listing by Quantity" << endl
         << "5. Listing by Cost" << endl
         << "6. Listing by Age" << endl
         << "7. Return to Main Menu" << endl
         << endl
         << "Enter Your Choice: ";

    cin >> userInput;

    switch (userInput) {
    case 1:
      repListing();
      break;
    case 2:
      repWholesale();
      break;
    case 3:
      repRetail();
      break;
    case 4:
      repQty();
      break;
    case 5:
      repCost();
      break;
    case 6:
      repAge();
      break;
    case 7:
      // EXIT HERE
      cout << "You selected item 7" << endl;
      exitMenu = true;
      break;
    default:
      cout << "Please enter a number in the range 1-7" << endl;
      break;
    }
  }
  cout << "Menu exited" << endl;
}

void repListing() { cout << "You selected Inventory Listing." << endl; }

void repWholesale() {
  cout << "You selected Inventory Wholesale Value." << endl;
}

void repRetail() { cout << "You selected Inventory Retail Value." << endl; }

void repQty() { cout << "You selected Listing By Quantity" << endl; }

void repCost() { cout << "You selected Listing By Cost" << endl; }

void repAge() { cout << "You selected Listing By Age." << endl; }