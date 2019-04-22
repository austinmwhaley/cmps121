//Author:	    Austin Whaley, APW5450, 2019-04-21
//Class:      CMPSC 121
//Activity:   25
//File:       cmpsc121/homework/module_14/M14A25_apw5450.cpp
//Purpose:    -

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
1. Fill vector with 5000 random numbers
2. Display:
- Smallest number DONE
- largest number DONE
- number of odd values DONE
- number of even values DONE
- sum of values
- average of values
- ask user for int and display the subscript of the cell or "NOT FOUND!"
- must use a function for all asks
*/

#include <iostream>
#include <ctime>    // time()
#include <cstdlib>  // srand(), rand()
#include <vector>
#include <iomanip>

using namespace std;

//Function Prototypes
void shellSort(vector<int>& V);
void swapper(int &a, int &b);
int find_smallest(const vector<int> &v);
int find_largest(const vector<int> &v);
int find_odd_values(const vector<int> &v);
int find_even_values(const vector<int> &v);
int find_sum_vect(const vector<int> &v);
double find_avg_vect(int size, int sum);
int binary_search(const vector<int> &v, int f, int l, int val);


int main() {

  const int MIN = 0, MAX = 10000;
  vector<int> v(5000);
  //vector<int> ;
  unsigned seed = time(0);
  srand(seed);
  int r, smallest, largest, num_odd, num_even, sum_of_vect,
      u_val, p;
  double avg_of_vect;

  // Fill vector with 5000 random numbers between MIN and MAX
  for (int i = 0; i < v.size(); i++){
    r = (rand() % (MAX - MIN + 1)) + MIN;
    v[i] = r;
  } // end for-loop

  smallest = find_smallest(v);
  largest = find_largest(v);
  num_odd = find_odd_values(v);
  num_even = find_even_values(v);
  sum_of_vect = find_sum_vect(v);
  avg_of_vect = find_avg_vect(v.size(), sum_of_vect);


  cout << left << setw(20) << "Smallest #:"  << smallest    << endl;
  cout << left << setw(20) << "Largest #:"   << largest     << endl;
  cout << left << setw(20) << "# Of Odds:"   << num_odd     << endl;
  cout << left << setw(20) << "# Of Evens:"  << num_even    << endl;
  cout << left << setw(20) << "Total:"       << sum_of_vect << endl;
  cout << left << setw(20) << "Average:"     << avg_of_vect << endl;

  cout << "Please enter a number between " << MIN << " & " << MAX << ": ";
  cin >> u_val;
  //u_val = 500; //DEBUG

  shellSort(v); //sort v
  p = binary_search(v, 0, v.size(), u_val);

  if (p == -1){
    cout << left << setw(20) << "NOT FOUND!\n";
  } else {
    cout << left << setw(20) << "Found at Position:" << p << endl;
  }

  return 0;
} // end main


// Functions
void shellSort(vector<int>& V)
{
	bool flag = true;
	int i, numLength = V.size();

	int d = numLength;
	while (flag || (d>1))    // bool flag
	{
		flag = false;  //reset flag to 0 to check for
		// future swaps     
		d = (d + 1) / 2;
		for (i = 0; i < (numLength - d); i++)
		{
			if (V[i + d] < V[i])
			{
				swapper(V[i], V[i + d]);

				flag = true;     //tells swap has occurred
			}
		}
	}
}


void swapper(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}


int find_smallest(const vector<int> &v){
  int c=10000;

  for (int i : v){
    if (i < c){
      c = i;
    } // end if-statement
  } // end for-loop

  return c;

} // end function


int find_largest(const vector<int> &v){
  int c=0;

  for (int i : v){
    if (i > c){
      c = i;
    } // end if-statement
  } // end for-loop

  return c;
}


int find_odd_values(const vector<int> &v){
  int c = 0;

  for (int i : v){
    if (i % 2 != 0){
      c += 1;
    } // end if-statement
  } // end for loop

  return c;

} // end function


int find_even_values(const vector<int> &v){
  int c = 0;

  for (int i : v){
    if (i % 2 == 0){
      c += 1;
    } // end if-statement
  } // end for loop

  return c;

} // end function


int find_sum_vect(const vector<int> &v){
  int s = 0;
  for (int i: v){
    s += i;
  } // end for loop

  return s;

} // end function


double find_avg_vect(int size, int sum){
  return sum/static_cast<float>(size);
}


int binary_search(const vector<int> &v, int first, int last, int value){
  // v is assumed to be sorted upon call
  // pg.1242 = reference

  int middle;
  middle = (first + last)/2;

  if (first > last){
    return -1; // value not found
  } else if (v[middle] == value){
    return middle; // value found
  } else if (v[middle] < value){
    return binary_search(v, middle+1, last, value); //value above
  } else {
    return binary_search(v, first, middle-1, value); //value below
  } // end if statement
} // end function

/* Execution Sample
Smallest #:         0
Largest #:          9999
# Of Odds:          2562
# Of Evens:         2438
Total:              24881062
Average:            4976.21
Please enter a number between 0 & 10000: 500
Found at Position:  272
*/
