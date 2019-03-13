//Author:	    Austin Whaley, APW5450, 2019-02-03
//Class:      CMPSC 121
//Activity:   7
//File:       cmpsc121/homework/module_04/M4A7_apw5450.cpp
//Purpose:    Mobile Service Provider

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

  // Declare variables
  char plan;
  int minutes, allotment;
  double base, overage, overage_fee;

  // Prompt user for input
  cout << "Enter Plan <A, B, or C> and number of minutes used this month:\n";

  // Gather input
  cin >> plan >> minutes;

  // Switch will be used to set variable values for bill evaluation later
  switch(plan) {
    case 'A':
      cout << "For Package A with " << minutes << " minutes of usage, your bill is: ";

      base = 39.99;
      allotment = 450;
      overage_fee = 0.45;

      break;

    case 'B':
      cout << "For Package B with " << minutes << " minutes of usage, your bill is: ";

      base = 59.99;
      allotment = 900;
      overage_fee = 0.40;

      break;
      
    case 'C':
      cout << "For Package C with " << minutes << " minutes of usage, your bill is: ";

      base = 69.99;
      allotment = (minutes + 1); //Unlimited

      break;
  }

  // From switch output above, evaluate bill
  if (minutes > allotment){

    minutes = minutes - allotment;
    overage = minutes * overage_fee;

    cout << "$" << (base + overage) << endl;
  } else {
    cout << "$" << base << endl;
  }

  return 0;
}

/* Execution Sample
A 451
For Package A with 451 minutes of usage, your bill is: $40.44
*/
