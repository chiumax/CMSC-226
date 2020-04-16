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
// char bookTitle[20][51] = {"HARRY POTTER HOGWARTZ", "JAMES", "LORD OF THE
// RING",
//                           "BACK TO THE PAST", "HARRY POTTER SORCEROR STONE"};
// char isbn[20][14] = {"ASDF-1234", "FDSA-1234", "QWER-5433", "PSAT-2424",
//                      "QPQP-2341"};
// char author[20][31] = {"JKJK", "DOE", "YAAAA", "MCQING", "JKJK"};
// char publisher[20][31] = {"DIDNEY", "HOLLY", "PIXAR", "DIDNEY", "DIDNEY"};
// char dateAdded[20][11] = {"05-05-2020", "05-06-2021", "05-06-2019",
//                           "05-05-2020", "07-21-2019"};

// int qtyOnHand[20] = {2, 0, 6, 7};

// double wholesale[20] = {1.01, 2.02, 9.99, 3.04};
// double retail[20] = {0.51, 1.51, 4.55, 3.04};

bookData books[20];
int maxElm = 20;

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

//

int main() {

  books[0].setTitle("HARRY POTTER HOGWARTZ");
  books[0].setISBN("ASDF-1234");
  books[0].setAuthor("JKJK");
  books[0].setPub("DIDNEY");
  books[0].setDateAdded("05-05-2020");
  books[0].setQty(2);
  books[0].setWholesale(1.01);
  books[0].setRetail(0.51);

  books[1].setTitle("JAMES");
  books[1].setISBN("FDSA-1234");
  books[1].setAuthor("DOE");
  books[1].setPub("HOLLY");
  books[1].setDateAdded("05-06-2021");
  books[1].setQty(0);
  books[1].setWholesale(2.02);
  books[1].setRetail(1.51);

  books[2].setTitle("LORD OF THE RING");
  books[2].setISBN("QWER-5433");
  books[2].setAuthor("YAAAA");
  books[2].setPub("PIXAR");
  books[2].setDateAdded("05-06-2019");
  books[2].setQty(6);
  books[2].setWholesale(9.99);
  books[2].setRetail(4.55);

  books[3].setTitle("BACK TO THE PAST");
  books[3].setISBN("PSAT-2424");
  books[3].setAuthor("MCQING");
  books[3].setPub("DIDNEY");
  books[3].setDateAdded("05-05-2020");
  books[3].setQty(7);
  books[3].setWholesale(3.04);
  books[3].setRetail(3.04);

  books[4].setTitle("HARRY POTTER SORCEROR STONE");
  books[4].setISBN("QPQP-2341");
  books[4].setAuthor("JKJK");
  books[4].setPub("DIDNEY");
  books[4].setDateAdded("07-21-2019");
  books[4].setQty(2);
  books[4].setWholesale(1.01);
  books[4].setRetail(0.51);

  writeFile(books[0]);
  writeFile(books[1]);
  writeFile(books[2]);
  writeFile(books[3]);
  writeFile(books[4]);

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
