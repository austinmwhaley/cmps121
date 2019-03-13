//Author:	    Austin Whaley, APW5450, 2019-02-03
//Class:      CMPSC 121
//Activity:   6
//File:       cmpsc121/homework/module_04/M4A6_apw5450.cpp
//Purpose:    Magic year evaluation

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

#include <iostream>
using namespace std;

int main() {

  // Variable declaration
  int month, day, year;

  // Prompt user for input
  cout << "Please enter a numeric month, day, and two digit year, separated by spaces:\n";

  // Collect input
  cin >> month >> day >> year;

  // Evaluate if it is a magic year
  if ( (month * day) == year ){
    cout << "It's a MAGIC date!\n";
  } else {
    cout << "Sorry, not a magic date\n";
  }

  return 0;
}

/* Execution Sample
Please enter a numeric month, day, and two digit year, separated by spaces:
8 2 16
It's a MAGIC date!
*/

/* Execution Sample 2
Please enter a numeric month, day, and two digit year, separated by spaces:
8 2 16
It's a MAGIC date!
*/
