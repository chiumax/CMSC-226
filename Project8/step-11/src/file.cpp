#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

#include "../header_files/all.h"

int writeFile(bookData book) {
  outFile.seekp(0L, ios::end);
  outFile.write(reinterpret_cast<char *>(&book), sizeof(book));
  return outFile.tellp();
}

int writeFile(bookData book, int index) {
  outFile.seekp(sizeof(book) * index, ios::beg);
  outFile.write(reinterpret_cast<char *>(&book), sizeof(book));

  return index;
}

bookData readFile(bookData book) {
  inFile.seekg(0L, ios::beg);
  if (!inFile.eof()) {
    inFile.read(reinterpret_cast<char *>(&book), sizeof(book));
    book.setIndex(inFile.tellg()/sizeof(book))
    return book;
  }
  book.setIndex(-1);
  return book;
}
bookData readFile(bookData book, int index) {
  inFile.seekg(sizeof(book) * index, ios::beg);
  if (!inFile.eof()) {
    inFile.read(reinterpret_cast<char *>(&book), sizeof(book));
    book.setIndex(index);
    return book;
  }
  book.setIndex(-1);
  return book;
}
