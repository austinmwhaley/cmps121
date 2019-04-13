//Author:	    Austin Whaley, APW5450, 2019-04-07
//Class:      CMPSC 121
//Activity:   21
//File:       cmpsc121/homework/module_12/M12A21_apw5450.cpp
//Purpose:    Write Struct Part data to file (append)

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

*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Part
{
  string number;
  string name;
  char c;
  int stock;
  double unit_price;
};

//Function Prototypes
void write_part(Part);

int main() {

  char cont;
  Part p;

  do {
    cout << "Please enter part number, name, class, num in stock and unit price\n";
    cin >> p.number >> p.name >> p.c >> p.stock >> p.unit_price;

    write_part(p);

    cout << "Continue?\n";
    cin >> cont;
  } while (toupper(cont) == 'Y'); // end do-while loop

  return 0;
} // end main

// Functions
void write_part(Part s){

  ofstream output_file;
  output_file.open("output.txt", ios::app); //append parameter

  // output data to global var "output_file"
  output_file << s.number << " ";
  output_file << s.name << " ";
  output_file << s.c << " ";
  output_file << s.stock << " ";
  output_file << s.unit_price << " ";
  output_file << endl;

  output_file.close();

}// end function

// P-14376 Widget B 120 34.95
/* Execution Sample
Please enter part number, name, class, num in stock and unit price
P-14376 Widget B 120 34.95
Continue?
y
Please enter part number, name, class, num in stock and unit price
P-14376 Widget B 120 34.95
Continue?
n
*/
