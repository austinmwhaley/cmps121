//Author:	    Austin Whaley, APW5450, 2019-03-03
//Class:      CMPSC 121
//Experiment: 08
//File:       cmpsc121/experiments/Experiment08/M7A15_apw5450.cpp
//Purpose:    Develop Confidence with random numbers

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
Out = 58.0
Walk = 9.70
Single = 22.0
Double = 6.1
Triple = 2.5
Home Run = 1.7

- Based on the above percentages, write a program to simulate Casey stepping up
to the plate 1000 times and count and display the number of categories.
- Then calculate and display his batting average
- Enclose login in a do-while loop asking the user if they want to continue
<Y or N> (run another simulation)
- Run and capture at least 2 simulations
*/

#include <iostream>
#include <cstdlib>  // srand & rand function
#include <ctime>    // time function

using namespace std;

int main() {

  unsigned seed = time(0);
  srand(seed);

  double batting_avg;
  int min_val=0, max_val=1000, s, out, walk, single, doubl, triple, homerun;
  char conf;

  // Simulation
  do {

    // Reset initial values
    out     =0;
    walk    =0;
    single  =0;
    doubl   =0;
    triple  =0;
    homerun =0;

    for (int i=0; i < 1000; i++) {

      s = (rand() % (max_val - min_val + 1)) + min_val;

      if (s >= 0 && s <= 580) {
        out += 1;

      } else if (s > 580 && s <= 677) {
        walk += 1;

      } else if (s > 677 && s <= 897) {
        single += 1;

      } else if (s > 897 && s <= 958) {
        doubl += 1;

      } else if (s > 958 && s <= 983) {
        triple += 1;

      } else {
        homerun += 1;

      } // end if-tree
    } // end for-loop

    batting_avg = static_cast<float>(single + doubl + triple + homerun)/
                  static_cast<float>(1000 - walk);

    cout << "Outs = "        << out         << endl;
    cout << "Walks = "       << walk        << endl;
    cout << "Singles = "     << single      << endl;
    cout << "Doubles = "     << doubl       << endl;
    cout << "Triples = "     << triple      << endl;
    cout << "Home Runs = "   << homerun     << endl;
    cout << "Batting AVG = " << batting_avg << endl;

    cout << "Do you have another purchase to enter? <Y or N> " << endl;
    cin >> conf;

  } while (conf == 'Y'); // end do-while loop

  return 0;
} // end main


/* Execution Sample
Outs = 607
Walks = 105
Singles = 192
Doubles = 58
Triples = 24
Home Runs = 14
Batting AVG = 0.321788
Do you have another purchase to enter? <Y or N>
Y
Outs = 589
Walks = 95
Singles = 217
Doubles = 61
Triples = 24
Home Runs = 14
Batting AVG = 0.349171
Do you have another purchase to enter? <Y or N>
Y
Outs = 561
Walks = 85
Singles = 235
Doubles = 82
Triples = 20
Home Runs = 17
Batting AVG = 0.386885
Do you have another purchase to enter? <Y or N>
N
*/
