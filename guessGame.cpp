/********************************************************************
Jared Falcon
CS111
10/21/20

This program will create a random number and the user will try to guess
what the number is. If the user input is greater than or less than. A
message will be displayed telling them "too high" or "too low" until
they guess it. 
 *******************************************************************/
#include <iostream>
#include <cstdlib>//used for rand
#include <iomanip>//manipulators

using namespace std;

int main()
{
  int guess;//user guess
  srand(time(0));//creates random number
  int num;//will store random number

  num = rand() % 100 + 1;//random number between 1-100 is stored in num

  //user enters guess
  cout << "Guess a number between 1 and 100. Enter your guess: ";
  cin >> guess;

  while(guess != num)//enter loop if they dont guess the number
    {
      if(guess > num)//guess > random number
	{
	  cout << right << " " << setw(28) << "Too high, try again. " << endl;//display number is too high
	}
      else if(guess < num)//guess < random number
	{
	  cout << right << " " << setw(27) << "Too low, try again. " << endl;// display number is too low
	}
      //keep guessing
      cout << "Enter your guess: ";
      cin >> guess;
    }
  if(guess == num)//user enters the correct random number
    {
      cout << "You guess it right!" << endl;//display message
    }
  cout << endl;//make new line

















  return 0;
}
