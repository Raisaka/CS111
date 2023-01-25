/*******************************************************************
Jared Falcon
CS111
10/22/20

This program will display 3 or more fibonacci numbers and will reject
any inputs that are less than 3.
 ******************************************************************/
#include <iostream>

using namespace std;

int main()
{

  int fib;//stores fibonacci number
  int n1 = 0;//first fib number
  int n2 = 1;//second fib number
  int sum = 0;//stores the sum of the fib numbers
  do//statement to be asked if input is rejected 
    {
      cout << "Enter the number of fibonacci numbers you want to see (N >= 3): ";
      cin >> fib;
    }
  while(fib < 3);//if input is less than 3, input will be rejected 
  {
    cout << endl;
    cout << n1 << " " << n2 << " ";//display first fib numbers
    for(int i = 0; i < fib-2; i++)//for loop to display the remaining fib numbers
      {//fib-2 to account for the first two fib numbers
	sum = n1 + n2;// stores the sum for the first fib numbers
	cout << sum << " ";//display sum
	n1 = n2;// set n1 to n2
	n2 = sum;// set n2 to the sum 
	
      }
    
  }
  cout << endl << endl;//new line
  


  return 0;
}
