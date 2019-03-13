//Author:	    Austin Whaley, APW5450, 2019-02-24
//Class:      CMPSC 121
//Activity:   11
//File:       cmpsc121/homework/module_07/M7A11_apw5450.cpp
//Purpose:    Reading files

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
1. Read in parts.txt
2. display the cost of inventory for each of the part classes
*/

#include <iostream>
#include <fstream> //read in file
#include <iomanip>

using namespace std;

int main() {

  double class_a_val=0, class_b_val=0, class_c_val=0, class_d_val=0,
         class_u_val=0, val;
  int class_a_count=0, class_b_count=0, class_c_count=0, class_d_count=0,
      class_u_count=0, count, lines=0;
  string part_num;
  char part_class;

  ifstream input_file("parts.txt");

  cout << "Reading data from parts.txt\n";

  while (input_file >> part_num >> part_class >> count >> val)
  {
    lines += 1;
    switch (part_class)
    {
      case 'A':
        class_a_count += count;
        class_a_val += (count*val);
        break;
      case 'B':
        class_b_count += count;
        class_b_val += (count*val);
        break;
      case 'C':
        class_c_count += count;
        class_c_val += (count*val);
        break;
      case 'D':
        class_d_count += count;
        class_d_val += (count*val);
        break;
      default:
        class_u_count += count;
        class_u_val += (count*val);
    } // end switch
  } // end while

  cout << lines << " lines total\n";

  cout << setprecision(2) << fixed;

  cout << "A parts\t Count:" << class_a_count << "\t Value of inventory: "\
  << class_a_val << endl;

  cout << "B parts\t Count:" << class_b_count << "\t Value of inventory: "\
  << class_b_val << endl;

  cout << "C parts\t Count:" << class_c_count << "\t Value of inventory: "\
  << class_c_val << endl;

  cout << "D parts\t Count:" << class_d_count << "\t Value of inventory: "\
  << class_d_val << endl;

  cout << "U parts\t Count:" << class_u_count << "\t Value of inventory: "\
  << class_u_val << endl;

  input_file.close();

  return 0;
}

/* Execution Sample
Reading data from parts.txt
304 lines total
A parts	 Count:2265	 Value of inventory: 191180.07
B parts	 Count:1744	 Value of inventory: 74764.16
C parts	 Count:2167	 Value of inventory: 50322.30
D parts	 Count:1448	 Value of inventory: 22416.49
U parts	 Count:274	 Value of inventory: 4282.68
*/
