//Author:		Austin Whaley, APW5450, 2019-01-12 12:18
//Class:		CMPSC 121
//Experiment:	01-1
//File:		cmpsc121/experiments/Experiment01-1/L001-apw5450-1.cpp
//Purpose: Lab Part 2

// This program calculates the amout of pay that
// will be contributed to a retirement plan if 5%,
// 7%, or 10% of monthly pay is withheld.

#include <iostream>
using namespace std;

int main()
{
  // Variables to hold the monthly pay and the amount of contribution
  double monthlyPay = 6000.0, contribution;

  // Calculate and dispaly a 5% contribution.
  contribution = monthlyPay * 0.05;
  cout << "5 percent is $" << contribution << " per month. \n";

  // Calculate and display a 7% contribution.
  contribution = monthlyPay * 0.07;
  cout << "7 percent is $" << contribution << " per month.\n";

  // Calculate and display a 10% contribution.
  contribution = monthlyPay * 0.1;
  cout << "10 percent is $" << contribution << " per month.\n";

  return 0;
}

/* Execution Sample
5 percent is $300 per month.
7 percent is $420 per month.
10 percent is $600 per month.
*/
