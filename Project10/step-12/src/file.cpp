#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

#include "../header_files/all.h"

int writeFile(bookData book) {
  file.clear();
  file.seekp(0L, ios::end);
  book.setIndex(file.tellp() / sizeof(book));
  file.write(reinterpret_cast<char *>(&book), sizeof(book));
  file.flush();
  return file.tellp();
}

int writeFile(bookData book, int index) {
  file.clear();
  file.seekp(sizeof(book) * index, ios::beg);
  book.setIndex(index);
  file.write(reinterpret_cast<char *>(&book), sizeof(book));
  file.flush();

  return index;
}

bookData readFile(bookData book) {
  file.clear();
  file.seekg(0L, ios::beg);
  if (!file.eof()) {
    file.read(reinterpret_cast<char *>(&book), sizeof(book));
    return book;
  }
  book.setIndex(-1);
  return book;
}
bookData readFile(bookData book, int index) {
  file.clear();
  file.seekg(sizeof(book) * index, ios::beg);
  if (!file.eof()) {
    file.read(reinterpret_cast<char *>(&book), sizeof(book));
    return book;
  }
  cout << "error";
  book.setIndex(-1);
  return book;
}

int totalIndex() {
  file.seekp(0L, ios::end);
  return file.tellp() / sizeof(book);
}
