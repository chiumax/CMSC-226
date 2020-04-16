#ifndef MAIN_HEADER
#define MAIN_HEADER

#include <cstring>
#include <fstream>
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
/////////////////////////////////////////////////
// extern char bookTitle[20][51];
// extern char isbn[20][14];
// extern char author[20][31];
// extern char publisher[20][31];
// extern char dateAdded[20][11];

// extern int qtyOnHand[20];

// extern double wholesale[20];
// extern double retail[20];
/////////////////////////////////////////////////

// defining variables

// number of elements
extern int maxElm;

class bookData {
private:
  char bookTitle[51];
  char isbn[14];
  char author[31];
  char publisher[31];
  char dateAdded[11];

  int qtyOnHand;
  int index;

  double wholesale;
  double retail;

public:
  // constructors
  bookData() {
    strcpy(this->bookTitle, "\0");
    strcpy(this->isbn, "\0");
    strcpy(this->author, "\0");
    strcpy(this->publisher, "\0");
    strcpy(this->dateAdded, "\0");

    qtyOnHand = 0;
    wholesale = 0;
    retail = 0;
  }

  bookData(char isbn[], char title[], char author[], char publisher[],
           char date[], int qty, double wholesale, double retail) {}

  bool isEmpty() { return (bookTitle[0] == '\0'); }

  void removeBook() { strcpy(this->bookTitle, "\0"); }

  // setters

  void setTitle(string p) { strcpy(this->bookTitle, (p).c_str()); }
  void setISBN(string p) { strcpy(this->isbn, (p).c_str()); }
  void setAuthor(string p) { strcpy(this->author, (p).c_str()); }
  void setPub(string p) { strcpy(this->publisher, (p).c_str()); }
  void setDateAdded(string p) { strcpy(this->dateAdded, (p).c_str()); }

  void setQty(int val) { this->qtyOnHand = val; }
  void setIndex(int val) { this->index = val; }

  void setWholesale(double val) { this->wholesale = val; }
  void setRetail(double val) { this->retail = val; }

  // getters

  string getTitle() { return this->bookTitle; }
  string getISBN() { return this->isbn; }
  string getAuthor() { return this->author; }
  string getPub() { return this->publisher; }
  string getDateAdded() { return this->dateAdded; }

  int getQty() { return this->qtyOnHand; }
  int getIndex() { return this->index; }

  double getWholesale() { return this->wholesale; }
  double getRetail() { return this->retail; }
};

extern bookData books[20];

extern bookData book;

extern fstream inFile;
extern fstream outFile;
extern fstream file;

// file.cpp
int writeFile(bookData book);
int writeFile(bookData book, int index);
bookData readFile(bookData book);
bookData readFile(bookData book, int index);
#endif
