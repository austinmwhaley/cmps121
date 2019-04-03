//Author:	    Austin Whaley, APW5450, 2019-03-24
//Class:      CMPSC 121
//Experiment: 10
//File:       cmpsc121/experiments/Experiment10/M10E10_apw5450.cpp
//Purpose:    Develop Confidence in Functions

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
Price per board foot

Pine = $0.89
Fir =   1.09
Cedar   2.26
Maple   4.40
Oak     3.10


*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const double INCHESINLINEARFOOT = 12.0;
const double INCHESINONESQUAREFOOT = 144.0;
const double PINECOST = 0.89;
const double FIRCOST = 1.09;
const double CEDARCOST = 2.26;
const double MAPLECOST = 4.40;
const double OAKCOST = 3.10;

bool validateType(char t);
// Return true if t represents a valid wood type or false otherwise
double calcBoardFeet(double th, double wid, double len);
// calculate board feet where th = thickness in inches,
// wid = width in inches and len = length in feet
double calcCost(char type, int numP, double bf);
// calculate cost based on type, number of pieces and board feet
string getTypeName(char type);
// return name of wood type based on char representing type, eg P = Pine
void getData(char & woodType, int & numPieces, double &thickness,
             double & width,  double & length);
// Get data on sale


int main()
{
	char woodType, reply;
	int numPieces;
	double thickness, width, length;
	double cost, totalCost, boardFeet;
	string woodTypeName;
	cout << fixed << setprecision(2);
	do
	{
		totalCost = 0;
		do
		{
			getData(woodType, numPieces, thickness, width, length);
			if (woodType != 'T')
			{
				boardFeet = calcBoardFeet(thickness, width, length);
				cost = calcCost(woodType, numPieces, boardFeet);
				woodTypeName = getTypeName(woodType) + ", cost: $";
				cout << setw(3) << numPieces << setw(6) << thickness
                           << " X " << setw(6) << width << " X " << setw(6)
                           << length << " " << setw(14)
					<< woodTypeName  << cost << endl;
				totalCost+= cost;
			}
		}while (toupper(woodType) != 'T');
		cout << "Total cost: $" << totalCost << endl;
		cout << "More purchases?" << endl;
		cin >> reply;
	}while (toupper(reply) == 'Y');

}

//Function definitions here:

bool validateType(char t) {
  if (t == 'P' || t == 'F' || t == 'C' || t == 'M' || t == 'O') {
    return true;
  } else {
    return false;
  }
}

double calcBoardFeet(double th, double wid, double len) {
  return ( (th * wid * (len*12) )/144 );
}

double calcCost(char type, int numP, double bf) {
  switch(type) {
    case 'P': return (bf * PINECOST )*numP;
    case 'F': return (bf * FIRCOST  )*numP;
    case 'C': return (bf * CEDARCOST)*numP;
    case 'M': return (bf * MAPLECOST)*numP;
    case 'O': return (bf * OAKCOST  )*numP;
  }
}

string getTypeName(char type) {
  switch(type) {
    case 'P': return "Pine";
    case 'F': return "Fir";
    case 'C': return "Cedar";
    case 'M': return "Maple";
    case 'O': return "Oak";
  }
}

void getData(char & woodType, int & numPieces, double &thickness,
  double & width,  double & length) {
  // get data on sale?
  cout << "Enter Item: ";
  cin >> woodType;

  while (woodType != 'P' && woodType != 'F' && woodType != 'C' &&\
         woodType != 'M' && woodType != 'O' && woodType != 'T') {

    cout << woodType << " is not a valid type, reenter:" << endl;
    cin >> woodType;
  }

  if (woodType != 'T') {
    cout << "Enter number of pieces and thickness width and length\n";
    cin >> numPieces >> thickness >> width >> length;
  } else {
    numPieces, thickness, width, length = 0;
  }
}


/*
Enter Item: O
Enter number of pieces and thickness width and length
100 2.5 3 20
100  2.50 X   3.00 X  20.00   Oak, cost: $3875.00
Enter Item: T
Total cost: $3875.00
More purchases?
n

*/





















//
