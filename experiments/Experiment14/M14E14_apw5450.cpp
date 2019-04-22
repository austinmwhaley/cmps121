//Author:	    Austin Whaley, APW5450, 2019-04-21
//Class:      CMPSC 121
//Experiment: 14
//File:       cmpsc121/experiments/Experiment14/M14E14_apw5450.cpp
//Purpose:    Practice with Vectors

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
Read in parts.txt >> part_number >> class >> balance >> cost
Display menu that can request reports
Each report should be a function
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream> //reading in file
#include <string>

using namespace std;

struct Parts
{
		string number;
		char cls;
		int ohb;
		double cost;
};

//Function Prototypes
bool readFile(vector <Parts> &pVector); //DONE
int displayMenu(); //DONE
double totalCost(const vector <Parts> &pVector); //DONE
void countByClass(const vector <Parts> & pVector,
                  vector <int> &classCounts); //DONE
double costForClass(char classIn, const vector <Parts> & pVector); //DONE
string highestCost(const vector <Parts> &pVector); //DONE
string lowestCost(const vector <Parts> &pVector); //DONE
void displayCounts(const vector <int> & classCounts); //DONE


int main() {

  bool b;
  int c, e=0;
  vector<Parts> pVector;
  vector<int> classCounts(6, 0);
  string highest_cost, lowest_cost;

  b = readFile(pVector);
  //cout << b << endl; //DEBUG

  while (e != 6){
    c = displayMenu();
    //cout << c << endl; //DEBUG

    switch(c) {
      // total cost of inventory
      case 1:
        double total_cost;
        total_cost = totalCost(pVector);
        cout << "Total cost of Inventory: $" << total_cost << endl; //DEBUG
        break;
      case 2:
        countByClass(pVector, classCounts);
        displayCounts(classCounts);
        break;
      case 3:
        char classIn;
        double cost_for_class;
        cout << "Which Class?: ";
        cin >> classIn;
        cost_for_class = costForClass(classIn, pVector);
        cout << "Cost of inventory for class "<< classIn << " is $" <<  cost_for_class << endl;
        break;
      case 4:
        highest_cost = highestCost(pVector);
        break;
      case 5:
        lowest_cost = lowestCost(pVector);
        break;
      case 6:
        e = 6;
        cout << "Goodbye..." << endl;
        break;
    } // end switch
  } // end while

  return 0;
} // end main


// Functions
bool readFile(vector <Parts> &pVector){

  bool b=true;
  string number;
  char cls;
  int ohb, i;
  double cost;
  ifstream input_file;
  input_file.open("parts.txt");

  if (input_file){
    b=true;
    //cout << "Reading file" << endl; //DEBUG
    while (input_file >> number >> cls >> ohb >> cost){
      //cout << number << cls << ohb << cost << endl; //Reading in entire file

      pVector.push_back(Parts());

      pVector[i].number = number;
      pVector[i].cls = cls;
      pVector[i].ohb = ohb;
      pVector[i].cost = cost;

      i++;
      //continue; //pass
    } // end while
  } else {
    b=false;
  }// end if

  return b;

} // end function


int displayMenu(){

  int c = 0;

  cout << "R E P O R T S  M E N U" << endl;
  cout << "1. Total cost of inventory." << endl;
  cout << "2. A count of parts of each class." << endl;
  cout << "3. Cost of inventory for a class." << endl;
  cout << "4. Part with the highest cost of inventory." << endl;
  cout << "5. Part with lowest cost of inventory." << endl;
  cout << "6. Exit." << endl;

  while (c == 0){
    cout << "Please enter a number: ";
    cin >> c;
    if (c >=1 && c <= 6){
      return c;
    } else {
      c=0;
    } // end if
  } // end while
} // end function


double totalCost(const vector <Parts> &pVector){

  double total_cost=0;

  for (int i = 0; i < pVector.size(); i++){
    total_cost += (pVector[i].cost*pVector[i].ohb);
  } // end for
  return total_cost;
} // end function


