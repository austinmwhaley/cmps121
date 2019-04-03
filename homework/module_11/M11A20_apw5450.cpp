//Author:	    Austin Whaley, APW5450, 2019-03-31
//Class:      CMPSC 121
//Activity:   20
//File:       cmpsc121/homework/module_11/M11A20_apw5450.cpp
//Purpose:    Reverse a String

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
#include <string>

using namespace std;

//Function Prototypes
void reverse(string s, int i);

int main() {

  string s;

  cout << "Please enter a string\n";
  getline(cin, s);

  reverse(s, s.length());

  cout << endl;

  return 0;
}

// Functions
void reverse(string s, int i){

  // cout << s.length() << " " << i << endl; //DEBUG

  if (i >= 0){
    cout << s[i];

    reverse(s, i - 1);
  }

}

/* Execution Sample
Please enter a string
Hello, World!
!dlroW ,olleH
*/
