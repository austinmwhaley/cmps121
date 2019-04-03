//Author:	    Austin Whaley, APW5450, 2019-03-24
//Class:      CMPSC 121
//Activity:   17
//File:       cmpsc121/homework/module_10/M10A17_apw5450.cpp
//Purpose:    Longest Pole for Room

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
Write a program with a function which will ask for the length, width and height
of a room and then pass that data to another function which will calculate and
display the length of the longest pole which will fit in that room. That pole
would run diagonally across the room from an upper corner to a lower
These will both be void functions. The first one will use reference parameters.
*/

#include <iostream>
#include <cmath> //sqrt
#include <iomanip> //setprecision

using namespace std;

//Function Prototypes
void user_input(int &, int &, int &);
void long_diag(int length, int width, int height);

int main() {

  int length, width, height;
  double pole_length;

  user_input(length, width, height);
  long_diag(length, width, height);

  return 0;
}

// Functions
void user_input(int &ref_length, int &ref_width, int &ref_height) {
  cout << "Please enter the length, width, & height of the room:\n";
  cin >> ref_length >> ref_width >> ref_height;
}

void long_diag(int length, int width, int height) {

  double pole_length;

  pole_length = sqrt( pow(length, 2) + pow(width, 2) + pow(height, 2) );

  cout << setprecision(2) << fixed;

  cout << "The longest pole that can fit in the room is: " << pole_length << endl;

}

/* Execution Sample
Please enter the length, width, & height of the room:
10 8 5
The longest pole that can fit in the room is: 13.75
*/
