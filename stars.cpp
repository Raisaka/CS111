/*********************************************************
Jared Falcon
CS111
10/17/20

This program will display a certain ammount of stars and rows
entered by the user. It has to be greater than or equal to 1.
There will be spaces displayed in decreasing order and the 
stars will be in increasing order.
 *********************************************************/
#include <iostream>
#include <iomanip>//manipulators

using namespace std;

int main()
{

  int num;//stores the number of rows  
  
  //user enters number for rows
  cout << "Enter the number of rows: ";
  cin >> num;

  if(num >= 1)//num has to be 1 or greater for it to work
    {
      for(int row = 1; row <= num; row++)//row starts at 1 and ends at the value of num
	{
	  for(int space = num-1; space >= row; space--)//the amount of spaces will be reduced each row down
	    {
	      cout << " ";
	    }
	  for(int star = 1; star <= row; star++)//stars will display in each row, increasing every row by 1
	    {
	      cout << "*";
	    }
	  cout << endl;
          
        }
      cout << endl;
    }
  else//if the user enters 0 or a negative number
    {
      cout << "This program works for n >= 1 only" << endl;
cout << endl;
    }






  return 0;
}
