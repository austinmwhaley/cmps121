//Author:		Austin Whaley, APW5450, 2019-01-12 11:41
//Class:		CMPSC 121
//Experiment:	01
//File:		cmpsc121/experiments/Experiment01/L001-apw5450.cpp
//Purpose:		Getting acquainted with the V.S.development environment.

#include <iostream>
using namespace std;
int main()
{
    // Declare variables that we will need later
    double length, width, height, volume, surface;

    // Prompt user for input
    cout << "Enter length, width, and height in inches: ";

    // Collect user input for the 3 variables declared previously
    cin >> length >> width >> height;

    // Volume and Surface Formulas
    volume = length * width * height;
    surface = length * width;

    // Display to user the answer for the above formulas
    cout << "For a box with length = " << length << ", width = " << ", height = " << height << endl;
    cout << "the volume is " << volume << " cubic inches and the surface is " << surface << " square inches" << endl;
    return 0;
}

/* Execution Sample:
Enter length, width, and height in inches: 5 5 4
For a box with length = 5, width = , height = 4
the volume is 100 cubic inches and the surface is 25 square inches
*/
