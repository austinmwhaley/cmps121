//Author:		Austin Whaley, APW5450, 2019-01-19
//Class:		CMPSC 121
//Homework:	Activity 3
//File:		cmpsc121/homework/module_02/M2A3-apw5450.cpp
//Purpose:  Display average of 5 numbers

/*
Write a program that will ask the user to enter 5 integers, read them in and display their average. Average should be a double.
A typical run would be:
Enter 5 integers: 3 8 9 6 7  The average is 6.6
Do a complete program and run it in a lab or on your own computer, put the .cpp file in the dropbox, with an execution sample as a comment at the end.
*/

#include <iostream>
using namespace std;

int main()
{
  // Declare variables
  short int int_1, int_2, int_3, int_4, int_5;
  double average;

  // Prompt user for input
  cout << "Please enter 5 integers seperated by spaces: ";

  // Collect user input
  cin >> int_1 >> int_2 >> int_3 >> int_4 >> int_5;

  // Evaluate average of 5 inputs
  average = (int_1 + int_2 + int_3 + int_4 + int_5)/ 5.0;

  // Display average value
  cout << "The average is " << average << endl;

  // return 0 if successful
  return 0;

}

/* Execution Sample

Please enter 5 integers seperated by spaces: 1 2 3 4 6
The average is 3.2

*/
