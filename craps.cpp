/*********************************************************
Jared Falcon
CS111
10/29/20

This program will simulate a simple game of craps. The user
will roll two die and the program will check if they win or
lose depending on what they roll. 
 ********************************************************/
#include <iostream>
#include <cstdlib>//using srand

using namespace std;
int rollDice(int roll);//fucntion for rolling two die

int main()
{
  srand(time(0));//creates random numbers
  int ans;//stores the first roll
  int ans2;//stores any roll after the first 
  int rolls;//the parameter needed to store our roll 
  ans = rollDice(rolls);//store our roll in ans for later 
  cout << ans << endl;
  if(ans == 7 || ans  == 11)//first condition, user rolls a 7 or 11 they win 
    {
      cout << "=== WIN ===" << endl;
    }
  else if(ans == 2 || ans == 3 || ans == 12)//second condition, user rolls a 2, 3, 12 they lose
    {
      cout << "=== LOSE ===" << endl;
    }
  else// any other number, the program will keep rolling 
    {
      // cout << "Taiga is the cutest girl ever!" << endl;
      do//the do while loop will make sure to keep rolling as long as the condition is true
	{
	  ans2 = rollDice(rolls);//make a second instance of our die
	  cout << ans2 << endl;//display our roll
	}while( (ans2 != ans) && (ans2 != 7) );//if the first roll is not equal to our next roll or if its not 7 keep rolling
      {
	if(ans2 == ans)//if we roll the same as our first roll, we win
	  {
	    cout << "=== WIN ===" << endl;
	  }
	else if(ans2 == 7)//if we roll a 7 before our second roll equals our first, we lose
	  {
	    cout << "=== LOSE ===" << endl;
	  }

	//cout << "LOSE" << endl;
      }
    

    }


  return 0;
}
/*****************************************
int roll will store our random die rolls

the function will return the sum of our two
rolls
 ****************************************/
int rollDice(int roll)
{
  
  roll = (rand() % 6 + 1) + (rand() % 6 + 1);//will generate random numbers 1-6 like a dice
  return roll;//return sum


}
