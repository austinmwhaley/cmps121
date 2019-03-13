//Author:	    Austin Whaley, APW5450, 2019-02-16
//Class:      CMPSC 121
//Project:    01
//File:       cmpsc121/homework/module_05/M5P1_apw5450.cpp
//Purpose:    North American Wind Chill Index

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
t_wc = temperature w/ wind chill
t_a = temperature actual (f)
V = velocity (mph)

Write a program which varies wind speed from 5 to 45 mph by 5 and temperature
actual from -5 to 50 by 5 and display a table of windchill values

*/

#include <iostream>
#include <cmath> //pow function
#include <iomanip>
using namespace std;

int main() {

  double t_wc, t_a, v;

  cout << setprecision(1) << fixed;

  cout << "Temp: -------------------- Wind Speed --------------------" << endl;
  cout << "\t5\t10\t15\t20\t25\t30\t35\t40\t45" << endl;

  for (t_a=-5; t_a<=50; t_a+=5)
  {
    cout << setw(5) << right << t_a << "\t";

    for (v=5; v<=45; v+=5)
    {

      t_wc = 35.74 + (0.6215*t_a) - (35.75*pow(v, 0.16)) + (0.4275*t_a*pow(v, 0.16)); //works

      cout << setw(5) << right << t_wc << "\t";

      if (v >= 45)
      {
        cout << endl;
      }

    } // end v for loop

  } // end t_a for loop

  return 0;
}

/*
Temp: -------------------- Wind Speed --------------------
	5	10	15	20	25	30	35	40	45
 -5.0	-16.4	-22.1	-25.8	-28.6	-30.8	-32.7	-34.3	-35.7	-37.0
  0.0	-10.5	-15.9	-19.4	-22.0	-24.1	-25.9	-27.4	-28.8	-30.0
  5.0	 -4.6	 -9.7	-13.0	-15.4	-17.4	-19.1	-20.5	-21.8	-23.0
 10.0	  1.2	 -3.5	 -6.6	 -8.9	-10.7	-12.3	-13.6	-14.8	-15.9
 15.0	  7.1	  2.7	 -0.2	 -2.3	 -4.0	 -5.5	 -6.8	 -7.9	 -8.9
 20.0	 13.0	  8.9	  6.2	  4.2	  2.6	  1.3	  0.1	 -0.9	 -1.8
 25.0	 18.9	 15.1	 12.6	 10.8	  9.3	  8.1	  7.0	  6.1	  5.2
 30.0	 24.7	 21.2	 19.0	 17.4	 16.0	 14.9	 13.9	 13.0	 12.2
 35.0	 30.6	 27.4	 25.4	 23.9	 22.7	 21.7	 20.8	 20.0	 19.3
 40.0	 36.5	 33.6	 31.8	 30.5	 29.4	 28.5	 27.7	 26.9	 26.3
 45.0	 42.3	 39.8	 38.2	 37.0	 36.1	 35.3	 34.5	 33.9	 33.3
 50.0	 48.2	 46.0	 44.6	 43.6	 42.8	 42.0	 41.4	 40.9	 40.4
*/



































//
