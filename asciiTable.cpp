/**********************************************************
Jared Falcon
CS111
10/14/20

This program will display the ascii characters from 25 through
126. It will start a new line every 14 characters. 
 *********************************************************/
#include <iostream>

using namespace std;

int main()
{

  int count = 0;//counter for making a new line after 14
  for(int ascii = 35; ascii <= 126; ascii++)//ascii starting at 25 going to 126 by 1 
    {
      cout << (char)ascii << " ";//display the ascii CHARACTER and a space 
      count++;// increase count by every character 
      
      if(count == 14)// once count reaches 14, display a new line
	{
	  
	  cout << endl;//new line
	  count = 0;// reset counter every 14 characters 
	}
      
    }
  cout << endl;//new line
  
  
  
  return 0;
}
