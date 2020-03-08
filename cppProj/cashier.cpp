#include <iostream>
#include <iomanip>
#include <string>

using namespace std;



int main() {
string date;
    int bookQuantity;
    string ISBN;
    string bookTitle;
    double price;

    const double TAX_RATE = 0.06;
    double salesTax;
    double subtotal;
    double total;
    
 

    cout << "Serendipity Booksellers" <<endl
        << "Cashier Module" <<endl
        << endl;

    cout << "Date: ";
    cin >> date;

    cout << "Quantity of Book: ";
    cin >> bookQuantity;

    cout << "ISBN: ";
    cin >> ISBN;

    cout << "Title: ";
    cin >> bookTitle;

    cout << "Price: ";
    cin >> price;


  // header 
  cout << "Serendipity Book Sellers" << endl
      << "Date: " << endl
      << setw(6) << "Qty" << setw(8) << "ISBN" << setw(20) << "Title" << setw(15) << "Price" << setw(15) << "Total" << endl
      << setfill('_') << setw(100) << ""<< endl << setfill (' ');

  // Content
    subtotal = bookQuantity*price;
    salesTax = subtotal*TAX_RATE;
    total = salesTax+subtotal;

    cout << setw(6) <<fixed<< bookQuantity << setw(8) << ISBN << setw(20) << bookTitle << setw(15) << setprecision(2) << price << setw(15) << price*bookQuantity << endl;
  //
  // footer
  cout << setw(10) << ""<<setw( 20 ) << left << "Subtotal"<<setw(50)<<right<< subtotal << endl 
      << setw(10) << "" <<setw(20) << left << "Tax"<<setw(50)<<right <<salesTax<< endl
      << setw(10) << "" <<setw(20) << left << "Total"<<setw(50)<<right<<total << endl
      << "Thank You for Shopping at Serendipity!" <<endl;


}

