/****************************************************************
Jared Falcon
CS111
10/14/20

This program will output the days worked as well as the pay earned
starting at 0.01 and double each day worked. The program will reject
negative inputs as well as 0. The total earned will be displayed at
the end of the program.
 ****************************************************************/
#include <iostream>
#include <iomanip>//used for manipulators

using namespace std;

int main()
{

  int days;//stores the days worked
  double pay = 0.01;//starting pay
  double total = 0;//stores the total

  //user enters the days
  cout << "Enter the number of days you worked: ";
  cin >> days;
  
  if(days <= 0)//will reject 0 and negative numbers 
    {
      cout << days << " is invalid. Thank you for using the system." << endl;//error message
      cout << endl;//new line
    }
  else//valid input display days and money earned
    {
      cout << endl;//new line
      cout << setw(10) << "Days" << setw(15) << "Pay" << endl;//display Days and Pay using setw 
      
      for(int i = 0; i < 25; i++)//this will loop 25 times and display -
	{
	  cout << "-";
	}
      cout << endl;
      cout << fixed << setprecision(2);// used to display 2 decimal points
      for(int j = 1; j <= days; j++)//will loop the same amount of days
	{
	  cout << setw(10) << j << setw(15) << pay << endl;//display number of days 1, 2, 3 etc and pay doubled 
	  total += pay;//stores the total earned
	  pay += pay;//doubles pay each time it loops	  
	}
      for(int i = 0; i < 25; i++)//this will loop 25 times and display -
        {
          cout << "-";
	}
      cout << endl;//new line
      cout << setw(10) << "Total" << setw(15) << total << endl;//display the total using setw
      cout << endl;//new line

    }








  return 0;
}
