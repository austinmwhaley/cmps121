//Author:	    Austin Whaley, APW5450, 2019-03-17
//Class:      CMPSC 121
//Project:    2
//File:       cmpsc121/homework/module_08/M8P2_apw5450.cpp
//Purpose:    Invoice Automation

/********************************************************************\
* Academic Integrity Affidavit:                                      *
* I certify that, this program code is my work.  Others may have     *
* assisted me with planning and concepts, but the code was written,  *
* solely, by me.                                                     *
* I understand that submitting code which is totally or partially    *
* the product of other individuals is a violation of the Academic    *
* Integrity Policy and accepted ethical precepts. Falsified          *
* execution results are also results of improper activities. Such    *
* violations may result in zero credit for the assignment, reduced   *
* credit for the assignment, or course failure.                      *
\********************************************************************/

/*
Write a C++ program to read details of invoices from a file and to output
invoices which indicate the total cost of each item and the total cost of the
invoice together with full details.
*/

#include <iostream>
#include <fstream> //read file
#include <iomanip>
using namespace std;

// Function Prototype
double calcCost(int quantity, double unitcost);
double accTotal(double totalCost, double itemCost);
void printLine(string itemno, string name, int quantity,
               double unitCost, double totalCost);
void printInvoiceHeader(string date);
void printReportHeader();
void printTotal(double invoiceTotal);

// create output file
ofstream fout;

int main() {

  int quantity, items;
  double unitCost, totalCost, itemCost, invoiceCost, invoiceTotal;
  string itemno, name, date;

  // Create and open input file in main
  // Be sure to test to see if you can read the file.
  // If not display a message and end the program.
  fout.open("output.txt");

  ifstream fin;
  fin.open("input.txt");
  if (fin) {
    ;
  } else {
    fout << "ERROR OPENING FILE\n";
    return 1;
  }

  // Read number of items and date.
  // Date can just be a string.
  // This will be the main read loop which will end the program
  // when it encounters end of file

  printReportHeader();

  while (fin >> items >> date) {

    // cout << "items: " << items << " date: " << date << endl; //DEBUG

    invoiceCost = 0;

    printInvoiceHeader(date);

    for (int i=0; i < items; i++) {
      fin >> itemno >> name >> quantity >> unitCost;
      //cout << itemno << name << quantity << unitCost << endl; //DEBUG

      totalCost = calcCost(quantity, unitCost);
      invoiceCost = accTotal(invoiceCost, totalCost);
      printLine(itemno, name, quantity, unitCost, totalCost);
    } // end for-loop

    printTotal(invoiceCost); //291.37
    // break; #DEBUG

  } // end while-loop

  // close file
  fin.close();

  return 0;
}

double calcCost(int quantity, double unitCost) {
  /*
  Operation     : Calculates the cost for a single item.
  Description   : Given the unit price of an item in
                  dollars and cents and the quantity of
                  the item, it calculates the total cost in
                  dollars and cents

  */
  double totalCost;

  totalCost = (quantity * unitCost);
  // cout << "totalCost = " << totalCost << endl; //DEBUG

  return totalCost;
}

double accTotal(double invoiceCost, double totalCost) {
  /*
  Operation     : Accumulates the total cost of invoice
  Description   : Given current total invoice cost and
                  the total cost of an invoice item
                  calculates the new total invoice cost.

  */
  double newTotalCost;

  newTotalCost = invoiceCost + totalCost;
  // cout << "newTotalCost = " << newTotalCost << endl; //DEBUG

  return newTotalCost;
}

void printLine(string itemno, string name, int quantity,
               double unitCost, double totalCost) {
  /*
  Operation     : Writes a line of the invoice.
  Description   : Given the item reference number, the name, the
                  quantity, the unit price and total
                  price of an item, outputs a line of
                  the invoice.

  */
  fout << setprecision(2) << fixed;

  fout << itemno << "\t"\
       << setw(12) << left << name << "\t"\
       << setw(3) << right << quantity << "\t"\
       << setw(7) << right << unitCost << "\t"\
       << setw(8) << right << totalCost << endl;
}

void printInvoiceHeader(string date) {
  /*
  Operation     : Writes “Invoice date: “ and the date to the file
  Description   : Accepts the date and writes Invoice date: followed by the
                  date into the file.
  */

  fout << "Invoice date: " << date << endl;
}

void printReportHeader(){
  /*
  Operation     : Writes “Erie Industrial Supply Corporation” as the first
                  line of the file
  Description   : Displays the company name

  */
  fout << "Erie Industrial Supply Corporation\n";
  //
}

void printTotal(double invoiceTotal) {
  /*
  Operation     : Writes “Total ……………………………………………………………………………” followed
                by the total and then an endl in the file.
  Description   : Accepts the total and writes it followed by a line of dots
                and then the invoice total and an endl
                date into the file.
  */

  fout << "Total …………………………………………………………………………… " << invoiceTotal << endl;
}

/* Execution Sample

*/
