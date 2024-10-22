
/*
cashier.cpp
CMSC 226, CRN 35481, Dr. Kuijt
Max C.

Cashier module
Ask for input and outputs a "receipt"
*/
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "../header_files/all.h"

using namespace std;

void cashier() {
  int bookQuantity;
  string ISBN;
  string userInput;

  int ind;
  vector<int> shoppingCart(file.totalIndex(), 0);

  const double TAX_RATE = 0.06;
  double salesTax = 0;
  double subtotal = 0;
  double total = 0;

  bool exitRegister = false;

  while (exitRegister == false) {

    cout << "Serendipity Booksellers" << endl
         << "Cashier Module" << endl
         << endl;

    cout << "ISBN: ";
    cin >> ISBN;
    cin.ignore();
    cout << endl;

    ind = findISBN(ISBN);
    if (ind == -1) {
      cout << "ISBN not found!" << endl
           << "Would you like to try again? (y/N) ";
      cin >> userInput;
      cin.ignore();

      if (userInput != "y") {
        return;
      }
      continue;
    }
    book = file.readFile(book, ind);

    cout << "Book title: " << book.getTitle() << endl
         << "Retail Price: " << book.getRetail() << endl
         << "Quantity: " << book.getQty() << endl;

    cout << "How many books would you like to purchase? : ";
    cin >> bookQuantity;
    cin.ignore();

    if (book.getQty() - bookQuantity < 0 || bookQuantity < 0) {
      cout << "Not enough book in stock or invalid input!" << endl
           << "Quitting...." << endl
           << endl;
      // restock shelf with stuff from cart

      for (int i = 0; i < file.totalIndex(); i++) {
        book = file.readFile(book, i);
        cout << shoppingCart[i];
        book.setQty(book.getQty() + shoppingCart[i]);
        file.writeFile(book, i);
      }
      return;
    }
    book.setQty(book.getQty() - bookQuantity);
    file.writeFile(book, ind);
    shoppingCart[ind] += bookQuantity;

    cout << "Would you like to purchase another book? (y/N) ";
    cin >> userInput;
    cin.ignore();

    if (userInput == "y") {
      continue;
    }

    // header
    cout << "Today's Date: ";
    coutTime();
    cout << endl;
    cout << "Serendipity Book Sellers" << endl
         << "Date: " << endl
         << setw(6) << "Qty" << setw(51) << "ISBN" << setw(51) << "Title"
         << setw(15) << "Price" << setw(15) << "Total" << endl
         << setfill('_') << setw(157) << "" << endl
         << setfill(' ');

    for (int i = 0; i < file.totalIndex(); i++) {
      // Content
      if (shoppingCart[i] != 0) {
        book = file.readFile(book, i);
        subtotal += shoppingCart[i] * book.getRetail();
        salesTax += subtotal * TAX_RATE;
        total += salesTax + subtotal;

        cout << setw(6) << fixed << shoppingCart[i] << setw(51)
             << book.getISBN() << setw(51) << book.getTitle() << setw(15)
             << setprecision(2) << book.getRetail() << setw(15)
             << shoppingCart[i] * book.getRetail() << endl;
      }
    }
    //
    // footer
    cout << endl;
    cout << setw(10) << "" << setw(20) << left << "Subtotal" << setw(50)
         << right << subtotal << endl
         << setw(10) << "" << setw(20) << left << "Tax" << setw(50) << right
         << salesTax << endl
         << setw(10) << "" << setw(20) << left << "Total" << setw(50) << right
         << total << endl
         << "Thank You for Shopping at Serendipity!" << endl;

    cout << "Would you like to make another transaction? (y/N): ";
    cin >> userInput;
    cin.ignore();

    exitRegister = userInput == "y" ? false : true;
    subtotal = 0;
    salesTax = 0;
    total = 0;
    for (int i = 0; i < file.totalIndex(); i++) {
      shoppingCart[i] = 0;
    }
    cout << endl;
  }
}

int findISBN(string ISBN) {
  for (int i = 0; i < file.totalIndex(); i++) {
    book = file.readFile(book, i);
    if (ISBN == book.getISBN()) {
      return i;
    }
  }
  return -1;
}