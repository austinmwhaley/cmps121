//Author:	    Austin Whaley, APW5450, 2019-03-24
//Class:      CMPSC 121
//Activity:   18
//File:       cmpsc121/homework/module_10/M10A18_apw5450.cpp
//Purpose:    Parse name

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
Write a program which asks you to enter a name in the form of first middle
initial last. So you might enter for example samuel p. clemens. Use getline to
read in the string because it contains spaces. Also, apparently the shift key
on your keyboard doesn’t work, because you enter it all lower case. Pass the
string to a function which uses .find to locate the letters which need to be
upper case and use toupper to convert those characters to uppercase. The
revised string should then be returned to main in the form Last, First MI
where it will be displayed.
*/

#include <iostream>
#include <cctype>
#include <string>

using namespace std;

//Function Prototypes
string conv_string(string name);

int main() {

  string name, conv_name;

  cout << "Please enter a name <first mi last>:\n";
  getline(cin, name);
  conv_name = conv_string(name);
  cout << "You entered " << name << ". It was converted to: " << conv_name << endl;

  return 0;
}

// Functions
string conv_string(string name) {

  string first, last, mi;
  int first_space, period, second_space;

  // find
  first_space = name.find(' ');
  period = name.find('.');
  second_space = name.find(' ', period);

  // manip
  first = first.assign(name, 0, first_space);
  mi = toupper(name.at(period-1));
  last = last.assign(name, second_space+1);

  first[0] = toupper(first.front()); //capitalize
  last[0] = toupper(last.front()); //capitalize

  return last + ", " + first + " " + mi;
}

/* Execution Sample
Please enter a name <first mi last>:
austin m. whaley
You entered austin m. whaley. It was converted to: Whaley, Austin M

*/























//
