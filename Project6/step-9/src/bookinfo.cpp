/*
bookinfo.cpp
CMSC 226, CRN 35481, Dr. Kuijt
Max C.

Book Info module
*/
#include <iomanip>
#include <iostream>
#include <string>

#include "../header_files/all.h"

using namespace std;

void bookInfo(string isbn, string title, string author, string publisher,
              string date, int qty, double wholesale, double retail) {

  /*


  */

  cout << fixed << setprecision(2);

  cout << "Serendipity Booksellers" << endl
       << "Book Information" << endl
       << endl
       << "ISBN: " << isbn << endl
       << "Title: " << title << endl
       << "Author: " << author << endl
       << "Publisher: " << publisher << endl
       << "Date Added: " << date << endl
       << "Quantity-On-Hand: " << qty << endl
       << "Wholesale Cost: " << wholesale << endl
       << "Retail Price: " << retail << endl;
}
