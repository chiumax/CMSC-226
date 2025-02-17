/*
mainmenu.cpp
CMSC 226, CRN 35481, Dr. Kuijt
Max C.

Main Menu Module
*/
#include <iomanip>
#include <iostream>
#include <string>

#include "../header_files/all.h"

using namespace std;

// Global Variables

// bookinfo.cpp
/*
 Parallel arrays
 arr[0] 0 represents the obj.
*/
char bookTitle[20][51] = {"HARRY POTTER HOGWARTZ", "JAMES", "LORD OF THE RING",
                          "BACK TO THE PAST", "HARRY POTTER SORCEROR STONE"};
char isbn[20][14] = {"ASDF-1234", "FDSA-1234", "QWER-5433", "PSAT-2424",
                     "QPQP-2341"};
char author[20][31] = {"JKJK", "DOE", "YAAAA", "MCQING", "JKJK"};
char publisher[20][31] = {"DIDNEY", "HOLLY", "PIXAR", "DIDNEY", "DIDNEY"};
char dateAdded[20][11] = {"05-05-2020", "05-06-2021", "05-06-2019",
                          "05-05-2020", "07-21-2019"};

// char bookTitle[20][51] = {"\0"};
// char isbn[20][14] = {"\0"};
// char author[20][31] = {"\0"};
// char publisher[20][31] = {"\0"};
// char dateAdded[20][11] = {"\0"};
// string bookTitle[20] = {"Harry Potter", "James", "lord of ring",
//                         "back to the past"};
// string isbn[20] = {"ASDF-1234", "FDSA-1234", "QWER-5433", "PSAT-2424"};
// string author[20] = {"JKJK", "Doe", "Yaaa", "Mcqing"};
// string publisher[20] = {"Didney", "Holly", "Pixar", "Didney"};
// string dateAdded[20] = {"05-05-2020", "05-06-2021", "05-06-2019",
// "05-05-2020"};

// int qtyOnHand[20] = {2, 0, 6, 7};

// double wholesale[20] = {1.01, 2.02, 9.99, 3.04};
// double retail[20] = {0.51, 1.51, 4.55, 3.04};
// bookTitle = {"Harry Potter", "James", "lord of ring", "back to the past"};
// isbn = {"ASDF-1234", "FDSA-1234", "QWER-5433", "PSAT-2424"};
// author = {"JKJK", "Doe", "Yaaa", "Mcqing"};
// publisher = {"Didney", "Holly", "Pixar", "Didney"};
// dateAdded = {"05-05-2020", "05-06-2021", "05-06-2019", "05-05-2020"};

int qtyOnHand[20] = {2, 0, 6, 7};

double wholesale[20] = {1.01, 2.02, 9.99, 3.04};
double retail[20] = {0.51, 1.51, 4.55, 3.04};
int maxElm = 20;
//

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
