//Author:	    Austin Whaley, APW5450, 2019-01-27
//Class:      CMPSC 121
//Experiment: 03
//File:       cmpsc121\experiments\Experiment03/M3E3_2_apw5450.cpp
//Purpose:    Evaluate torque and diameter of a shaft

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

int main()
{
  double D, T, S, P, N;

  // 20 1500 5000      // Sample Input 1 //Success
  // 20 50 5000        // Sample Input 2 //Success
  // 270 40 6500       // Sample Input 3
  cout << "Enter values for horsepower(P), rpm(n), and shear strength(s)" << endl;
  cin >> P >> N >> S;

  // Set precison to 3 and display in fixed point notation for floating-point values
  cout << setprecision(3) << fixed;

  // Evaluate T and D
  T = 63000*(P/N);
  D = pow((16*T)/S, 0.333);

  // Header Text
  cout << "P(HP)\t\t N(rpm)\t\t S(psi)\t\t T(torque)\t D(diameter)" << endl;

  // Values element-wise below
  cout << left << setw(9) << P << "\t "\
       << left << setw(9) << N << "\t "\
       << left << setw(9) << S << "\t "\
       << left << setw(9) << T << "\t "\
       << left << setw(9) << D << "inches\n";

  return 0;
}

/* Execution Sample 1
Enter values for horsepower(P), rpm(n), and shear strength(s)
20 1500 5000
P(HP)		 N(rpm)		 S(psi)		 T(torque)	 D(diameter)
20.000	 1500.000	 5000.000	 840.000	   1.390  inches
*/

/* Execution Sample 2
Enter values for horsepower(P), rpm(n), and shear strength(s)
20 50 5000
P(HP)		 N(rpm)		 S(psi)		 T(torque)	 D(diameter)
20.000   50.000    5000.000  25200.000	 4.314    inches
*/

/* Execution Sample 3
Enter values for horsepower(P), rpm(n), and shear strength(s)
270 40 6500
P(HP)		 N(rpm)		 S(psi)		 T(torque)	 D(diameter)
270.000  40.000    6500.000  425250.000	 10.130   inches
*/
