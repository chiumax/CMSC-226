/*
reports.cpp
CMSC 226, CRN 35481, Dr. Kuijt
Max C.

Reports Module
*/
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>

#include "../header_files/all.h"

using namespace std;

void reports() {
  int userInput;
  bool exitMenu = false;

  cout << setfill('=');

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
    cin.ignore();

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

void repListing() {
  cout << "You selected Inventory Listing." << endl << endl;

  cout << setw(10) << " "
       << "Entire Inventory" << setw(10) << " " << endl
       << "Date: ";
  coutTime();
  cout << endl;

  // TODO: Modify from 20 to a dynamic max limit
}

void repWholesale() {
  cout << "You selected Inventory Wholesale Value." << endl << endl;

  cout << setw(10) << " "
       << "Entire Inventory Wholesale Prices" << setw(10) << " " << endl
       << "Date: ";
  coutTime();
  cout << endl;
}

void repRetail() {
  cout << "You selected Inventory Retail Value." << endl << endl;

  cout << setw(10) << " "
       << "Entire Inventory Retail Prices" << setw(10) << " " << endl
       << "Date: ";
  coutTime();
  cout << endl;
}

void repQty() {
  cout << "You selected Listing By Quantity" << endl << endl;

  cout << setw(10) << " "
       << "Entire Inventory Book Quantities" << setw(10) << " " << endl
       << "Date: ";
  coutTime();
  cout << endl;
}

void repCost() {
  cout << "You selected Listing By Cost" << endl << endl;

  cout << setw(10) << " "
       << "Entire Inventory Book Costs" << setw(10) << " " << endl
       << "Date: ";
  coutTime();
  cout << endl;
}

void repAge() {
  cout << "You selected Listing By Age." << endl << endl;

  cout << setw(10) << " "
       << "Entire Inventory Date Added" << setw(10) << " " << endl
       << "Date: ";
  coutTime();
  cout << endl;
}

void coutTime() {
  // code from https://www.tutorialspoint.com/cplusplus/cpp_date_time.htm

  // current time
  time_t now = time(0);

  // convert now to string form
  char *dt = ctime(&now);

  cout << dt;
}