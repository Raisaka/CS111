/*************************************************************************
Jared Falcon
CS111
10/21/20

This program will only accept non-negative values and will reverse them.
 ************************************************************************/
#include <iostream>

using namespace std;

int main()
{

  int num;//user input
  int remainder = 0;//remainder set to 0
  
  //user input num
  cout << "Enter a non-negative number: ";
  cin >> num;
  
  while(num < 0)//if num is negative the user must enter another number
    {
      //display invalid num and enter again
      cout << "The number is invalid. Enter a non-negative number: ";
      cin >> num;
      
    }
  
  
  if(num == 0)//if num is 0, display 0
    {
      cout << num;
    }
  while(num != 0)//while num is not 0, stay in the loop 
    {
      remainder = num % 10;//remainder is stored
      cout << remainder;//remainder is displayed
      num /= 10;//whole value is divided by 10, and goes back up to the loop if the number is not 0
    }  
  cout << endl << endl;//makes new lines
  














  return 0;
}
