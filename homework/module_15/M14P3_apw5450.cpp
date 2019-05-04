//Author:	    Austin Whaley, APW5450, 2019-04-27
//Class:      CMPSC 121
//Project:    3
//File:       cmpsc121/homework/module_15/M14P3_apw5450.cpp
//Purpose:    Project 3

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
- Be able to type in a part number and display console information
- Or if not present, be able to insert it into the list (in order)

- After searching:
1. how many searches
2. How many successful
3. and how many inserted

- Needs to write to parts.txt so additions are saved
- Shell Sort needs to be used for sorting
- Will need to use a parallel vector
-
*/

#include <iostream>
#include <vector>
#include <fstream> //file manip
#include <string>
#include <iomanip>

using namespace std;

// templated swap function – Swaps two items in a vector of any type
// Put this BEFORE main()  Called from sort function
template <class CType>
void swapper (CType& a, CType & b)
{
    CType temp;
    temp = a;
    a = b;
    b = temp;
}


//Function Prototypes

bool get_data(vector <string>& part_number,
              vector <char>& part_class,
              vector <int>& part_ohb,
              vector <double>& part_cost); // fills vectors


int binary_search(const vector<string>& vect, int first, int last, string key); // Does a binary search
string get_target();
void get_more_data(char& class_in,int& part_ohb_in,double& part_cost_in);

void insert_data(vector <string>& part_number,
                 vector <char>& part_class,
                 vector <int>& part_ohb,
                 vector <double>& part_cost,
                 string part_in, char class_in,
                 int part_ohb_in, double part_cost_in);

void display(const vector <string>& part_number,
             const vector <char>& part_class,
             const vector <int>& part_ohb,
             const vector <double>& part_cost, int finder);

void sort(vector <string>& part_number,
           vector <char>& part_class,
           vector <int>& part_ohb,
           vector <double>& part_cost);

void print_stats(int searches, int good, int bad);

void put_data(const vector <string>& part_number,
              const vector <char>& part_class,
              const vector <int>& part_ohb,
              const vector <double>& part_cost);


int main() {

  vector<string> part_number;
  vector<char> part_class;
  vector<int> part_ohb;
  vector<double> part_cost;
  bool read_file_status=false;
  string target;
  int search_count=0, vect_index, parts_added=0;
  char b='Y';

  char class_in;
  int part_ohb_in;
  double part_cost_in;

  read_file_status = get_data(part_number, part_class, part_ohb, part_cost);

  while(b == 'Y'){
    search_count+=1;

    target = get_target();

    vect_index = binary_search(part_number, 0, part_number.size() - 1, target);
    //cout << vect_index << endl;

    if (vect_index == -1){
      cout << "PART NUMBER NOT FOUND - ADDING PART NUMBER" << endl;
      get_more_data(class_in, part_ohb_in, part_cost_in);
      insert_data(part_number, part_class, part_ohb, part_cost,
                  target, class_in, part_ohb_in, part_cost_in);
      sort(part_number, part_class, part_ohb, part_cost);
      parts_added+=1;

      // for (string part: part_number){
      //   cout << part << endl;
      // }

    } else {
      display(part_number, part_class, part_ohb, part_cost, vect_index);
    }

    cout << "ADDITIONAL SEARCH? <Y or N>: ";
    cin >> b;
    if (toupper(b) != 'Y'){
      print_stats(search_count, (search_count-parts_added), parts_added);
    } // end if
  } // end-while

  put_data(part_number, part_class, part_ohb, part_cost);
  return 0;
} // end main


// Functions
bool get_data(vector <string>& part_number,
              vector <char>& part_class,
              vector <int>& part_ohb,
              vector <double>& part_cost){

  bool b=true;
  int i = 0;

  string number;
  char cls;
  int ohb;
  double cost;

  ifstream input_file;
  input_file.open("parts.txt");

  if (input_file){
    b=true;
    // cout << "Reading file" << endl; //DEBUG

    // Place values in intermediate variables
    while (input_file >> number >> cls >> ohb >> cost){
      //cout << number << cls << ohb << cost << endl; //DEBUG

      // Add intermediate variables to vector
      part_number.push_back(number);
      part_class.push_back(cls);
      part_ohb.push_back(ohb);
      part_cost.push_back(cost);

      // cout << part_number[i] << "|" << part_class[i] << "|" \
      //      << part_ohb[i]    << "|" << part_cost[i]  << endl; //DEBUG

      i++; //Increment index
    } // end while
  } else {
    b=false;
  }// end if

  return b;

}

