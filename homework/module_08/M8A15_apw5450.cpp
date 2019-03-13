//Author:	    Austin Whaley, APW5450, 2019-03-03
//Class:      CMPSC 121
//Activity:   15
//File:       cmpsc121/homework/module_08/M8A15_apw5450.cpp
//Purpose:    Value of items loop

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

*/

#include <iostream>

using namespace std;

// Function Prototype
double value_of_purchase(int items_sold, double cost);

int main() {

  int items_sold;
  double cost, value;
  char conf='Y';

  do {

    // Ask and collect user input
    cout << "Please enter number of items sold and the cost of one item\n";
    cin >> items_sold >> cost;

    value = value_of_purchase(items_sold, cost);

    cout << "The extended amount is $" << value << endl;

    cout << "Do you have another purchase to enter? <Y or N> " << endl;
    cin >> conf;

  } while (conf == 'Y'); // end do-while loop

  return 0;
}

double value_of_purchase(int items_sold, double cost) {
  return items_sold * cost;
}


/* Execution Sample
Please enter number of items sold and the cost of one item
2 5.00
The extended amount is $10
Do you have another purchase to enter? <Y or N>
Y
Please enter number of items sold and the cost of one item
3 5.00
The extended amount is $15
Do you have another purchase to enter? <Y or N>
N
*/
