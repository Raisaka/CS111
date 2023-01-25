/******************************************************************
Jared Falcon
CS111
HW 2 part 2
10/1/20
This prigram will ask the user to enter a temperature in Celcius 
and convert it into Fahrenheit and round it to the nearest integer.
 *****************************************************************/
#include <iostream>

using namespace std;

int main()
{
  int C;// variable to store the user input for Celcius
  int F;// variable to store the conversion from Celcius to Fahrenheit

  //ask the use to enter a temp in C
  cout << "Enter a temperature in Celcius: ";
  cin >> C;
  cout << endl;//makes space for a new line
  
  F = (9.0/5*C+32)+.5;//conversion for Celcius to Fahrenheit (the .5 makes sure the value is either rounded up or down) it will be stored as an integer in F

  
  cout << C << " C" << " = " << F << " F" << endl;//prints result with spaces
  cout << endl;// makes space for a new line







  return 0;
}
