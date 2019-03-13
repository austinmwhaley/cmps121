//Author:	    Austin Whaley, APW5450, 2019-02-10
//Class:      CMPSC 121
//Activity:   8
//File:       cmpsc121/homework/module_05/M5A8_apw5450.cpp
//Purpose:    Identify placement on Cartesian Plane

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

  int x, y, r;

  // x = user x input
  // y = user y input
  // r = end response

  // prompt user for input
  cout << "Please enter an integer coordinate: x, y\n";

  // gather user input
  cin >> x >> y;

  // evaluate coordinate position
  if (x == 0 && y == 0)  // origin
  {
    r = 0;
  }
  else if (x != 0 && y == 0) // x-axis
  {
    r = 1;
  }
  else if (x == 0 && y != 0) // y-axis
  {
    r = 2;
  }
  else if (x > 0 && y > 0) //q1
  {
    r = 3;
  }
  else if (x < 0 && y > 0) //q2
  {
    r = 4;
  }
  else if (x < 0 && y < 0) //q3
  {
    r = 5;
  }
  else if (x > 0 && y < 0) //q4
  {
    r = 6;
  }
  else
  {
    cout << "Error in coordinate evaluation";
  }

  // return response
  switch (r) {
    case 0:
      cout << "(" << x << "," << y << ") is on the origin.\n";
      break;
    case 1:
      cout << "(" << x << "," << y << ") is on the x-axis.\n";
      break;
    case 2:
      cout << "(" << x << "," << y << ") is on the y-axis.\n";
      break;
    case 3:
      cout << "(" << x << "," << y << ") is in the first quadrant.\n";
      break;
    case 4:
      cout << "(" << x << "," << y << ") is in the second quadrant.\n";
      break;
    case 5:
      cout << "(" << x << "," << y << ") is in the thrid quadrant.\n";
      break;
    case 6:
      cout << "(" << x << "," << y << ") is in the fourth quadrant.\n";
      break;
  }

  return 0;

  // Possible choices = <origin, y-axis, x-axis, or quadrant number>
}

/* Execution Sample

*/

/* Execution Sample
Please enter an integer coordinate: x, y
0 0
(0,0) is on the origin.
*/

/* Execution Sample
Please enter an integer coordinate: x, y
0 1
(0,1) is on the y-axis.
*/

/* Execution Sample
Please enter an integer coordinate: x, y
1 0
(1,0) is on the x-axis.
*/

/* Execution Sample
Please enter an integer coordinate: x, y
1 1
(1,1) is in the first quadrant.
*/

/* Execution Sample
Please enter an integer coordinate: x, y
-1 1
(-1,1) is in the second quadrant.
*/

/* Execution Sample
Please enter an integer coordinate: x, y
-1 -1
(-1,-1) is in the thrid quadrant.
*/

/* Execution Sample
Please enter an integer coordinate: x, y
1 -1
(1,-1) is in the fourth quadrant.
*/
