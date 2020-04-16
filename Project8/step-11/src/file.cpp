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

int readFile(bookData book) {
  inFile.seekg(0L, ios::beg);
  if (!inFile.eof()) {
    inFile.read(reinterpret_cast<char *>(&book), sizeof(book));
    return inFile.tellg();
  }
  return -1;
}
int readFile(bookData book, int index) {
  inFile.seekg(sizeof(book) * index, ios::beg);
  if (!inFile.eof()) {
    inFile.read(reinterpret_cast<char *>(&book), sizeof(book));
    book return index;
  }
  return -1;
}
