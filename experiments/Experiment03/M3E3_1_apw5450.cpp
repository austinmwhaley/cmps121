//Author:	    Austin Whaley, APW5450, 2019-01-27
//Class:      CMPSC 121
//Experiment: 03
//File:       cmpsc121\experiments\Experiment03/M3E3_1_apw5450.cpp
//Purpose:    Evaluate volume and surface area of a ring

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
#include <iomanip>
#include <cmath>
using namespace std;

const double PI = 3.14159;

int main()
{
  // r_ring = radius of ring
  // r_x = radius of cross-section

  double r_ring, r_x, volume, surface_area;

  // Volume = V = 2 π^2Rr^2
  // Surface Area = S = 4 π2Rr

  // 25.75 3      //Sample Input
  // 29.99 4      //Exe Input
  cout << "Enter radius of ring and radius of cross section " << endl;
  cin >> r_ring >> r_x;

  cout << "For a ring with a radius of " << r_ring << " and a cross section radius of "\
       << r_x << endl;

  cout << setprecision(3) << fixed;

  // Volume
  volume = (2.0)*pow(PI, 2.0)*r_ring*(pow(r_x, 2.0));
  cout << "The volume is: \t\t" << volume << endl;

  // Surface Area
  surface_area = (4.0)*pow(PI, 2.0)*r_ring*r_x;
  cout << "The surface area is: \t" << surface_area << endl;

  return 0;
}

/* Execution Sample

Enter radius of ring and radius of cross section
29.99 4
For a ring with a radius of 29.99 and a cross section radius of 4
The volume is: 		    9471.646
The surface area is: 	4735.823

*/
