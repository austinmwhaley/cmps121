//Author:	    Austin Whaley, APW5450, 2019-02-16
//Class:      CMPSC 121
//Activity:   10
//File:       cmpsc121/homework/module_06/M6A10_apw5450.cpp
//Purpose:    Day of week (do-while loops)

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

int main()
{
  // Declare variables
  int w_val;
  bool f;
  string c;

  do //outside do-while loop start
  {

  // Prompt user for day_of_week input
  do
  {

    f = false;

    cout << "Please enter a day of week value: ";
    cin >> w_val;

    if ( (w_val < 1) || (w_val > 7) ) {
      cout << w_val << " is invalid\n";
    } else {
      f = true;
    } // end if

  } while (f == false); //end do-while

  // Display day of week
  switch (w_val)
  {
    case 1:
      cout << "Sunday\n";
      break;
    case 2:
      cout << "Monday\n";
      break;
    case 3:
      cout << "Tuesday\n";
      break;
    case 4:
      cout << "Wednesday\n";
      break;
    case 5:
      cout << "Thursday\n";
      break;
    case 6:
      cout << "Friday\n";
      break;
    case 7:
      cout << "Saturday\n";
      break;
  } // end switch


  cout << "Do you wish to continue <y, n>? ";
  cin >> c;

} while ( (c == "y") || (c == "Y") ); // outside do-while loop end

  return 0;
} // end main


/*
Please enter a day of week value: 7
Saturday
Do you wish to continue <y, n>? y
Please enter a day of week value: 8
8 is invalid
Please enter a day of week value: 5
Thursday
Do you wish to continue <y, n>? n
*/






































//
