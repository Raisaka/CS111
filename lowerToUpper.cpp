/*************************************************************
Jared Falcon
CS111
HW 2 part 1
10/1/20

This program will convert lowercase letters into uppercase. 

*************************************************************/
#include <iostream>

using namespace std;

int main()
{
  char lower; //variable used to enter a character (lowercase letter)
  char upper;// variable used to store the uppercase letter 

  //ask the use to enter a lowercase letter 
  cout << "Enter a lowercase letter: "; 
  cin >> lower;
  upper = lower - 32;// upper is used to store the uppercase letter (lower = whatever ascii value and minus 32 will get the uppercase letter)

  cout << "The uppercase letter is " << upper << "." << endl;//formated with a period at the end
  cout << endl;//leave a blank space at the end










  return 0;
}
