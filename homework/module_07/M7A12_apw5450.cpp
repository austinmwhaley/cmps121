//Author:	    Austin Whaley, APW5450, 2019-02-24
//Class:      CMPSC 121
//Activity:   12
//File:       cmpsc121/homework/module_07/M7A12_apw5450.cpp
//Purpose:    Creating Functions (Ulam Sequence)

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
1. Ask the user for an integer greater than or equal to 2
2. Pass integer to a function which will produce and display ulam sequence
   2a. Do not accept a number less than 2

Ulam Sequence = begins with an integer. If even divide by 2. If odd, multiply
by 3 and add 1. Continue loop until integer 1 is produced.
*/

#include <iostream>
#include <fstream>

using namespace std;

int ulam(int num) {

  if (num % 2 == 0)
  {
    num /= 2;
  } else {
    num = (num*3)+1;
  }// end if

  cout << num << " ";

  return num;
} // end ulam function

int main() {

  int num;

  cout << "Please enter a number greater than or equal to 2\n";
  cin >> num;

  while (num < 2)
  {
    cout << "ERROR: Please enter a number greater than or equal to 2\n";
    cin >> num;
  } // end while

  cout << "The Ulam sequence starting from " << num << " is: " << num << " ";

  while (num != 1)
  {
    num = ulam(num);
  } // end while

  cout << "\n";
  return 0;

} // end main function



/* Execution Sample
Please enter a number greater than or equal to 2
10
The Ulam sequence starting from 10 is: 10 5 16 8 4 2 1

Please enter a number greater than or equal to 2
20
The Ulam sequence starting from 20 is: 20 10 5 16 8 4 2 1
*/
