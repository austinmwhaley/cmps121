//Author:	    Austin Whaley, APW5450, 2019-03-17
//Class:      CMPSC 121
//Experiment: 9
//File:       cmpsc121/experiments/Experiment09/M9E9_apw5450.cpp
//Purpose:    Develop Confidence with Functions

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
Write a program that asks a user to enter a date in month day year format
(for example 10 12 2016) and displays the day of the week for that date,
in this case, Wednesday.
Be sure to validate month and day to be sure they are in range.
To validate 2/29/yyyy, you will have to call the isLeapyear function.

*/

#include <iostream>

using namespace std;

// Function Prototypes
bool isLeapYear(int year);
int getCenturyValue(int year);
int getYearValue(int year);
int getMonthValue(int month, int year);

int main() {
  int c, y, m, month, day, year, v;
  string day_of_week;

  cout << "Please enter a date <MM DD YYYY>\n";
  cin >> month >> day >> year;

  c = getCenturyValue(year);
  y = getYearValue(year);
  m = getMonthValue(month, year);

  v = (day+c+y+m)%7;

  switch(v) {
    case 0:
      day_of_week = "Sunday";
      break;
    case 1:
      day_of_week = "Monday";
      break;
    case 2:
      day_of_week = "Tuesday";
      break;
    case 3:
      day_of_week = "Wednesday";
      break;
    case 4:
      day_of_week = "Thursday";
      break;
    case 5:
      day_of_week = "Friday";
      break;
    case 6:
      day_of_week = "Saturday";
      break;
    case 7:
      day_of_week = "Sunday";
      break;
  }

  cout << month << "/" << day << "/" << year << " is a " << day_of_week << endl;

  return 0;
}



bool isLeapYear(int year) {

  if ( (year%400==0) || (year%4==0 && year%100!=0)){
    return true;
  } else {
    return false;
  } // end if
}

int getCenturyValue(int year) {
  int d, r, c, o;
  c =  2013 / 100;
  d = c/4;
  r = c%4;
  o = (3 - r)*2;
  // cout << o << endl; //DEBUG
  return o;
}

int getYearValue(int year) {
  int l, d, o;
  l = year%100;
  d = l/4;
  o = l + d;
  // cout << l << d << o << endl; //DEBUG
  return o;
}

int getMonthValue(int month, int year) {

  bool status;

  status = isLeapYear(year);

  switch(month) {
    case 1:
      if (status){
        return 6;
      } else {
        return 0;
      }

    case 2:
      if (status){
        return 2;
      } else {
        return 3;
      }

    case 3:
      if (status){
        return 3;
      } else {
        return 3;
      }

    case 4:
      if (status){
        return 6;
      } else {
        return 6;
      }

    case 5:
      if (status){
        return 1;
      } else {
        return 1;
      }

    case 6:
      if (status){
        return 4;
      } else {
        return 4;
      }

    case 7:
      if (status){
        return 6;
      } else {
        return 6;
      }

    case 8:
      if (status){
        return 2;
      } else {
        return 2;
      }

    case 9:
      if (status){
        return 5;
      } else {
        return 5;
      }

    case 10:
      if (status){
        return 0;
      } else {
        return 0;
      }

    case 11:
      if (status){
        return 3;
      } else {
        return 3;
      }

    case 12:
      if (status){
        return 5;
      } else {
        return 5;
      }

    default:
      return -1;
  }
}


/* Execution Sample
Please enter a date <MM DD YYYY>
10 12 2016
10/12/2016 is a Wednesday
*/
