/*****************************************************************************
Jared Falcon
This template was written by Kazumi Slott for CS111
11-01-20

getInt asks for an integer and rejects bad inputs outside the range.
getDouble asks for a decimal number and rejects bad inputs outside the range.
getYN asks for Y or N and reject bad inputs other than Y, y, N or n.
*****************************************************************************/
#include <iostream>
using namespace std;

/******************************************************************************                                                               
min is the minimum value accepted                                                                                                             
max is the maxmum value accepted                                                                                                             
msg is the message shown when the user's input was outside the range.                                                                        
                                                                                                                                              
This function will read an integer number and keeps asking to enter a new number                                                             
as long as the user enters a number outside the range. It will return a number 
within the range (between min and max inclusive).                                                                                    
*******************************************************************************/
int getInt(int min, int max, string msg)
{
  int n; //user's input
  cin >> n;

  while(n < min || n > max) // the user's input was outside the range
    {
      cout << msg;  //show the message to the user
      cin >> n;     //read a new input
    }

  return n; //return a good value that is within the range (between min and max enclusive)
}

/******************************************************************************                                                               
min is the minimum value accepted
max is the maxmum value accepted
msg is the message shown when the user's input was outside the range.

This function will read a double number and keeps asking to enter a new number
as long as the user enters a number outside the range. It will return a number
within the range (between min and max inclusive).
*******************************************************************************/
                                                                                                                                            
double getDouble(double min, double max, string msg)                                                                                                          
{                                                                                                                                              
//Mimic getInt() above
  double input;
  cin >> input;

  while(input < min || input > max) // the user's input was outside the range
    {
      cout << msg;  //show the message to the user
      cin >> input;     //read a new input
    }

  return input; //return a value in range                                                                                                             
                                                                                                                                               
}


/******************************************************************************                                                               
msg is the message shown when the user inputs a character other than Y, y, N or N.                                                                                                                                           

The function will return ans which has Y or N stored in it. The function will also
convert y and n into capitals so it can return it. 
*******************************************************************************/

char getYN(string msg)
{
  char ans;
  cin >> ans;
  if(ans == 'y' || ans == 'n')
    {
      ans = ans - 32;
    }
  
  while(ans != 'Y' && ans != 'N')
    {
      cout << msg;
      cin >> ans;
      if(ans == 'y' || ans == 'n')
	{
	  ans = ans - 32;
	}

    }
  return ans;
  /*As long as the user enters characters other than Y, y, N, or n, keep asking. 
If the user enters a lowercase y or n, convert it to the uppercase Y or N.
This function returns either uppercase Y or N.
  */
}


