//Author:	    Austin Whaley, APW5450, 2019-03-31
//Class:      CMPSC 121
//Activity:   19
//File:       cmpsc121/homework/module_11/M11A19_apw5450.cpp
//Purpose:    Overload Functions Practice

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
1. Randomly ask user to enter base and height or three sides
2. Call appropriate overload function
3. Return double
4. Ask the user if they want to continue or not
*/

#include <iostream>
#include <cstdlib>  // rand function
#include <ctime>    // time function
#include <cmath>    // sqrt function

using namespace std;

//Function Prototypes
double triangleArea(double base, double height);
double triangleArea(double s1, double s2, double s3);

int main() {

  // Variable declaration
  int min_val=0, max_val=1, r;
  double base, height, s1, s2, s3, area;
  char c;

  do {
    // Genrate seed for rand via system time
    unsigned seed = time(0);
    srand(seed);

    // Init random number between 0 AND 1
    r = (rand() % (max_val - min_val + 1)) + min_val;

    // Control Logic for overload functions
    if (r == 0) {
      cout << "Please enter base and height of triangle\n";
      cin >> base >> height;
      area = triangleArea(base, height);
    } else {
      cout << "Please enter three side lengths of triangle\n";
      cin >> s1 >> s2 >> s3;
      area = triangleArea(s1, s2, s3);
    } // end if

    // Print Area result
    cout << "The area is: " << area << endl;

    // Prompt user to continue and gather input
    cout << "Continue? <Y or N>\n";
    cin >> c;

  } while (toupper(c) == 'Y'); //end while

  return 0;
}

// Functions
double triangleArea(double base, double height) {
  return (.5*base*height);
}

double triangleArea(double s1, double s2, double s3) {

  //p = (a+b+c)/2
  //a = sqrt(p*a*b*c)

  double p;

  p = ( (s1+s2+s3)/2 );

  return sqrt( p * (p - s1) * (p - s2) * (p - s3) );
}


/* Execution Sample
Please enter three side lengths of triangle
18 30 24
The area is: 216
Continue? <Y or N>
y
Please enter base and height of triangle
24 18
The area is: 216
Continue? <Y or N>
n
*/
