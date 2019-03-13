//Author:	    Austin Whaley, APW5450, 2019-02-03
//Class:      CMPSC 121
//Experiment: 4
//File:       cmpsc121/experiments/Experiment04/M4E4_apw5450.cpp
//Purpose:    Selection Logic Lab

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
using namespace std;

int main() {

  // Declare variables
  int hours, lap;
  char v_type;
  string v_out;
  double rt_1, rt_2, bill, rt_1_calc, rt_2_calc;

  // hours = hours parked
  // lap = how many hours until second rate takes effect
  // v_type = vehicle type
  // v_out = string output of vehicle type
  // rt_1 & rt_2 = first and second rate
  // bill = final amount due
  // rt_1_calc and rt_2_calc = store intermediate calculations for bill

  // Prompt user for input
  cout << "Please enter vechicle type <C=Car, T=Truck, B=Bus> and hours parked:\n";

  // Gather user input
  cin >> v_type >> hours;

  // Set switch for v_type for later evaluation for bill
  switch(v_type) {
    case 'C':

      v_out = "Car";
      rt_1 = 1.25;
      rt_2 = 1.50;
      lap = 2;
      break;

    case 'T':

      v_out = "Truck";
      rt_1 = 2.75;
      rt_2 = 3.75;
      lap = 2;
      break;

    case 'B':

      v_out = "Bus";
      rt_1 = 9.50;
      rt_2 = 6.75;
      lap = 1;
      break;
  }

  // Bill Calculation
  if (hours > lap){
    rt_1_calc = lap * rt_1;
    rt_2_calc = (hours-lap) * rt_2;
    bill = rt_1_calc + rt_2_calc;
  } else {
    bill = hours * rt_1;
  }

  // Receipt
  cout << "Crunchum Parking Lots, Inc\n";
  cout << "\"We usually find your vehicle!\"\n";
  cout << "===================================\n";
  cout << "Vehicle Type: \t" << v_out << endl;
  cout << "Time: \t\t" << hours << " Hours\n";
  cout << "Amount Due: \t" << '$' << bill << endl;
  cout << "===================================\n";

  return 0;
}

/* Execution Sample (C 7)
Please enter vechicle type <C=Car, T=Truck, B=Bus> and hours parked:
C 7
Crunchum Parking Lots, Inc
"We usually find your vehicle!"
===================================
Vehicle Type: 	Car
Time: 		      7 Hours
Amount Due: 	  $10
===================================
*/

/* Execution Sample (T 10)
Please enter vechicle type <C=Car, T=Truck, B=Bus> and hours parked:
T 10
Crunchum Parking Lots, Inc
"We usually find your vehicle!"
===================================
Vehicle Type: 	Truck
Time: 		      10 Hours
Amount Due: 	  $35.5
===================================
*/

/* Execution Sample (B 8)
B 8
Crunchum Parking Lots, Inc
"We usually find your vehicle!"
===================================
Vehicle Type: 	Bus
Time: 		      8 Hours
Amount Due: 	  $56.75
===================================
*/
