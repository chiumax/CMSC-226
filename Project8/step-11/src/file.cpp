#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

#include "../header_files/all.h"

int writeFile(BookData book) {
    outFile.seekp(0L, ios::end)
    outFile.write(reinterpret_cast<char *>(&book),sizeof(book));
    return outFile.tellp();
}

int writeFile(BookData book, int index){
    outfile.seekp(sizeof(book)*index, ios::beg);
    outFile.write(reinterpret_cast<char *>(&book), sizeof(book));

    return index;
}


int readFile(BookData book) {
    inFile.seekg(0L, ios::beg);
    if(!inFile.eof()){
        inFile.read(reinterpret_case<char *>(&book), sizeof(book));
        return inFile.tellg();
    }
    return -1;
    
}
int readFile(BookData book, int index) {
    inFile.seekg(sizeof(book)*index, ios::beg);
    if(!inFile.eof()){
        inFile.read(reinterpret_case<char *>(&book), sizeof(book));
        return index;
    }
    return -1;
}


