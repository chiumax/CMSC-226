/*
reports.cpp
CMSC 226, CRN 35481, Dr. Kuijt
file.totalIndex() C.

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

  for (int i = 0; i < file.totalIndex(); i++) {
    book = file.readFile(book, i);
    if (book.getTitle() != "\0") {
      cout << endl << endl << "Book #" << count << endl;
      cout << "=====" << endl
           << "Title: " << book.getTitle() << endl
           << "ISBN #: " << book.getISBN() << endl
           << "Author: " << book.getAuthor() << endl
           << "Publisher: " << book.getPub() << endl
           << "Date Added (MM-DD-YYYY): " << book.getDateAdded() << endl
           << "Quantity on Hand: " << book.getQty() << endl
           << "Wholesale Cost: " << book.getWholesale() << endl
           << "Retail Price: " << book.getRetail() << endl
           << "=====" << endl;
      count++;
    }
  }
  // TODO: Modify from 20 to a dynamic file.totalIndex() limit
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
  for (int i = 0; i < file.totalIndex(); i++) {
    book = file.readFile(book, i);
    if (book.getTitle() != "\0") {
      cout << endl << endl << "Book #" << count << endl;
      cout << "=====" << endl
           << "Title: " << book.getTitle() << endl
           << "ISBN #: " << book.getISBN() << endl
           << "Quantity on Hand: " << book.getQty() << endl
           << "Wholesale Cost: " << book.getWholesale() << endl
           << "=====" << endl;
      count++;
      total += book.getWholesale() * book.getQty();
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
  for (int i = 0; i < file.totalIndex(); i++) {
    book = file.readFile(book, i);
    if (book.getTitle() != "\0") {
      cout << endl << endl << "Book #" << count << endl;
      cout << "=====" << endl
           << "Title: " << book.getTitle() << endl
           << "ISBN #: " << book.getISBN() << endl
           << "Quantity on Hand: " << book.getQty() << endl
           << "Retail Price: " << book.getRetail() << endl
           << "=====" << endl;
      count++;
      total += book.getRetail() * book.getQty();
    }
  }
  cout << "Total retail value of inventory: " << total << endl;
}
/// change to reflect class
void repQty() {
  cout << "You selected Listing By Quantity" << endl << endl;

  cout << setw(10) << " "
       << "Entire Inventory Book Quantities " << setw(10) << " " << endl
       << "Date: ";
  coutTime();
  cout << endl;
  int count = 1;

  descendingSort("quantity");

  for (int i = 0; i < file.totalIndex(); i++) {
    book = file.readFile(book, i);
    if (book.getTitle() != "\0") {
      cout << endl << endl << "Book #" << count << endl;
      cout << "=====" << endl
           << "Title: " << book.getTitle() << endl
           << "ISBN #: " << book.getISBN() << endl
           << "Quantity on Hand: " << book.getQty() << endl
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
  int count = 1;

  descendingSort("wholesale");

  for (int i = 0; i < file.totalIndex(); i++) {
    book = file.readFile(book, i);
    if (book.getTitle() != "\0") {
      cout << endl << endl << "Book #" << count << endl;
      cout << "=====" << endl
           << "Title: " << book.getTitle() << endl
           << "ISBN #: " << book.getISBN() << endl
           << "Quantity on Hand: " << book.getQty() << endl
           << "Wholesale Cost: " << book.getWholesale() << endl
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
  int count = 1;

  descendingSort("date");

  // descendingSortDate(&dateAdded[0], p);

  for (int i = 0; i < file.totalIndex(); i++) {
    book = file.readFile(book, i);

    if (book.getTitle() != "\0") {
      cout << endl << endl << "Book #" << count << endl;
      cout << "=====" << endl
           << "Title: " << book.getTitle() << endl
           << "ISBN #: " << book.getISBN() << endl
           << "Quantity on Hand: " << book.getQty() << endl
           << "Date Added (MM-DD-YYYY): " << book.getDateAdded() << endl
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

void descendingSort(string type) {
  int max = 0;
  BookData tempBook;
  bool condition;
  // using selection sort
  for (int i = 0; i < file.totalIndex(); i++) {
    max = i;
    for (int j = i; j < file.totalIndex(); j++) {
      tempBook = file.readFile(tempBook, j);
      book = file.readFile(book, max);

      if (type == "wholesale") {
        condition = book.getWholesale() < tempBook.getWholesale();
      }
      if (type == "quantity") {
        condition = book.getQty() < tempBook.getQty();
      }
      if (type == "date") {
        string tempDate = tempBook.getDateAdded();
        string date = book.getDateAdded();
        tempDate = tempDate.substr(6, 4) + tempDate.substr(0, 2) +
                   tempDate.substr(3, 2);
        date = date.substr(6, 4) + date.substr(0, 2) + date.substr(3, 2);
        condition = date < tempDate;
      }

      if (condition) {
        max = j;
      }
    }
    tempBook = file.readFile(book, i);
    book = file.readFile(book, max);
    file.writeFile(book, i);
    file.writeFile(tempBook, max);
  }
}