/**************************************************************************
Jared Falcon
CS111
10/22/20

This program will reject any negative values. It will take ages until the user
exits using -1. The program will output the average age, amount of minors and 
adults. It will also display the oldest and youngest age. If no ages were
entered a message will display saying so.
 *************************************************************************/
#include <iostream>

using namespace std;

int main()
{

  int age;//takes ages
  double avg = 0;//adds up the ages
  int total = 0;//add up the number of people
  int minors = 0;//add up only minors
  int adults = 0;//adds up only adults
  int oldest = 0;//stores oldest age
  int youngest = 0;//stores youngest age

  cout << "Enter an age: ";
  cin >> age;

  while(age >= 0)//if the age is 0 or greater enter loop
    {
      total++;//add up people
      avg += age;//add up ages
     
      if(total == 1)//if there is at least one age, set it to both youngest and oldest
	{
	  youngest = age;
	  oldest = age;
	
	}
      else//otherwise keep comparing until the last age is entered 
	{
	  if(age < youngest)//compares youngest age and sets it to youngest
	    {
	      youngest = age;
	    }
	  if(age > oldest)//compares oldest age
	    {
	      oldest = age;
	    }
	}
      if(age < 18)//if age is less than 18, increase minors
	{
	  minors++;
	}
      else if(age >= 18)//if age is 18 or more increase adults
	{
	  adults++;
	}
      cout << "Enter an age: ";// keep entering an age until a negative number is entered
      cin >> age;
      
    }  
  cout << endl;//new line
  if(total == 0)//if no ages were entered, display message
    {
      cout << "No ages were entered" << endl;
    }
  else//otherswise display the information
    {
      cout << avg / total << "(average)" << endl;
      cout << minors << "(minors)" << endl;
      cout << adults << "(adults)" << endl;
      cout << oldest << "(oldest)" << endl;
      cout << youngest << "(youngest)" << endl;
    }
  cout << endl;//new line


  return 0;
}
