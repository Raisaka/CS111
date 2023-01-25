/**************************************************************************
Jared Falcon
CS111
10/11/20

This program will calculate the user's electric bill. It will ask them for 
the month and the current and previous readings. The program will reject 
invalid month inputs as well as invalid readings. The program will display 
how much energy the user used and how much they owe.
 *************************************************************************/
#include <iostream>
#include <iomanip>//use manipulators

using namespace std;

int main()
{
  string name;//stores user name
  char Enter;//makes the user press enter 
  int month;//stores the month
  int current;//stores current reading
  int previous;//stores previous reading
  int KWH;//stores total KWH used
  double due;//stores total amount due 

  //user enters their information for their bill
  cout << "Enter your first name: ";
  cin >> name;
  cin.ignore();//ignores the enter in the queue
  cout << endl;
  cout << "Welcome, " << name << "!" << endl;
  cout << "This program will ask for the month and current and previous meter readings then calculate your electric bill. Please press " << "\"ENTER\"" << " to continue." << endl;
  cin.get(Enter);//user has to press "Enter" to continue

  cout << "Enter the month: ";//enter month
  cin >> month;

  if(month <= 0 || month > 12)//checks for invalid month
    {
      cout << month << " is an invalid month!" << endl;
    }
  else//otherwise ask for the readings
    {
      cout << "Enter the current meter reading: ";
      cin >> current;
      cout << "Enter the previous meter reading: ";
      cin >> previous;
     
      KWH = current - previous;//stores the total KWH usage
     
      cout << fixed << setprecision(2);//shows 2 decimal points 
      if(current < 0 || previous < 0 || previous > current)//checks to see if the readings are invalid (negative, or if previous is bigger than current)
	{
	  cout << "The readings are invalid!" << endl;
	}
      else//if readings are good calculate the total
	{
	  if(month < 5 || month > 9)//checks if the month is not inbetween 5-9 for a flat rate
	    {
	      if(KWH <= 400)//if 400 or under, flat rate
		{
		  due = 8.50;//flat rate
		}
	      else if(KWH > 400)//otherwise if over 400, each watt will be charged extra
		{
		  due = (KWH - 400)*0.06575 + 8.50;//calcultion for the other months not 5-9
		}
	    }
	  else//if the months are 5-9
	    {
	      if(KWH <= 400)//flat rate
		{
		  due = 8.50;//flat rate
		}
	      else if(KWH > 400)//over 400
		{
		  due = (KWH - 400)*0.07525 + 8.50;//the rate increases if over 400 during these months
		}
	    }
	  cout << endl;//makes a new line
	  cout << "You consumed " << KWH << " KWH " << "and your amount due is $" << due << endl;//prints how much energy you used and how much you owe
	}
     
	  
    }


  

  cout << endl;//makes a new line 


  return 0;
}
