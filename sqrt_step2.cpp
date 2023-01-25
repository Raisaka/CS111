/**************************************************************************
Jared Falcon
CS111
10-4-2020

This program will determine between two numbers (top and bottom)
which is closer to the square root of the initial given number by the user.
***************************************************************************/
#include <iostream>


using namespace std;

int main()
{
  int num;//stores number thats going to be squared
  int top;//top number
  int bot;//bottom number
  double ans;//stores a double variable 
  int sum;//stores integer to match top


  //ask the user to enter three integers 
  cout << "Num = ";
  cin >> num;
  cout << "Top = " ;
  cin >> top;
  cout << "Bottom = ";
  cin >> bot;

  //this will divide the initial number by the top and save it as a double
  ans = (double)num/top;
 
  //this will round the double variable ans and store it as an integer
  //if its == to the top number then the top is closer if not its the bottom
  sum = ans + 0.5;
 

  
  if(num/top == top)//automatically checks if the top is a perfect square
    {
      cout << "Top is closer to the square root of " << num << endl;
    }
  else if(sum == top)//checks if the integer sum is == to the top
    {
      cout << "Top is closer to the square root of " << num << endl;
    }
  else//if top is not == to sum, then bottom is closer
    {
      cout << "Bottom is closer to the square root of " << num << endl;
    }
  cout << endl;//makes space for a new line 






  return 0;
}
