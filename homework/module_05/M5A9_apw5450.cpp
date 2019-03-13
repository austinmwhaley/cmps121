//Author:	    Austin Whaley, APW5450, 2019-02-10
//Class:      CMPSC 121
//Activity:   9
//File:       cmpsc121/homework/module_05/M5A9_apw5450.cpp
//Purpose:    Sum even digits in given input over 10,000

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

  int num, working_num, sum = 0, digit;

  // prompt and save user input
  cout << "Please enter an integer greater than 10,000: ";
  cin >> num;

  // confirm user input is w/in params
  while (num < 10000)
  {
    cout << num << " is not greater than 10,000\n";
    cout << "Please enter an integer greater than 10,000: ";
    cin >> num;
  }

  // save num for later use
  working_num = num;

  // sum even digits in workin_num
  while (working_num != 0)
  {
    digit = (working_num%10);

    if (digit%2 == 0)
    {
      sum += digit;
    }

    working_num /= 10;
  }

  cout << "The sum of the even digits of " << num << " is: " << sum << endl;

  return 0;

}

// 39428

/* Execution Sample
Please enter an integer greater than 10,000: 22
22 is not greater than 10,000
Please enter an integer greater than 10,000: 22222
The sum of the even digits of 22222 is: 10
*/
