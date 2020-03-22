#ifndef MAIN_HEADER
#define MAIN_HEADER

#include <string>

using namespace std;

/*
    bookinfo.cpp
*/
void bookInfo(string isbn, string title, string author, string publisher,
              string date, int qty, double wholesale, double retail);

/*
    cashier.cpp
*/

void cashier();

/*
    invmenu.cpp
*/
void invMenu();

void lookUpBook();

void addBook();

void editBook();

void deleteBook();

// custom functions for invmenu

// return index of book given bookName
// if not found, return -1
int bookIndex(string bookName);

// display all book attributes
// ask which one to edit until user quits
void editBookMenu(int bookIndex);

// given message output whether "y" or not based on userInput
bool confirm(string message);

// given book index print out bookInfo()
void displayBook(int bookIndex);

/*
    reports.cpp
*/
void reports();

void repListing();

void repWholesale();

void repRetail();

void repQty();

void repCost();

void repAge();

// custom functions for reports

// prints current time
void coutTime();
// Global Variables
// bookinfo.cpp
/*
 Parallel arrays
 arr[0] 0 represents the obj.

 no need to use extern i believe
*/
extern string bookTitle[20];
extern string isbn[20];
extern string author[20];
extern string publisher[20];
extern string dateAdded[20];

extern int qtyOnHand[20];

extern double wholesale[20];
extern double retail[20];
//

#endif
