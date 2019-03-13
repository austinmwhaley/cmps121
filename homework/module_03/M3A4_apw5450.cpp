//Author:	    Austin Whaley, APW5450, 2019-01-27
//Class:      CMPSC 121
//Activity:   04
//File:       cmpsc121\homework\module_03/M3A4_apw5450.cpp
//Purpose:    Fahrenheit -> Celsius Converter

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

// Write a program which reads in a temperature in Fahrenheit and
// displays it in Celsius. You can find the appropriate formula on the web.
// Hint: Integer division does NOT give accurate answers!

#include <iostream>

using namespace std;

int main()
{
  // declare variables
  double f_tmp, c_tmp;

  // prompt user for input
  cout << "Please enter the current temperature in Fahrenheit: ";

  // gather user input and store
  cin >> f_tmp;

  // formula for conversion with sample io
  //(32°F − 32) × 5/9 = 0°C
  //(65 - 32) * 5/9 = 18.3333

  // perform conversion
  // Hint: Integer division does NOT give accurate answers!
  c_tmp = (f_tmp - 32) * 5/9;
  // c_tmp = static_cast<int>(c_tmp); // see below note

  // formula from above above displays the correct answer however
  // if it needs to be an int (unclear from instructions) you
  // could use line 46

  cout << "The temperature in Celsius = " << c_tmp << endl;

  return 0;
}

/* Execution Sample

Please enter the current temperature in Fahrenheit: 65
The temperature in Celsius = 18.3333

OR

Please enter the current temperature in Fahrenheit: 65
The temperature in Celsius = 18


*/
