/**************************************************************************
Jared Falcon
CS111
11-02-20

This program will reject invalid inputs not in range which is set by a function
getInt() in input.h. The program will determine where the square root will start.
The number to be squared will be divided by top or bottom which ever is closer.
Finding the average and then finding the average again by adding our given number
and our average. This process will repeat itself 10 times using a for loop. 
***************************************************************************/
#include <iostream>
#include "input.h"//for using getInt()

using namespace std;

int main()
{
  int num;//stores number thats going to be squared
  int top;//top number
  int bot;//bottom number
  double ans;//stores a double variable 
  int sum;//stores integer to match top
  double avg;//stores the first average 
  double avg2;//stores second average
 
  //reject bad inputs using our getInt() function 
  cout << "Enter a postive number that you want to find the square root for: ";
  num = getInt(1, 9000000, "Enter a positive integer number between 1 and 9000000: ");//our range 1-9000000 and our message if input is invalid

  for(top = 1; top*top < num; top++)//this loop will make the top number go over 1 time above num
    {
      
      //cout << top << endl;
      if(top*top == num)//if the top number squared is the same as num
	{
	  ;//display nothing and store top
	}
    }
  bot = top - 1;//whatever top is, botttom is 1 less 
 
  //this will divide the initial number by the top and save it as a double
  ans = (double)num/top;
 
  //this will round the double variable ans and store it as an integer
  //if its == to the top number then the top is closer if not its the bottom
  sum = ans + 0.5;
 

  
  if(num/top == top)//automatically checks if the top is a perfect square
    {
      cout << top << " is the square root of " << num << endl;
    }
  else if(sum == top)//checks if the integer sum is == to the top
    {
      cout << "Start at " << top << endl;//start of at top
      avg = (double)num/top;//divide num and top to get average
      avg2 = (avg+top)/2;//add average and top and then divide by 2 to get second average
      
      for(int i = 0; i < 10; i++)//this for loop will run 10 times and make the square root more accurate
	{
	  avg = num/avg2;//avg is num divided by our second average 
	  avg2 = (avg+avg2)/2;//avg2 is avg + avg2 and then divided by 2
	}
      /*for(int i = 0; i < 10; i++)//this loop also works but it makes an unnecessary step
	{
	  avg2 = num/avg;
	  avg = (avg+avg2)/2;	  
	}
      */
      cout << "The square root of " << num << " is " << avg2 << endl;//displays num and the square root
      cout << "The square of the square root is " << avg2*avg2 << endl;//displays the the square root squared back to num
     
     
    }
  else//if top is not == to sum, then bottom is closer
    {
      //same process as above but using the bottom number
      cout << "Start at " << bot << endl;
      avg = (double)num/bot;
      avg2 = (avg+bot)/2;
      
      for(int i = 0; i < 10; i++)
        {
          avg = num/avg2;
          avg2 = (avg+avg2)/2;
        }
  
      cout << "The square root of " << num << " is " << avg2 << endl;
      cout << "The square of the square root is " << avg2*avg2 << endl;
     
     
    }
  cout << endl;//makes space for a new line 
  
  




  return 0;
}
