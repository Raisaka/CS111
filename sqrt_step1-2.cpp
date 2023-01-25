/**************************************************************************
Jared Falcon
CS111
10-4-2020

This program will receive a number from the user and then using a for loop
it will determine to TOP and BOTTOM number. Which would be closer to the 
square root of the number. 
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

  cout << "Enter Num: " ;
  cin >> num;

  for(top = 1; top*top < num; top++)//this loop will make the top number go over 1 time above num
    {
      
      //cout << top << endl;
      if(top*top == num)//if the top number squared is the same as num
	{
	  ;//display nothing and store top
	}
    }
  bot = top - 1;//whatever top is, botttom is 1 less 
  cout << "Top is " << top << endl;
  cout << "Bottom is " << bot << endl;
  //ask the user to enter three integers 
  /*
  cout << "Num = ";
  cin >> num;
  cout << "Top = " ;
  cin >> top;
  cout << "Bottom = ";
  cin >> bot;
  */
  //this will divide the initial number by the top and save it as a double
  ans = (double)num/top;
 
  //this will round the double variable ans and store it as an integer
  //if its == to the top number then the top is closer if not its the bottom
  sum = ans + 0.5;
 

  
  if(num/top == top)//automatically checks if the top is a perfect square
    {
      cout << "Between " << top << " and " << bot << ", " << top << " is closer." << endl;
	// cout << "Top is closer to the square root of " << num << endl;
    }
  else if(sum == top)//checks if the integer sum is == to the top
    {
      cout << "Between " << top << " and " << bot << ", " << top << " is closer." << endl;
      // cout << "Top is closer to the square root of " << num << endl;
    }
  else//if top is not == to sum, then bottom is closer
    {
      cout << "Between " << top << " and " << bot << ", " << bot << " is closer." << endl;
      //cout << "Bottom is closer to the square root of " << num << endl;
    }
  cout << endl;//makes space for a new line 
  





  return 0;
}
