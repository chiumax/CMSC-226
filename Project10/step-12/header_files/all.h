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

// defining variables

// number of elements
extern int maxElm;

class BookData {
private:
  char bookTitle[51];
  char isbn[14];
  char author[31];
  char publisher[31];
  char dateAdded[11];

  int qtyOnHand;

  double wholesale;
  double retail;

public:
  // constructors
  BookData() {
    strcpy(this->bookTitle, "\0");
    strcpy(this->isbn, "\0");
    strcpy(this->author, "\0");
    strcpy(this->publisher, "\0");
    strcpy(this->dateAdded, "\0");

    qtyOnHand = 0;
    wholesale = 0;
    retail = 0;
  }

  BookData(char isbn[], char title[], char author[], char publisher[],
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

  void setWholesale(double val) { this->wholesale = val; }
  void setRetail(double val) { this->retail = val; }

  // getters

  string getTitle() { return this->bookTitle; }
  string getISBN() { return this->isbn; }
  string getAuthor() { return this->author; }
  string getPub() { return this->publisher; }
  string getDateAdded() { return this->dateAdded; }

  int getQty() { return this->qtyOnHand; }

  double getWholesale() { return this->wholesale; }
  double getRetail() { return this->retail; }

  // class functions

  bool bookMatch(string bookTitle) {
    char bookTitleChar[51];
    strcpy(bookTitleChar, userBook.c_str());
    strUpper(bookTitleChar);
    return strstr(this->bookTitle, bookTitleChar);
  }
};


class BookFile{
  private:
    fstream file;
  public:
  // constructors
    BookFile() {

    }
    
    BookFile(string filePath) {
        fstream tempFile;
        tempFile(filePath, ios::in | ios::binary | ios::out);
        this->file =  tempFile;
    }

  int writeFile(bookData book) {
    this->file.clear();
    this->file.seekp(0L, ios::end);
    this->file.write(reinterpret_cast<char *>(&book), sizeof(book));
    this->file.flush();
    return this->file.tellp();
  }

  int writeFile(bookData book, int index) {
    this->file.clear();
    this->file.seekp(sizeof(book) * index, ios::beg);
    this->file.write(reinterpret_cast<char *>(&book), sizeof(book));
    this->file.flush();

    return index;
  }

  bookData readFile(bookData book) {
    this->file.clear();
    this->file.seekg(0L, ios::beg);
    if (!this->file.eof()) {
      this->file.read(reinterpret_cast<char *>(&book), sizeof(book));
      return book;
    }
    return book;
  }
  bookData readFile(bookData book, int index) {
    this->file.clear();
    this->file.seekg(sizeof(book) * index, ios::beg);
    if (!this->file.eof()) {
      this->file.read(reinterpret_cast<char *>(&book), sizeof(book));
      return book;
    }
    cout << "error";
    return book;
  }

  int totalIndex() {
    this->file.seekp(0L, ios::end);
    return this->file.tellp() / sizeof(book);
  }

}

extern BookData book;
extern BookFile file;

#endif
