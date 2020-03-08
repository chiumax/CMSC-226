/*
reports.cpp
CMSC 226, CRN 35481, Dr. Kuijt
Max C.

Reports Module
*/

#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  int userInput;
  bool exitMenu = false;

  // Menu exits on user input "7"
  while (exitMenu == false) {
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
      cout << "You selected item 5" << endl;
      break;
    case 6:
      cout << "You selected item 6" << endl;
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
