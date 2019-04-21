//Author:	    Austin Whaley, APW5450, 2019-04-13
//Class:      CMPSC 121
//Experiment: 13
//File:       cmpsc121/experiments/Experiment13/M13E13_apw5450.cpp
//Purpose:    Build confidence with arrays and reading files

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
#include <string>   // string dtype
#include <fstream>  // ifstream
#include <ctime>    // time()
#include <cstdlib>  // srand(), rand()
#include <iomanip>  // setpercision

using namespace std;

//Function Prototypes
void fill_candidates_array(string candidates[], int &size);
void fill_votes_array(int votes[], int size);
void fill_percents_array(int votes[], double percents[], int size);
void print_results(string cadidates[], int votes[], double percents[], int size);

int main() {

  // ONLY 19 CANDIDATES IN CANDIDATES.TXT!!!
  const int CAPACITY = 25;
  string candidates[CAPACITY];
  int votes[CAPACITY], size=CAPACITY;
  double percents[CAPACITY];

  fill_candidates_array(candidates, size);

  fill_votes_array(votes, size);

  fill_percents_array(votes, percents, size);

  print_results(candidates, votes, percents, size);

  return 0;
} // end main


// Functions
void fill_candidates_array(string candidates[], int &size) {

  string candidate;
  int c=0;

  ifstream input_file("candidates.txt");

  while (input_file >> candidate){
    // cout << candidate << endl; //DEBUG
    candidates[c] = candidate;
    c+=1;
  } // end while-loop

  size = c;
  // cout << "Size = " << size << endl; //DEBUG

} // end function


void fill_votes_array(int votes[], int size){

  const int MIN = 1500, MAX = 25000;
  unsigned seed = time(0);
  srand(seed);
  int r;

  for (int i = 0; i < size; i++){
    r = (rand() % (MAX - MIN + 1)) + MIN;
    votes[i] = r;
  } // end for-loop
} // end function


void fill_percents_array(int votes[], double percents[], int size){
  // Determine the total number of votes for all candiates

  int sum=0;

  for (int i = 0; i < size; i++) {
    // cout << "Votes: " << votes[i] << endl; //DEBUG
    sum+=votes[i];
  } // end for-loop

  // cout << "Sum: " << sum << endl; //DEBUG

  for (int i = 0; i < size; i++) {
    //percents[i] = votes[i]/sum;
    percents[i] = (votes[i]/static_cast<double>(sum))*100;
    // cout << "Percent: " << percents[i] << endl; //DEBUG
  } // end for-loop

} // end function


void print_results(string candidates[], int votes[], double percents[], int size) {

  int h = 0;
  string c;

  cout << setprecision(1) << fixed;
  cout << "Candidate\tVotes\tPercent\n";

  for (int i = 0; i < size; i++) {
    cout << setw(12) << left << candidates[i] << "\t";
    cout << right << votes[i] << "\t";
    cout << percents[i] << "%\n";
  } // end for-loop

  for (int i = 0; i < 19; i++){
    if (votes[i] > h){
      h = votes[i];
      c = candidates[i];
    } // end if-statement
  } // end for-loop

  cout << "\n[Winner, Vote Count] = [" << c << "," << h << "]" << endl;

} // end function

/* Execution Sample
Candidate       Votes   Percent
Rubio           24484   10.5%
Bush            3167    1.4%
Christie        10727   4.6%
Paul            4342    1.9%
O'Malley        18808   8.1%
Cruz            9371    4.0%
Clinton         22596   9.7%
Trump           13181   5.7%
Kasich          24838   10.7%
Sanders         4832    2.1%
Carson          11090   4.8%
Gilmore         17459   7.5%
Fiorina         6022    2.6%
Santorum        14700   6.3%
Huckabee        18559   8.0%
Graham          4298    1.8%
Jindal          15537   6.7%
Walker          1556    0.7%
Perry           7234    3.1%

[Winner, Vote Count] = [Kasich,24838]
*/
