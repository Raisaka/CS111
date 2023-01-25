/***********************************************************************
Jared Falcon
CS111
11/01/20

The program will calculate the user's odds of winning or losing. It will
reject bad inputs negative and over the set value of games.
The function playGame() will simulate a simple game of craps, it
will roll two die and the program will check if they win or
lose depending on what they roll. The function will return true or false. 
************************************************************************/
#include <iostream>
#include <cstdlib>//using srand
#include <iomanip>//manipulators
#include "input.h"//include funtion for rejecting values

using namespace std;
int rollDice(int roll);//function for rolling two die
bool playGame();//function for playing a game of craps

int main()
{
  srand(time(0));//generates random rumbers
  int games;//stores games played
  bool TorF;//stores true or false from playGame
  double yes;//stores number of wins/true
  double no;//stores number of loses/false
  double WIN;//stores the win percentage
  double LOSE;//stores the lose percentage

  //asks user for games
  cout << "How many games do you want to play?: ";
  games = getInt(1, 100000000, "You need to input a number between 1 and 100000000: ");//getInt() is a function in input.h to reject integer values, we store it in games
  //TorF = playGame();
  
  for(int i = 0; i < games; i++)//this for loop will run how many games the user wants
   {
     TorF = playGame();//creates a new game everytime the for loop runs
     
     if(TorF == true)//if true = win
       {
	 yes++;//add win
       }
     else//false = loss
       {
	 no++;//add loss
       }
   }
  WIN = yes/games;//stores win percentage
  LOSE = no/games;//stores loss percentage


  //  WIN = (double)yes/games;//stores win percentage
  // LOSE = (double)no/games;//stores loss percentage
  cout << fixed << setprecision(3);//will make 3 decimal places show up
  cout << right << " " << setw(9) << "win %" << setw(10) << "lose %" << endl;//line them up and multiply WIN by 100 for percentage
  cout << right << " " << setw(9) <<  WIN*100 << setw(10) << LOSE*100 << endl;//line them up and multiply LOSE by 100 for percentage

  cout << endl;//new line
  //cout << "lose % " << LOSE*100 << endl;
  
 return 0;
}
/***************************************
int ans = stores first roll
int ans2;//stores any roll after the first
int rolls;//the parameter needed to store our roll

This function plays one game of craps
and return true for a win or false for a loss.
**************************************/
bool playGame()
{
  //srand(time(0));//creates random numbers
  int ans;//stores the first roll
  int ans2;//stores any roll after the first 
  int rolls;//the parameter needed to store our roll 
  ans = rollDice(rolls);//store our roll in ans for later 
//  cout << ans << endl;
  if(ans == 7 || ans  == 11)//first condition, user rolls a 7 or 11 they win 
    {
      return true;
// cout << "=== WIN ===" << endl;
    
    }
  else if(ans == 2 || ans == 3 || ans == 12)//second condition, user rolls a 2, 3, 12 they lose
    {
      return false;
//    cout << "=== LOSE ===" << endl;
    }
  else// any other number, the program will keep rolling 
    {
      // cout << "Taiga is the cutest girl ever!" << endl;
      do//the do while loop will make sure to keep rolling as long as the condition is true
	{
	  ans2 = rollDice(rolls);//make a second instance of our die
//	  cout << ans2 << endl;//display our roll
	}while( (ans2 != ans) && (ans2 != 7) );//if the first roll is not equal to our next roll or if its not 7 keep rolling
      {
	if(ans2 == ans)//if we roll the same as our first roll, we win
	  {
            return true;
//          cout << "=== WIN ===" << endl;
	  }
	else if(ans2 == 7)//if we roll a 7 before our second roll equals our first, we lose
	  {
            return false;
//          cout << "=== LOSE ===" << endl;
	  }


      }
    

    }


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
