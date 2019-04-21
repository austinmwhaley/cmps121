//Author:	    Austin Whaley, APW5450, 2019-04-13
//Class:      CMPSC 121
//Activity:   24
//File:       cmpsc121/homework/module_13/M13A24_apw5450.cpp
//Purpose:    Fun with Vectors

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
Write program using parallel vectors and a function which fills each of them
with 500 random numbers between 1 and 100.

Then pass both vectors to a function which will return an integer indicating
a count of how many times both vectors had even number in the same location
*/

#include <iostream>
#include <vector>
#include <ctime>    // time()
#include <cstdlib>  // srand(), rand()

using namespace std;

//Function Prototypes
int count_even_in_same_position(vector<int>, vector<int>);

int main() {

  const int MIN = 1, MAX = 100;
  vector<int> parallel_1(500, 0); //Initialize 500 elements of 0
  vector<int> parallel_2(500, 0); //Initialize 500 elements of 0
  int r, count;

  unsigned seed = time(0);
  srand(seed);

  for(int i = 0; i < 500; i++){
    r = (rand() % (MAX - MIN + 1)) + MIN;
    parallel_1[i] = r;
    r = (rand() % (MAX - MIN + 1)) + MIN;
    parallel_2[i] = r;
  }

  //cout << "Size parallel_1: " << parallel_1.size() << endl; //DEBUG
  //cout << "Size parallel_2: " << parallel_2.size() << endl; //DEBUG

  count = count_even_in_same_position(parallel_1, parallel_2);

  cout << "The Vector contains " << count << " elements where both values are even" \
       << endl;

  return 0;
} // end main

// Functions
int count_even_in_same_position(vector<int> p1, vector<int> p2){
  int count=0;

  for (int i = 0; i < p1.size(); i++){
    if (p1[i]%2==0 && p2[i]%2==0){
      count+=1;
    } // end if-statement
  } // end for-loop

  return count;
}

/* Execution Sample
The Vector contains 130 elements where both values are even
*/
