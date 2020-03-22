/*
invmenu.cpp
CMSC 226, CRN 35481, Dr. Kuijt
Max C.

Inventory Module
*/
#include <iomanip>
#include <iostream>
#include <string>

#include "../header_files/all.h"

using namespace std;

void invMenu() {
  int userInput;
  bool exitMenu = false;

  // Menu exits on user input "5"
  while (exitMenu == false) {
    cout << endl;
    cout << "Serendipity Booksellers" << endl
         << "Inventory Database" << endl
         << "1. Look Up a Book" << endl
         << "2. Add a Book" << endl
         << "3. Edit a Book's Record" << endl
         << "4. Delete a Book" << endl
         << "5. Return to the Main Menu" << endl
         << endl
         << "Enter Your Choice: ";
    cin >> userInput;
    cin.ignore();

    switch (userInput) {
    case 1:
      lookUpBook();
      break;
    case 2:
      addBook();
      break;
    case 3:
      editBook();
      break;
    case 4:
      deleteBook();
      break;
    case 5:
      // EXIT HERE
      cout << "You selected item 5" << endl;
      exitMenu = true;
      break;
    default:
      cout << "Please enter a number in the range 1-5" << endl;
      break;
    }
  }
  cout << "Menu exited" << endl << endl;
}

// prints out book information
void lookUpBook() {
  string userBook;
  int index = 0;

  cout << "You selected Look Up Book." << endl;
  cout << "Title of book to look up: ";

  getline(cin, userBook);

  index = bookIndex(userBook);

  if (index > -1) {
    // look up book
    displayBook(index);

    cout << "Book looked up..." << endl;
  } else {
    cout << "Book not in inventory";
  }
}

void addBook() {
  string stringInput;
  double doubleInput;
  int intInput;
  cout << "You selected Add Book." << endl;

  for (int i = 0; i < 20; i++) {
    if (bookTitle[i] == "" || bookTitle[i] == "\0") {
      cout << "Book title: ";

      getline(cin, stringInput);
      bookTitle[i] = stringInput;

      cout << "ISBN #: ";
      cin >> stringInput;
      cin.ignore();
      isbn[i] = stringInput;

      cout << "Author's name: ";

      getline(cin, stringInput);
      author[i] = stringInput;

      cout << "Publisher's name: ";

      getline(cin, stringInput);
      publisher[i] = stringInput;

      cout << "Date: ";
      cin >> stringInput;
      cin.ignore();
      dateAdded[i] = stringInput;

      cout << "Quantity of book: ";
      cin >> intInput;
      cin.ignore();
      qtyOnHand[i] = intInput;

      cout << "Wholesale cost: ";
      cin >> doubleInput;
      cin.ignore();
      wholesale[i] = doubleInput;

      cout << "Retail cost: ";
      cin >> doubleInput;
      cin.ignore();
      retail[i] = doubleInput;

      return;
    }
  }
  cout << "Inventory full..." << endl;
}

void editBook() {
  string userBook;
  int index = 0;

  cout << "You selected Edit Book." << endl;
  cout << "Title of book to edit: ";

  getline(cin, userBook);

  index = bookIndex(userBook);

  if (index > -1) {
    // edit book
    // lookupbook called in menu
    editBookMenu(index);

    cout << "Book edited..." << endl;
  } else {
    cout << "Book not in inventory." << endl;
  }
}

void deleteBook() {
  string userBook;
  string tempInput;
  int index = 0;

  cout << "You selected Delete Book." << endl;
  cout << "Title of book to delete: ";

  getline(cin, userBook);

  index = bookIndex(userBook);

  if (index > -1) {
    // delete book
    displayBook(index);
    cout << endl << "Are you sure you want to delete this book? (y/N): ";
    cin >> tempInput;
    cin.ignore();

    if (tempInput == "y") {
      bookTitle[index] = "\0";
      isbn[index] = "\0";

      cout << "Book deleted..." << endl;
    }
  }
}

// custom Function

// return index of book given userBook
// if not found, return -1
int bookIndex(string userBook) {
  for (int i = 0; i < 20; i++) {
    if (bookTitle[i] == userBook) {
      return i;
    }
  }
  return -1;
}

// display all book attributes
// ask which one to edit until user quits
void editBookMenu(int bookIndex) {
  bool exitMenu = false;
  int choice;

  string stringInput;
  double doubleInput;
  int intInput;

  while (exitMenu == false) {
    displayBook(bookIndex);
    cout << endl << endl;
    cout << "1. ISBN" << endl
         << "2. Title" << endl
         << "3. Author" << endl
         << "4. Publisher " << endl
         << "5. Date Added" << endl
         << "6. Quantity-On-Hand " << endl
         << "7. Wholesale Cost " << endl
         << "8. Retail Price " << endl
         << "9. Quit" << endl
         << endl;
    cout << "Which one to edit? (1-9): ";
    cin >> choice;
    cin.ignore();
    switch (choice) {
    case 1:
      if (confirm("ISBN? (y/N): ")) {
        cout << "New value: ";
        cin >> stringInput;
        cin.ignore();

        isbn[bookIndex] = stringInput;
      }
      break;
    case 2:
      if (confirm("Title? (y/N): ")) {
        cout << "New value: ";

        getline(cin, stringInput);

        bookTitle[bookIndex] = stringInput;
      }
      break;
    case 3:
      if (confirm("Author? (y/N): ")) {
        cout << "New value: ";

        getline(cin, stringInput);

        author[bookIndex] = stringInput;
      }
      break;
    case 4:
      if (confirm("Publisher? (y/N): ")) {
        cout << "New value: ";

        getline(cin, stringInput);

        publisher[bookIndex] = stringInput;
      }
      break;
    case 5:
      if (confirm("Date Added? (y/N): ")) {
        cout << "New value: ";
        cin >> stringInput;
        cin.ignore();

        dateAdded[bookIndex] = stringInput;
      }
      break;
    case 6:
      if (confirm("Quantity-On-Hand? (y/N): ")) {
        cout << "New value: ";
        cin >> intInput;
        cin.ignore();

        qtyOnHand[bookIndex] = intInput;
      }
      break;
    case 7:
      if (confirm("Wholesale Cost? (y/N): ")) {
        cout << "New value: ";
        cin >> doubleInput;
        cin.ignore();

        wholesale[bookIndex] = doubleInput;
      }
      break;
    case 8:
      if (confirm("Retail Price? (y/N): ")) {
        cout << "New value: ";
        cin >> doubleInput;
        cin.ignore();

        retail[bookIndex] = doubleInput;
      }
      break;
    case 9:
      exitMenu = true;
      break;
    default:
      cout << "Invalid choice. (1-9)" << endl;
    }
  }
}

// given message output whether "y" or not based on userInput
bool confirm(string message) {
  string userInput;
  cout << message;
  cin >> userInput;
  cin.ignore();

  return userInput == "y";
}

// given book index print out bookInfo()
void displayBook(int bookIndex) {
  bookInfo(isbn[bookIndex], bookTitle[bookIndex], author[bookIndex],
           publisher[bookIndex], dateAdded[bookIndex], qtyOnHand[bookIndex],
           wholesale[bookIndex], retail[bookIndex]);
}