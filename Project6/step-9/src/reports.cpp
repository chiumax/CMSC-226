/*
reports.cpp
CMSC 226, CRN 35481, Dr. Kuijt
maxElm C.

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
       << "Entire Inventory " << setw(10) << " " << endl
       << "Date: ";
  coutTime();
  cout << endl;

  int count = 1;
  for (int i = 0; i < maxElm; i++) {
    if (isbn[i] != "\0" && isbn[i] != "") {
      cout << endl << endl << "Book #" << count << endl;
      cout << "=====" << endl
           << "Title: " << bookTitle[i] << endl
           << "ISBN #: " << isbn[i] << endl
           << "Author: " << author[i] << endl
           << "Publisher: " << publisher[i] << endl
           << "Date Added (MM-DD-YYYY): " << dateAdded[i] << endl
           << "Quantity on Hand: " << qtyOnHand[i] << endl
           << "Wholesale Cost: " << wholesale[i] << endl
           << "Retail Price: " << retail[i] << endl
           << "=====" << endl;
      count++;
    }
  }
  // TODO: Modify from 20 to a dynamic maxElm limit
}

void repWholesale() {
  cout << "You selected Inventory Wholesale Value." << endl << endl;

  cout << setw(10) << " "
       << "Entire Inventory Wholesale Prices " << setw(10) << " " << endl
       << "Date: ";
  coutTime();
  cout << endl;

  int count = 1;
  double total = 0;
  for (int i = 0; i < maxElm; i++) {
    if (isbn[i] != "\0" && isbn[i] != "") {
      cout << endl << endl << "Book #" << count << endl;
      cout << "=====" << endl
           << "Title: " << bookTitle[i] << endl
           << "ISBN #: " << isbn[i] << endl
           << "Quantity on Hand: " << qtyOnHand[i] << endl
           << "Wholesale Cost: " << wholesale[i] << endl
           << "=====" << endl;
      count++;
      total += wholesale[i] * qtyOnHand[i];
    }
  }
  cout << "Total wholesale value of inventory: " << total << endl;
}

void repRetail() {
  cout << "You selected Inventory Retail Value." << endl << endl;

  cout << setw(10) << " "
       << "Entire Inventory Retail Prices " << setw(10) << " " << endl
       << "Date: ";
  coutTime();
  cout << endl;

  int count = 1;
  double total = 0;
  for (int i = 0; i < maxElm; i++) {
    if (isbn[i] != "\0" && isbn[i] != "") {
      cout << endl << endl << "Book #" << count << endl;
      cout << "=====" << endl
           << "Title: " << bookTitle[i] << endl
           << "ISBN #: " << isbn[i] << endl
           << "Quantity on Hand: " << qtyOnHand[i] << endl
           << "Retail Price: " << retail[i] << endl
           << "=====" << endl;
      count++;
      total += retail[i] * qtyOnHand[i];
    }
  }
  cout << "Total retail value of inventory: " << total << endl;
}

void repQty() {
  cout << "You selected Listing By Quantity" << endl << endl;

  cout << setw(10) << " "
       << "Entire Inventory Book Quantities " << setw(10) << " " << endl
       << "Date: ";
  coutTime();
  cout << endl;

  int *p[maxElm];
  descendingSort(&qtyOnHand[0], p);
  int count = 1;
  for (int i = 0; i < maxElm; i++) {
    int ind = p[i] - &qtyOnHand[0];
    if (isbn[ind] != "\0" && isbn[ind] != "") {
      cout << endl << endl << "Book #" << count << endl;
      cout << "=====" << endl
           << "Title: " << bookTitle[ind] << endl
           << "ISBN #: " << isbn[ind] << endl
           << "Quantity on Hand: " << qtyOnHand[ind] << endl
           << "=====" << endl;
      count++;
    }
  }
}

void repCost() {
  cout << "You selected Listing By Cost" << endl << endl;

  cout << setw(10) << " "
       << "Entire Inventory Book Costs " << setw(10) << " " << endl
       << "Date: ";
  coutTime();
  cout << endl;

  double *p[maxElm];
  descendingSort(&wholesale[0], p);
  int count = 1;
  for (int i = 0; i < maxElm; i++) {
    int ind = p[i] - &wholesale[0];
    if (isbn[ind] != "\0" && isbn[ind] != "") {
      cout << endl << endl << "Book #" << count << endl;
      cout << "=====" << endl
           << "Title: " << bookTitle[ind] << endl
           << "ISBN #: " << isbn[ind] << endl
           << "Quantity on Hand: " << qtyOnHand[ind] << endl
           << "Wholesale Cost: " << wholesale[ind] << endl
           << "=====" << endl;
      count++;
    }
  }
}

void repAge() {
  cout << "You selected Listing By Age." << endl << endl;

  cout << setw(10) << " "
       << "Entire Inventory Date Added " << setw(10) << " " << endl
       << "Date: ";
  coutTime();
  cout << endl;

  // preprocess dates
  string val[maxElm];
  string *p[maxElm];
  for (int i = 0; i < maxElm; i++) {
    // reordering string for comparison
    // YYYY-MM-DD

    // dates are MM-DD-YYYY for substring
    // 0,2 3,2 6,4
    string date = dateAdded[i];

    if (date != "") {
      val[i] = date.substr(6, 4) + date.substr(0, 2) + date.substr(3, 2);
    }
  }
  descendingSort(&val[0], p);

  // descendingSortDate(&dateAdded[0], p);
  int count = 1;
  for (int i = 0; i < maxElm; i++) {
    int ind = p[i] - &val[0];

    if (isbn[ind] != "\0" && isbn[ind] != "") {
      cout << endl << endl << "Book #" << count << endl;
      cout << "=====" << endl
           << "Title: " << bookTitle[ind] << endl
           << "ISBN #: " << isbn[ind] << endl
           << "Quantity on Hand: " << qtyOnHand[ind] << endl
           << "Date Added (MM-DD-YYYY): " << dateAdded[ind] << endl
           << "=====" << endl;
      count++;
    }
  }
}

void coutTime() {
  // code from https://www.tutorialspoint.com/cplusplus/cpp_date_time.htm

  // current time
  time_t now = time(0);

  // convert now to string form
  char *dt = ctime(&now);

  cout << dt;
}

void descendingSort(double *pointer, double *p[]) {
  // uses selection sort to sort items in descending order
  // pointer is array of pointers to sort
  // double *p[maxElm];
  int max = 0;

  // assign pointers to array
  for (int i = 0; i < maxElm; i++) {
    p[i] = pointer + i;
  }

  // using selection sort
  for (int i = 0; i < maxElm; i++) {
    max = i;
    for (int j = i; j < maxElm; j++) {
      if (*p[max] < *p[j]) {
        max = j;
      }
    }
    double *temp = p[max];
    p[max] = p[i];
    p[i] = temp;
  }
}
void descendingSort(int *pointer, int *p[]) {
  // uses selection sort to sort items in descending order
  // pointer is array of pointers to sort
  // double *p[maxElm];
  int max = 0;

  // assign pointers to array
  for (int i = 0; i < maxElm; i++) {
    p[i] = pointer + i;
  }

  // using selection sort
  for (int i = 0; i < maxElm; i++) {
    max = i;
    for (int j = i; j < maxElm; j++) {
      if (*p[max] < *p[j]) {
        max = j;
      }
    }
    int *temp = p[max];
    p[max] = p[i];
    p[i] = temp;
  }
}
void descendingSort(string *pointer, string *p[]) {
  // uses selection sort to sort items in descending order
  // pointer is array of pointers to sort
  // double *p[maxElm];
  int max = 0;

  // assign pointers to array
  for (int i = 0; i < maxElm; i++) {
    p[i] = pointer + i;
  }

  // using selection sort
  for (int i = 0; i < maxElm; i++) {
    max = i;
    for (int j = i; j < maxElm; j++) {
      if ((*p[max]) > (*p[j])) {

        max = j;
      }
    }
    string *temp = p[max];
    p[max] = p[i];
    p[i] = temp;
  }
}
