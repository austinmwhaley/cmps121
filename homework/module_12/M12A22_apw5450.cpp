//Author:	    Austin Whaley, APW5450, 2019-04-07
//Class:      CMPSC 121
//Activity:   22
//File:       cmpsc121/homework/module_12/M12A22_apw5450.cpp
//Purpose:    Array Practice

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
#include <cstdlib>  // rand function

using namespace std;

//Function Prototypes

int main() {

  // Initialize and create array
  const int ARRAY_SIZE=50, MIN_VAL=0, MAX_VAL=99999;
  int arr[ARRAY_SIZE], c=1;

  //Fill array of len=50 w. 50 rand ints
  // Genrate seed for rand via system time
  unsigned seed = time(0);
  srand(seed);

  for (int i = 0; i < ARRAY_SIZE; i++) {
    arr[i] = (rand() % (MAX_VAL - MIN_VAL + 1)) + MIN_VAL;
    // cout << arr[i] << endl; //DEBUG
  } //end for-loop

  //Print rand ints in rows of 10
  // iterate over arr and every 10th row endl
  for (int i : arr) {
    cout << i << " ";
    if (c % 10 == 0) {
      cout << endl;
    } // end if-statement
    c++; //haha get it?
  } //end for-loop

  return 0;
} // end main

// Functions

/* Execution Sample
98858 23872 79652 79185 29694 99515 99247 12858 22436 52100
87382 15057 53417 23584 76337 45963 43753 50710 21073 36973
24772 570 22860 76192 19471 87228 70564 92831 51029 57045
61486 66239 80918 41138 45424 26964 57006 44672 39822 79442
13124 43557 10851 82893 67141 87189 28856 10895 54251 49929
*/
