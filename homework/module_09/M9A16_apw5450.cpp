//Author:	    Austin Whaley, APW5450, 2019-03-17
//Class:      CMPSC 121
//Activity:   16
//File:       cmpsc121/homework/module_09/M8A16_apw5450.cpp
//Purpose:    Static Local Variable Usage

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
Write a program with function which uses a static variable to keep track of the
 current balance of a bank account. Do not allow an overdraft!
*/

#include <iostream>

using namespace std;

// Function Prototype
double update_balance(double val);

int main() {

  double val, balance;
  char c;

  do {
    cout << "Please enter number for transaction <(+) = deposit, (-) = withdraw>\n";
    cin >> val;

    balance = update_balance(val);

    cout << "Current Balance = " << balance << endl;

    cout << "Do you have more transactions? <Y or N>\n";
    cin >> c;

  } while (c == 'Y');

  cout << "Thank you and have a good day\n";

  return 0;
}

double update_balance(double val) {

  static double current_balance; //init = 0

  if ( (val < 0) & (current_balance + val < 0) ) {
    cout << "TRANSACTION DENIED: Insufficient Funds\n";
  } else {
    current_balance += val;
  }

  return current_balance;
}


/* Execution Sample
Please enter number for transaction <(+) = deposit, (-) = withdraw>
100
Current Balance = 100
Do you have more transactions? <Y or N>
Y
Please enter number for transaction <(+) = deposit, (-) = withdraw>
-100
Current Balance = 0
Do you have more transactions? <Y or N>
Y
Please enter number for transaction <(+) = deposit, (-) = withdraw>
50
Current Balance = 50
Do you have more transactions? <Y or N>
Y
Please enter number for transaction <(+) = deposit, (-) = withdraw>
-75
TRANSACTION DENIED: Insufficient Funds
Current Balance = 50
Do you have more transactions? <Y or N>
N
Thank you and have a good day
*/
