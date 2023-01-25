/*******************************************************************
Jared Falcon
CS111
HW 2 part 3
10/1/20

This program will ask the user to enter a time in seconds and it 
will convert the seonds into hours, minutes, and remaining seconds.

 *****************************************************************/
#include <iostream>

using namespace std;

int main()
{
  int seconds;//stores initial seconds
  int hours;//stores hours
  int minutes;//stores minutes
  int second;//stores remaining seconds 

  //asks the user to enter a time in seconds
  cout << "Enter a time in seconds: ";
  cin >> seconds;
  cout << endl;//makes space for a new line

  cout << seconds;//will make the initial value of seconds print before its converted 
  hours = seconds/3600;//divides seconds into the appropriate amount of hours
  seconds = seconds%3600;//stores the remaining seconds
  minutes = seconds/60;//divides seconds into the appropriate amount of minutes
  seconds = seconds%60;//stores the remaining seconds
  second = seconds/1;//remaining seconds divided by 1
  seconds = seconds%1;//keeps remaining seconds 

  cout << " seconds" << " = " << hours << " hours " << minutes << " minutes " << second << " seconds " << endl;//prints the conversion of seconds into hours, minutes and remaining seconds
  cout << endl;//makes space for a new line 










  return 0;

}
