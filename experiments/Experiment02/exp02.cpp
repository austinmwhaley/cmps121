//Author:	    Austin Whaley, APW5450, 2019-01-19
//Class:      CMPSC 121
//Experiment: 02
//File:       cmpsc121\experiments\Experiment02/exp02.cpp
//Purpose:    Division modulus division.

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

int main()
{

  // Variable Definitions
  double tendered;
  double cost;
  int change;
  int fifties, twenties, tens, fives, dollars, quarters, dimes, nickles, pennies;

  // Prompt user for input and collect input
  cout << "Enter amount of purchase and amount tendered: ";
  cin >> cost >> tendered;

  // Display input information
  cout << "For your purchase of $" << cost << " you tendered $" << tendered << endl;

  // starting change in cents
  change = (tendered - cost) * 100;

  // Display change in dollars
  cout << "Your change is $" << change/100.00 << endl;

  // Evaluate change denominations in cents
  fifties  =   change / (50*100);
  change   =   change % (50*100);

  twenties =   change / (20*100);
  change   =   change % (20*100);

  tens     =   change / (10*100);
  change   =   change % (10*100);

  fives    =   change / (5*100);
  change   =   change % (5*100);

  dollars  =   change / (1*100);
  change   =   change % (1*100);

  quarters =   change / 25;
  change   =   change % 25;

  dimes    =   change / 10;
  change   =   change % 10;

  nickles  =   change / 5;
  change   =   change % 5;

  pennies  =   change / 1;
  change   =   change % 1;

  // Display denominations
  cout << "Fifties:\t"  << fifties  << endl;
  cout << "Twenties:\t" << twenties << endl;
  cout << "Tens:\t\t"   << tens     << endl;
  cout << "Fives:\t\t"  << fives    << endl;
  cout << "Dollars:\t"  << dollars  << endl;
  cout << "Quarters:\t" << quarters << endl;
  cout << "Dimes:\t\t"  << dimes    << endl;
  cout << "Nickles:\t"  << nickles  << endl;
  cout << "Pennies:\t"  << pennies  << endl;

  return 0;
}

/* Execution Sample

Enter amount of purchase and amount tendered: 2.08 100.00
For your purchase of $2.08 you tendered $100
Your change is $97.92
Fifties:	1
Twenties:	2
Tens:		  0
Fives:		1
Dollars:	2
Quarters:	3
Dimes:		1
Nickles:	1
Pennies:	2

*/
