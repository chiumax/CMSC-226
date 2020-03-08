#ifndef MAIN_HEADER
#define MAIN_HEADER

/*
// TODO: print out 2 decimals for bookinfo

*/

#include <string>

using namespace std;
// bookinfo.cpp
void bookInfo(string isbn, string title, string author, string publisher,
              string date, int qty, double wholesale, double retail);

// cashier.cpp
void cashier();

// invmenu.cpp
void invMenu();

void lookUpBook();

void addBook();

void editBook();

void deleteBook();

// reports.cpp
void reports();

void repListing();

void repWholesale();

void repRetail();

void repQty();

void repCost();

void repAge();

// Global Variables
// bookinfo.cpp
/*
 Parallel arrays
 arr[0] 0 represents the obj.
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