void countByClass(const vector <Parts> & pVector, vector <int> &classCounts){
  char cls;
  int ohb;

  for (int i = 0; i < pVector.size(); i++){
    switch (pVector[i].cls){
      case 'A':
        classCounts[0] += 1;
        break;
      case 'B':
        classCounts[1] += 1;
        break;
      case 'C':
        classCounts[2] += 1;
        break;
      case 'D':
        classCounts[3] += 1;
        break;
      case 'E':
        classCounts[4] += 1;
        break;
      case 'F':
        classCounts[5] += 1;
        break;
    } // end switch
  } // end for
} // end function


void displayCounts(const vector <int> & classCounts){
  cout << "A\t" << classCounts[0] << endl;
  cout << "B\t" << classCounts[1] << endl;
  cout << "C\t" << classCounts[2] << endl;
  cout << "D\t" << classCounts[3] << endl;
  cout << "E\t" << classCounts[4] << endl;
  cout << "F\t" << classCounts[5] << endl;
}


double costForClass(char classIn, const vector <Parts> & pVector){
  double total_cost = 0;
  for (int i = 0; i < pVector.size(); i++){
    if (pVector[i].cls == classIn){
        total_cost += (pVector[i].cost*pVector[i].ohb);
    } // end if
  } // end for
  return total_cost;
} // end function


string highestCost(const vector <Parts> &pVector){
  double highest_cost = 0;
  string highest_part;
  for (int i = 0; i < pVector.size(); i++){
    if ( (pVector[i].cost*pVector[i].ohb) > highest_cost){
      highest_part = pVector[i].number;
    } // end if
  } // end for

  cout << "The part with the highest cost of inventory is " << highest_part << endl;
  return highest_part;
} // end function


string lowestCost(const vector <Parts> &pVector){
  double lowest_cost = 1000000;
  string lowest_part;
  for (int i = 0; i < pVector.size(); i++){
    if ( (pVector[i].cost*pVector[i].ohb) < lowest_cost){
      lowest_part = pVector[i].number;
    } // end if
  } // end for

  cout << "The part with the lowest cost of inventory is " << lowest_part << endl;
  return lowest_part;
} // end fucntion


/* Execution Sample
R E P O R T S  M E N U
1. Total cost of inventory.
2. A count of parts of each class.
3. Cost of inventory for a class.
4. Part with the highest cost of inventory.
5. Part with lowest cost of inventory.
6. Exit.
Please enter a number: 1

Total cost of Inventory: $342966
R E P O R T S  M E N U
1. Total cost of inventory.
2. A count of parts of each class.
3. Cost of inventory for a class.
4. Part with the highest cost of inventory.
5. Part with lowest cost of inventory.
6. Exit.
Please enter a number: 2
A       85
B       69
C       77
D       60
E       5
F       8
R E P O R T S  M E N U
1. Total cost of inventory.
2. A count of parts of each class.
3. Cost of inventory for a class.
4. Part with the highest cost of inventory.
5. Part with lowest cost of inventory.
6. Exit.
Please enter a number: 3
Which Class?: A
Cost of inventory for class A is $191180
R E P O R T S  M E N U
1. Total cost of inventory.
2. A count of parts of each class.
3. Cost of inventory for a class.
4. Part with the highest cost of inventory.
5. Part with lowest cost of inventory.
6. Exit.
Please enter a number: 4
The part with the highest cost of inventory is P-43672
R E P O R T S  M E N U
1. Total cost of inventory.
2. A count of parts of each class.
3. Cost of inventory for a class.
4. Part with the highest cost of inventory.
5. Part with lowest cost of inventory.
6. Exit.
Please enter a number: 5
The part with the lowest cost of inventory is P-43672
R E P O R T S  M E N U
1. Total cost of inventory.
2. A count of parts of each class.
3. Cost of inventory for a class.
4. Part with the highest cost of inventory.
5. Part with lowest cost of inventory.
6. Exit.
Please enter a number: 6
Goodbye...
*/
