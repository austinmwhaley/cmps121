//Author:	    Austin Whaley, APW5450, 2019-03-03
//Class:      CMPSC 121
//Activity:   14
//File:       cmpsc121/homework/module_08/M8A14_apw5450.cpp
//Purpose:    Code for rolling a 2 dice

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
#include <cstdlib>  // srand & rand function
#include <ctime>    // time function

using namespace std;

int main() {

  int max_val=6, min_val=1, dice1_status, dice2_status;

  // Genrate seed for rand via system time
  unsigned seed = time(0);
  srand(seed);

  // dice_status
  dice1_status = (rand() % (max_val - min_val + 1)) + min_val;
  dice2_status = (rand() % (max_val - min_val + 1)) + min_val;

  cout << "You rolled a [" << dice1_status << "] on dice 1 and a ["\
       << dice2_status << "] on dice 2" << endl;

  return 0;
}

/* Execution Sample
You rolled a [6] on dice 1 and a [2] on dice 2
*/
