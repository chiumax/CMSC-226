#ifndef MAIN_HEADER
#define MAIN_HEADER

#include <string>

using namespace std;

/*
    bookinfo.cpp
*/
void bookInfo(char isbn[], char title[], char author[], char publisher[],
              char date[], int qty, double wholesale, double retail);

/*
    cashier.cpp
*/

void cashier();

// custom functions for cashier

// given isbn string return index
int findISBN(string ISBN);

/*
    invmenu.cpp
*/
void invMenu();

void lookUpBook();

void addBook();

void editBook();

void deleteBook();

void strUpper(char *input);
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

// descending sort
void descendingSort(double *pointer, double *p[]);
// overload for int
void descendingSort(int *pointer, int *p[]);
// overload for string
void descendingSort(string *pointer, string *p[]);

// print
// Global Variables
// bookinfo.cpp
/*
 Parallel arrays
 arr[0] 0 represents the obj.

 no need to use extern i believe
*/
extern char bookTitle[20][51];
extern char isbn[20][14];
extern char author[20][31];
extern char publisher[20][31];
extern char dateAdded[20][11];

extern int qtyOnHand[20];

extern double wholesale[20];
extern double retail[20];

// defining variables

// number of elements
extern int maxElm;

#endif
