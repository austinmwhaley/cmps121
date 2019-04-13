//Author:	    Austin Whaley, APW5450, 2019-04-07
//Class:      CMPSC 121
//Experiment: 12
//File:       cmpsc121/experiments/Experiment12/M12E12_apw5450.cpp
//Purpose:    Develop confidence with structs

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
You have been tasked with writing a program to generate
a quarterly sales report for your company
*/

#include <iostream>
#include <fstream> //files
#include <string>
#include <iomanip> //setprecision

using namespace std;

// Structs
struct Invoice {
  string invoice_num;
  char equip_code;
  double cost;
};

//Function Prototypes
void accumulate(const Invoice &i, double &a, double &b, double &c);
void writeReport(double a, double b, double c);

int main() {

  Invoice i;
  double a, b, c;

  // Read in file contents to struct
  ifstream input_file("sales.txt");

  while (input_file >> i.invoice_num >> i.equip_code >> i.cost) {
    // Pass struct and three accumulator variables to function for lines in file
    accumulate(i, a, b, c);
  };

  // writeReport() function (writes report to text file)
  writeReport(a, b, c);

  return 0;
} // end main

// Functions
void accumulate(const Invoice &i, double &a, double &b, double &c) {
  switch(toupper(i.equip_code)) {
    case 'A': a+=i.cost;
              break;
    case 'B': b+=i.cost;
              break;
    case 'C': c+=i.cost;
              break;
  }
} // end function

void writeReport(double a, double b, double c) {

  cout << setprecision(2) << fixed;
  ofstream output_file("inventoryReport.txt");
  double total;

  total = a+b+c;

  output_file << "---------- SALES REPORT ----------\n";
  output_file << "CAPITAL EQUIPMENT\t$" << a << "\t" << (a/total)*100 << "%" << endl;
  output_file << "EXPENSED EQUIPMENT\t$" << b << "\t" << (b/total)*100 << "%" << endl;
  output_file << "SMALL PARTS\t\t$" << c << "\t" << (c/total)*100 << "%" << endl;
  output_file << "\t\t\t----------\n";
  output_file << "TOTAL SALES\t\t$" << total << endl;
} // end function

/* Execution Sample
---------- SALES REPORT ----------

CAPITAL EQUIPMENT       $24093.18       26.31%
EXPENSED EQUIPMENT      $22222.80       24.27%
SMALL PARTS             $45251.98       49.42%
                        ----------
TOTAL SALES             $91567.96
*/