int binary_search(const vector<string>& vect, int first, int last, string key){
  // Adapted from pg. 1241 Recursive Binary Search Function

  int middle;

  if (first > last){
    return -1;
  }
  middle = (first + last) / 2;
  if (vect[middle] == key){
    return middle;
  } else if (vect[middle] < key){
    return binary_search(vect, middle+1, last, key);
  } else {
    return binary_search(vect, first, middle-1, key);
  } // end if
}

string get_target(){
  string part_number;
  cout << "Please insert a part number: ";
  cin >> part_number;
  return part_number;
}

void get_more_data(char& class_in,int& part_ohb_in,double& part_cost_in){

  cout << "CLASS OHB COST: ";
  cin >> class_in >> part_ohb_in >> part_cost_in;
}

void insert_data(vector <string>& part_number,
                 vector <char>& part_class,
                 vector <int>& part_ohb,
                 vector <double>& part_cost,
                 string part_in, char class_in,
                 int part_ohb_in, double part_cost_in){

    part_number.push_back(part_in); //target
    part_class.push_back(class_in);
    part_ohb.push_back(part_ohb_in);
    part_cost.push_back(part_cost_in);

}

void display(const vector <string>& part_number,
             const vector <char>& part_class,
             const vector <int>& part_ohb,
             const vector <double>& part_cost, int finder){
    // START
    double inv_value = part_ohb[finder]*part_cost[finder];

    cout << setprecision(2) << fixed;
    cout << left << setw(25) << "PART NUMBER:" << part_number[finder] << endl;
    cout << left << setw(25) << "CURRENT INVENTORY:" << part_ohb[finder] << endl;
    cout << left << setw(25) << "CLASS:" << part_class[finder] << endl;
    cout << left << setw(25) << "COST:" << "$" << part_cost[finder] << endl;
    cout << left << setw(25) << "INV VALUE:" << "$" << inv_value << endl;
}

void sort(vector <string>& part_number,
           vector <char>& part_class,
           vector <int>& part_ohb,
           vector <double>& part_cost){

  for (int max_e = part_class.size() - 1; max_e > 0; max_e--){
    for (int i = 0; i < max_e; i++){
      if (part_number[i] > part_number[i+1]){
        swap(part_number[i], part_number[i+1]);
        swap(part_class[i], part_class[i+1]);
        swap(part_ohb[i], part_ohb[i+1]);
        swap(part_cost[i], part_cost[i+1]);
      } // end if
    } // end for-loop INNER
  } // end for-loop OUTER
}

void print_stats(int searches, int good, int bad){
  cout << "----------SEARCH STATS----------" << endl;
  cout << left << setw(25) << "TOTAL SEARCHES:" << searches << endl;
  cout << left << setw(25) << "PARTS SEARCH POSITIVE:" << good << endl;
  cout << left << setw(25) << "PARTS SEARCH NEGATIVE:" << bad << endl;
}

void put_data(const vector <string>& part_number,
              const vector <char>& part_class,
              const vector <int>& part_ohb,
              const vector <double>& part_cost){
    //START
    ofstream output_file;
    output_file.open("parts_v2.txt");

    for (int i = 0; i < part_number.size(); i++){
      output_file << part_number[i] << " "\
                  << part_class[i]  << " "\
                  << part_ohb[i]    << " "\
                  << part_cost[i]   << endl;
    } // end for
}


/* Execution Sample
Please insert a part number: P-33195
PART NUMBER:             P-33195
CURRENT INVENTORY:       11
CLASS:                   C
COST:                    $24.63
INV VALUE:               $270.93
ADDITIONAL SEARCH? <Y or N>: Y
Please insert a part number: P-10022
PART NUMBER NOT FOUND - ADDING PART NUMBER
CLASS OHB COST: C 123 45.00
ADDITIONAL SEARCH? <Y or N>: Y
Please insert a part number: P-31977
PART NUMBER NOT FOUND - ADDING PART NUMBER
CLASS OHB COST: A 12 156.00
ADDITIONAL SEARCH? <Y or N>: Y
Please insert a part number: P-32344
PART NUMBER NOT FOUND - ADDING PART NUMBER
CLASS OHB COST: D 88 12.00
ADDITIONAL SEARCH? <Y or N>: N
----------SEARCH STATS----------
TOTAL SEARCHES:          4
PARTS SEARCH POSITIVE:   1
PARTS SEARCH NEGATIVE:   3
*/
