//Author:	    Austin Whaley, APW5450, 2019-02-24
//Class:      CMPSC 121
//Experment:  07
//File:       cmpsc121/experiments/Experiment07/M7E7_apw5450.cpp
//Purpose:    AMSCO Fleet Report

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
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main() {

  string v_id, max_v_id, min_v_id;
  double miles, gallons, mpg, total_miles, count=0.0,
         max_mpg=-1, min_mpg=1000, avg_mpg=0, total_mpg=0;

  cout << "AMSCO Fleet Report\n";
  cout << "Vehicle ID\tMiles\tGallons\tMPG\n";
  cout << "----------------------------------------\n";

  ifstream input_file("FleetInput.txt");

  cout << setprecision(2) << fixed;

  while (input_file >> v_id >> miles >> gallons)
  {

    mpg = miles/gallons;
    total_mpg += mpg;

    cout << v_id << "\t" << miles << "\t" << gallons << "\t" << mpg << endl;

    count += 1.0;
    total_miles += miles;
    avg_mpg = total_mpg/count;

    if (mpg > max_mpg)
    {
      max_mpg = mpg;
      max_v_id = v_id;
    } // end max if

    if (mpg < min_mpg)
    {
      min_mpg = mpg;
      min_v_id = v_id;
    } // end min if

  } // end while

  cout << "----------------------------------------\n";
  cout << "Count:\t\t"     << count       << endl;
  cout << "Total Miles:\t" << total_miles << endl;
  cout << "Average MPG:\t" << avg_mpg     << endl;
  cout << "Vehicle ID with Best MPG: " << max_v_id << "\t" << max_mpg << endl;
  cout << "Vehicle ID with Worst MPG: " << min_v_id << "\t" << min_mpg << endl;

  return 0;
}

/* Execution Sample
AMSCO Fleet Report
Vehicle ID	Miles	Gallons	MPG
----------------------------------------
279BX6KY2Z	582.20	20.50	28.40
802MX8BZ4Q	723.60	25.10	28.83
671AY6DZ3N	756.90	27.50	27.52
845DH6AJ3B	660.20	25.40	25.99
566GJ6KV2U	510.20	30.80	16.56
109QW2RP2Y	301.20	8.30	36.29
135TR4YC6H	387.60	12.20	31.77
122AC6UG7P	228.90	14.70	15.57
136VW8TD2Z	331.20	19.10	17.34
448WQ2DX1M	543.90	33.60	16.19
721GZ1LJ5N	629.80	27.90	22.57
779FS3MB4Y	651.20	28.40	22.93
553SB5LK8O	444.40	26.80	16.58
----------------------------------------
Count:		    13.00
Total Miles:	6751.30
Average MPG:	23.58
Vehicle ID with Best MPG: 109QW2RP2Y	36.29
Vehicle ID with Worst MPG: 122AC6UG7P	15.57

*/
