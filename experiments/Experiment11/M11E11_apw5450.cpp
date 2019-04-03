//Author:	    Austin Whaley, APW5450, 2019-03-31
//Class:      CMPSC 121
//Experiment: 11
//File:       cmpsc121/experiments/Experiment11/M11E11_apw5450.cpp
//Purpose:    String Functions

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
#include <fstream>

using namespace std;

//Function Prototypes
string fixName(string n); //takes in the name and returns it in the right format
string fixSSN(string ss); //Fixes SSN
string fixPhone(string ph); // Fixes phone number
string fixAddress(string addr); //Fixes address
string fixCity(string cty); // Fixes city
string fixState(string st); // Fixes state
string extractField(string &s);
//Extracts a field eg name from the input string and then deletes
//it and the octothorpe (#) that follows it. Notice string s is
//passed by reference
void buildLine(string &s, string field); // Concatenates field and a comma to string s

int main() {

  string s, n, ss, ph, addr, cty, st;
  int space;

  // specify input_file
  ifstream input_file("badnames.txt");
  ofstream output_file("parsed_names.txt");

  // read in lines
  if (input_file) {
    while ( getline(input_file, s) )
    {
      // NAME
      // cout << l << endl; //DEBUG
      space = s.find('#', 0);
      n = fixName(n.assign(s, 0, space ));
      // cout << n << endl; //DEBUG
      s.erase(0, space + 1);

      // SSN
      // cout << l << endl; //DEBUG
      space = s.find('#', 0);
      ss = fixSSN(ss.assign(s, 0, space));
      // cout << f_ssn << endl; //DEBUG
      s.erase(0, space + 1);

      // PHONE
      // cout << l << endl; //DEBUG
      space = s.find('#', 0);
      ph = fixPhone(ph.assign(s, 0, space));
      // cout << f_phone << endl; //DEBUG
      s.erase(0, space + 1);

      // ADDR
      // cout << l << endl; //DEBUG
      space = s.find('#', 0);
      addr = fixAddress(addr.assign(s, 0, space));
      // cout << f_addr << endl; //DEBUG
      s.erase(0, space + 1);

      // City
      // cout << l << endl; //DEBUG
      space = s.find('#', 0);
      cty = fixCity(cty.assign(s, 0, space));
      // cout << f_cty << endl; //DEBUG
      s.erase(0, space + 1);

      // State
      // cout << l << endl; //DEBUG
      space = s.find('#', 0);
      st = fixState(st.assign(s, 0, space));
      // cout << f_st << endl; //DEBUG
      s.erase(0, space + 1);

      // Zip = s

      // Write output
      output_file << n << ss << ph << addr << cty << st << s << endl;

      // break; //DEBUG

    } // end while loop
  } // end if statement

  return 0;
}

// Functions

string fixName(string n) {

  int sep;
  string f, l;

  sep = n.find(' ');
  f.assign(n, 0, sep);
  l.assign(n, sep + 1);
  f[0] = toupper(f[0]);
  l[0] = toupper(l[0]);

  return l+","+f+",";

}

string fixSSN(string ss) {
  string f_ssn;

  f_ssn.append(ss, 0, 3).append("-", 1);
  f_ssn.append(ss, 3, 2).append("-", 1);
  f_ssn.append(ss, 5, 4);

  return f_ssn+",";
}

string fixPhone(string ph) {
  string f_phone;

  f_phone.append(ph, 0, 3).append("-", 1);
  f_phone.append(ph, 3, 3).append("-", 1);
  f_phone.append(ph, 6, 4);

  return f_phone+",";

}

string fixAddress(string addr) {
  char prev=' ';

  for (int i = 0; i < addr.length(); i++){
    // cout << addr[i];
    if (prev == ' '){
      addr[i] = toupper(addr[i]);
    } // end if
    prev = addr[i];
  } //end for

  return addr+',';
}

string fixCity(string cty) {
  cty[0] = toupper(cty[0]);
  return cty+',';
}

string fixState(string st) {
  st[0] = toupper(st[0]);
  st[1] = toupper(st[1]);
  return st+',';
}


/* Execution Sample

*/
