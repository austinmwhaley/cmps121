//Author:	    Austin Whaley, APW5450, 2019-04-13
//Class:      CMPSC 121
//Activity:   23
//File:       cmpsc121/homework/module_13/M13A23_apw5450.cpp
//Purpose:    Fun with Arrays

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
#include <ctime>    // time()
#include <cstdlib>  // srand(), rand()

using namespace std;

//Function Prototypes


int main() {

  const int SIZE = 10, MIN = 0, MAX = 10;
  int nums[SIZE] = {5,4,2,7,6,8,5,2,8,14};
  int r, highest=0, sum=0;

  // 1. square each number
  for (int i = 0; i < SIZE; i++) {
    // cout << "Original Number: " << nums[i] << endl; //DEBUG
    nums[i] = nums[i]*nums[i];
    cout << "Squared Number: " << nums[i] << endl; //DEBUG
  }

  // 2. Add a random number between 0 and 10 to each number
  unsigned seed = time(0);
  srand(seed);

  for (int i = 0; i < SIZE; i++) {
    r = (rand() % (MAX - MIN + 1)) + MIN;
    // cout << "Original Number: " << nums[i] << endl; //DEBUG
    // cout << "Random Number: " << r << endl; //DEBUG
    nums[i] = nums[i]+r;
    cout << "Random+Element: " << nums[i] << endl; //DEBUG
  }

  // 3. Add each number to the number that follows
  for (int i = 0; i < SIZE-1; i++) {

    //cout << "This Number: " << nums[i] << endl; //DEBUG
    //cout << "Next Number: " << nums[i+1] << endl; //DEBUG
    nums[i] = nums[i]+nums[i+1];
    cout << "Element+Next Element: " << nums[i] << endl; //DEBUG
  }


  // 4. Calculate the sum of all numbers
  for (int i = 0; i < SIZE; i++) {
    sum += nums[i];
  }
  cout << "Sum: " << sum << endl; //DEBUG

  // 5. Display largest number in array
  for (int i = 0; i < SIZE; i++) {
    if (nums[i] > highest){
      highest = nums[i];
    }
    // cout << "Highest: " << highest << endl; //DEBUG
  }
  cout << "Highest: " << highest << endl; //DEBUG

  return 0;
} // end main

// Functions


/* Execution Sample
Squared Number: 25
Squared Number: 16
Squared Number: 4
Squared Number: 49
Squared Number: 36
Squared Number: 64
Squared Number: 25
Squared Number: 4
Squared Number: 64
Squared Number: 196
Random+Element: 28
Random+Element: 17
Random+Element: 12
Random+Element: 49
Random+Element: 39
Random+Element: 74
Random+Element: 33
Random+Element: 11
Random+Element: 70
Random+Element: 196
Element+Next Element: 45
Element+Next Element: 29
Element+Next Element: 61
Element+Next Element: 88
Element+Next Element: 113
Element+Next Element: 107
Element+Next Element: 44
Element+Next Element: 81
Element+Next Element: 266
Sum: 1030
Highest: 266
*/
