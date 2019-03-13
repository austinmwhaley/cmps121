//Author:	    Austin Whaley, APW5450, 2019-03-03
//Class:      CMPSC 121
//Activity:   13
//File:       cmpsc121/homework/module_08/M8A13_apw5450.cpp
//Purpose:    Randomly Flipping a coin

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

/* Scrap
Simulate flipping a coin 10 times. End round if landing on 2/H
Payout = 2^n, n = round first 2/H appears
*/

// pg. 129 = random function

#include <iostream>
#include <cstdlib>  // rand function
#include <ctime>    // time function
#include <cmath>    // pow function
#include <iomanip>  //setprecison & fixed

using namespace std;

int main() {

  int max_val=1, min_val=0, cs, c;
  double payout, tot_payout=0, avg_payout=0;

  // Genrate seed for rand via system time
  unsigned seed = time(0);
  srand(seed);

  // Run for 10 iterations
  for (int i = 1; i < 11; i++) {

    // Init counter
    c = 0;

    // Flip count until 1/H
    do {

      // Increment counter
      c += 1;

      // coin_status
      cs = (rand() % (max_val - min_val + 1)) + min_val;

      if (cs == 1) {
        cout << "H";
      } else {
        cout << "T";
      } // end if-statement

    } while (cs != 1); // end do-while loop

    cout << setprecision(2) << fixed;

    payout = pow(2, c);
    cout << "\t You win $" << payout << endl;

    tot_payout += payout;
    avg_payout = (tot_payout)/(static_cast<float>(i));

  } // end for-loop

  cout << "The average payout was $" << avg_payout << endl;

  return 0;
}

/* Execution Sample
TTH	   You win $8.00
TH	   You win $4.00
H	     You win $2.00
H	     You win $2.00
TH	   You win $4.00
H	     You win $2.00
H	     You win $2.00
TTH	   You win $8.00
H	     You win $2.00
TTTTH	 You win $32.00
The average payout was $6.60
*/
