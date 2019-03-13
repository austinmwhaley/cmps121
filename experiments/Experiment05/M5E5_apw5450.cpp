//Author:	    Austin Whaley, APW5450, 2019-02-10
//Class:      CMPSC 121
//Experiment: 5
//File:       cmpsc121/experiments/Experiment05/M5E5_apw5450.cpp
//Purpose:    Develop confidence with selection logic and debugging

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

// Fix exe errors - fixed
// Send screenshots of the code (just use cout) - done
// Write Zippy Cell Phone Company script

//Caution, this program contains intentional errors!
// #include <iostream>
// #include <string> //renamed to string
// #include <iomanip> //added for setprecision
//
// using namespace std;
//
// const int LT20 = 20;
// const double LT20Charge = 0.10;
// const int LT40 = 20;
// const double LT40Charge = 0.08;
// const int LT60 = 60; //misnammed variable
// const double LT60Charge = 0.06;
// const double GTE60Charge = 0.04;
// const double BALANCELIMIT = 400.00;
// const double LOWBALANCECHARGE = 15.00;
//
// int main()
// {
// 	int numberOfChecks;
// 	bool isUnder = false;
// 	double balance, serviceFee = 0, checkCharge;
// 	cout << fixed << setprecision(2);
//
//   // fixed spacing
// 	cout << "Please enter beginning balance and number of checks written" << endl;
// 	cin  >> numberOfChecks >> balance;
//
// 	if (balance < BALANCELIMIT)
// 	{
// 		serviceFee + LOWBALANCECHARGE;
// 		isUnder = true;
//     cout << isUnder << " <- isUnder Val\n"; //DEBUG
// 	}
//
//   // missing curly braces
// 	if (numberOfChecks < LT20)
//   {
//     serviceFee += (LT20Charge * numberOfChecks);
//   }
// 	else if (numberOfChecks < LT40)
// 	{
//     serviceFee += (LT40Charge * numberOfChecks);
//   }
// 	else if (numberOfChecks < LT60)
// 	{
//     serviceFee += (LT60Charge * numberOfChecks);
//   }
// 	else
//   {
//     serviceFee += (GTE60Charge * numberOfChecks);
//   }
//
//   cout << serviceFee << " <- serviceFee Val\n"; //DEBUG
//
// 	cout << "MEGABUX Bancorp" << endl; //renamed end1
// 	cout << "Your balance was " << balance << endl; //renamed balnce
//
//   //added missing quote and spacing
// 	if (isUnder)
// 	{
// 		cout << "You did not maintain the minimum balance!"  << endl;
// 		cout << "You incurred a fee of $" << LOWBALANCECHARGE << endl;
// 	}
// 	cout << "Total service Charge = $" << serviceFee << endl;
//
// }

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

  string act_num, p_out;
  char plan;
  int d_min, n_min;
  double total=0.00;

  if (total !> 0){
    cout << "True"
  }

  // prompt and gather user input
  cout << "Please enter account number and service Code <s or p>\n";
  cin >> act_num >> plan;

  cout << "Please enter daytime minutes and nighttime minutes:\n";
  cin >> d_min >> n_min;

  // Standard = flat 12 plus .20 p/min after 60min

  // Premium = flat 25 plus .10 p/min for daytime after 75 min
  // and .05 p/min for nighttime after 100 min

  // Plan and Total Evaluation
  if (plan == 'P' || plan == 'p')
  {
    p_out = "PREMIUM";
    total += 25;
    if (d_min > 75)
    {
      total += (d_min-75)*.10;
    }

    if (n_min > 100)
    {
      total += (n_min-100)*.05;
    }
  }
  else if (plan == 'S' || plan == 's')
  {
    p_out = "STANDARD";
    total += 12;
    if ((d_min+n_min) > 60)
    {
      total += ((d_min+n_min)-100)*.20;
    }
  }
  else
  {
    cout << "Input Error\n";
  }

  // Output
  cout << setprecision(2) << fixed;

  cout << "---------Zippy Cell Phone Company---------\n";
  cout << "Service Type: " << p_out      << endl;
  cout << "Daytime minutes: \t" << d_min   << endl;
  cout << "Nighttime minutes: \t" << n_min << endl;
  cout << "Amount Due: $\t" << total     << endl;

  return 0;
}

/* Execution Sample
Please enter account number and service Code <s or p>
AW5450 p
Please enter daytime minutes and nighttime minutes:
85 110
---------Zippy Cell Phone Company---------
Service Type: PREMIUM
Daytime minutes: 	   85
Nighttime minutes: 	 110
Amount Due: $	26.50
*/








































//
