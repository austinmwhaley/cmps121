//Author:	    Austin Whaley, APW5450, 2019-02-16
//Class:      CMPSC 121
//Experiment: 06
//File:       cmpsc121/experiments/Experiment06/M6E6_apw5450.cpp
//Purpose:    Develop confidence in loops

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
1) Read in num_items and unit_price per item
2) Indicate end of list by entering -99 0
3) Enter:
  a) number of transactions -> trans_num
  b) total units sold -> unit_count
  c) average units p/order
  d) largest transaction amount
  e) smallest transaction amount
  f) total revenue
  g) average revenue per order
*/


#include <iostream>
#include <iomanip>
using namespace std;

int main() {

  double num_items, trans_num=1, unit_total=0,
          unit_price, total_rev=0, trans_amt=0,
          max_trans_amt, min_trans_amt;

  // num_items = number of items (user input)
  // unit_price = price per unit (user input)
  // trans_num = transaction count (counter)
  // unit_total = total number of units (accumulator)
  // total_rev = total revenue (accumulator)
  // trans_amt = transaction amount
  // max_trans_amt = maximum transaction amount
  // min_trans_amt = minimum transaction amount

  cout << "Enter transactions -99 0 to stop\n";

  do
  {
    // Prompt and gather user input
    cout << "Transaction #" << trans_num << ": ";
    cin >> num_items >> unit_price;

    if ( (num_items != -99) && (unit_price != 0) )
    {

      trans_amt = num_items*unit_price;

      // Evaluate transaction report values
      unit_total += num_items;
      total_rev += (num_items*unit_price);

      if (trans_num == 1){
        max_trans_amt, min_trans_amt = trans_amt;
      } else {

        if (trans_amt > max_trans_amt) {
          max_trans_amt = trans_amt;
        } // end max-if

        if (trans_amt < min_trans_amt) {
          min_trans_amt = trans_amt;
        } // end min-if

      } // end if-else

      trans_num += 1;

    } // end inner while-loop

  } while ( (num_items != -99) && (unit_price != 0) );

  trans_num -= 1;

  //========================================================================//

  // cout << num_items << endl;
  // cout << unit_price << endl;
  // cout << trans_num << endl;
  // cout << unit_total << endl;
  // cout << total_rev << endl;
  // cout << trans_amt << endl;
  // cout << max_trans_amt << endl;
  // cout << min_trans_amt << endl << endl;

  // We need to divide by a double not user input int DataType
  trans_num = static_cast<double>(trans_num);

  // set precision

  cout << setprecision(2) << fixed;

  cout << "TRANSACTION PROCESSING REPORT\n";

  // a) number of transactions
  cout << "\tTransactions processed:\t\t" << right << setw(10) << trans_num << endl;

  // b) total units sold
  cout << "\tUnits sold:\t\t\t" << right << setw(10) << unit_total << endl;

  // c) AVG units per order
  cout << "\tAverage units per order:\t" << right << setw(10) << (unit_total/(trans_num)) << endl;

  // d) largest transaction amount
  cout << "\tLargest Transaction:\t\t" << right << setw(10) << max_trans_amt << endl;

  // e) smallest transaction amount
  cout << "\tSmallest Transaction:\t\t" << right << setw(10) << min_trans_amt << endl;

  // f) total revenue
  cout << "\tTotal Revenue:\t\t\t"<< "$" << right << setw(9) << total_rev << endl;

  // g) average revenue per order
  cout << "\tAverage Revune:\t\t\t$" << right << setw(9) << (total_rev/trans_num) << endl;

  return 0;
  
}

/*
Enter transactions -99 0 to stop
Transaction #1: 30 9.75
Transaction #2: 22 8.50
Transaction #3: 15 7.95
Transaction #4: 12 9.00
Transaction #5: 16 8.55
Transaction #6: 36 7.99
Transaction #7: 100 10.75
Transaction #8: 43 9.99
Transaction #9: 14 6.95
Transaction #10: 14 8.98
Transaction #11: -99 0
TRANSACTION PROCESSING REPORT
	Transactions processed:		     10.00
	Units sold:			              302.00
	Average units per order:	     30.20
	Largest Transaction:		     1075.00
	Smallest Transaction:		       97.30
	Total Revenue:			      $  2858.78
	Average Revune:			      $   285.88

*/






































//
