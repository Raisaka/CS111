/**************************************************************************
Jared Falcon
CS111
HW 2 part 4
10/1/20

This program will ask the user for two integers. One for hours and the 
other for minutes. It will display the angle the hands on the clock are
positioned at the given time.

 *************************************************************************/
#include <iostream>

using namespace std;

int main()
{

  int hours;//stores hours 
  int minutes;//stores minutes

  //asks the user to enter both hours and minutes
  cout << "Enter hours: ";
  cin >> hours;
  cout << "Enter minutes: ";
  cin >> minutes;
  

  cout << "The angle of the hour hand is : " << ((hours*60+minutes)%360)*.5 << endl;//using the mod operator, it gets the remaider of the calculation and then multiply it by .5 to get the exact angle, will show decimal point
  cout << "The angle of the minute hand is : " << minutes*6 << endl;//minutes multiplied by 6 will get this angle 
  cout << endl;















  return 0;
}
