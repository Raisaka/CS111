/************************************************************************
Jared Falcon
CS 111
11/13/20

This program will bring up a menu with multiple options in order to 
manipulate an array. The program will be able to fill an array, print its 
contents as well as reversing it. It also uses functions to search for a key,
find the average, highest value as well as double the numbers in the array and 
showing a bar graph.
 ***********************************************************************/
#include <iostream>

using namespace std;

void fillArray(int ar[], int s);
void printArray(const int ar[], int s);
void reverseArray(int ar[], int s);
int search(const int ar[], int s, int key);
double findAvg(int ar[], int s);
int findHighest(const int ar[], int s);
void doubleArray(int ar[], int s);
void showBarGraph(const int ar[], int s);
int main()
{
  const int SIZE = 5;//size of array
  int AR[SIZE];//array with given size
  int input;//our input
  int key;//key to look for
  int index;//index of the array
  double Avg;//our average
  int Highest;//stores highest value

  /* fillArray(AR, SIZE);
  printArray(AR, SIZE);
  reverseArray(AR, SIZE);
  printArray(AR, SIZE);
  */
  do
    {
      /*cout << "=============" << endl;
      cout << "1: fill the array" << endl;
      cout << "2: print the array" << endl;
      cout << "3: reverse the contents of the array" << endl;
      cout << "10: sequential search" << endl;
      cout << "13: quit" << endl;
      cout << "=============" << endl;
      */
      cout << "----------------------------------------------------------------------" << endl;
      cout << "1) fill 2) print  3) reverse  4) average 5) highest  6) double 7) bar graph  10) sequential search  13) quit"<< endl;
      cout << "----------------------------------------------------------------------" << endl;
      
      cout << "Enter your choice: ";
      cin >> input;
      cout << endl;
      //this will be the cases from the menu above that can be accessed
      //each case calls a different function to perform its given task
      switch(input)
	{
	case 1: fillArray(AR, SIZE);//fills array
	  cout << endl;
	  break;
	case 2: printArray(AR, SIZE);//displays array 
	  cout << endl;
	  break;
	case 3: reverseArray(AR, SIZE);//reverses array
	  //	  cout << endl;
	  break;
	case 4: Avg = findAvg(AR, SIZE);//finds the average 
	  cout << "The average number is " << Avg << endl;
	  cout << endl;
	  break;
	case 5: Highest = findHighest(AR, SIZE);// finds the highest number
	  cout << "The highest number is " << Highest << endl;
	  cout << endl;
	  break;
	case 6: doubleArray(AR, SIZE);//doubles the numbers in the array 
	  // cout << endl;
	  break;
	case 7: showBarGraph(AR, SIZE);//shows a bar graph with stars 
	  break;
	case 10: 
	  cout << "Enter the key: ";
	  cin >> key;
	  cout << endl;
	  index = search(AR, SIZE, key);//returns the index where the key was found 
	  if(index == -1)//if returning value is -1 key was not found
	    {
	      cout << key << " was not found." << endl;
	    }
	  else//key was found 
	    {
	      cout << key << " was found at index " << index << endl;
	    } 
	  cout << endl;
	  break;
	default: //default case to reject values not in the menu
	  if(input != 13)//if the value is 13, we can quit the program, otherwise its invalid 
	    {
	      cout << "Invalid choice" << endl;
	      cout << endl;
	    }
	  
	}
    }while(input != 13);//quit program
    {
      cout << "Thank you for using the system!" << endl;
         
    }


  return 0;
}
/*****************************************************
ar[] is the array 
s is the size of the array

This function will fill our array with integer values
 *****************************************************/
void fillArray(int ar[], int s)
{
  for(int i = 0; i < s; i++)//for loop to fill array 
    {
      cout << "Enter a number: ";
      cin >> ar[i];
    }
}
/*****************************************************
const ar our array is not changing 
s for size

This funtion will display our array
 ****************************************************/
void printArray(const int ar[], int s)
{
  cout << "The numbers in the array are ";
  for(int i = 0; i < s; i++)//for loop to display array with a space 
    {
      cout << ar[i] << " ";
    }
  cout << endl;
}
/*****************************************************
ar[] used for the array
s for size

This function will reverse the array
 *****************************************************/
void reverseArray(int ar[], int s)
{
  int temp;//stores a temporary value
  for(int i = 0; i < s; i++, s--)//for loop to go from top to bottom and vice versa
    {
      temp = ar[i];//store first value in temp
      ar[i] = ar[s-1];// store last value in first index
      ar[s-1] = temp;// store temp in last index
      
    }
}
/*****************************************************
const ar[] not chaging our array
s for size
key for finding our value

THis function will return the index where our key was 
found and it will return -1 if not found.
 ***************************************************/
int search(const int ar[], int s, int key)
{
  for(int i = 0; i < s; i++)//for loop to go through array
    {
      if(ar[i] == key)//if key matches array value 
	{
	  return i;//return index
	}
    }
  return -1;//otherwise return -1(not found)
}
/*******************************************************
ar[] for the array
s for size

THis function will return the average value in the array/
 ******************************************************/
double findAvg(int ar[], int s)
{
  double avg = 0;//intialize avg
  
  for(int i = 0; i < s; i++)//for loop to go through and add all the values
    {
      avg += ar[i];//stores and adds all values in avg
    }
  return avg/s;//divide avg by size of the array and return it

}
/*****************************************************
const ar[] for the non changing array
s for size

THis fucntion will return the highest value found in
the array 
 ****************************************************/
int findHighest(const int ar[], int s)
{
  int High = 0;//initialize high to 0 being the highest index value
  for(int i = 1; i < s; i++)//for loop to go through the array and check each value
    {
      if(ar[i] > High)//if the second index value is higher
	{
	  High = ar[i];// high is now that index value
	}
    }
  return High;//return highest value

}
/*******************************************************
ar[] for the array 
s is the size

This function will double the numbers in the array
 ******************************************************/
void doubleArray(int ar[], int s)
{
  for(int i = 0; i < s; i++)//for loop to go through each value
    {
      ar[i]*=2;//multiply each index value by two
    }
}
/*********************************************************
const ar[] for the array that wont change
s for the size

THis fucnction will show a star which will represent a value of 10
 *********************************************************/
void showBarGraph(const int ar[], int s)
{
  for(int i = 0; i < s; i++)//for for each slot 
    {
      cout << "Slot " << i << ": ";//show each slot from 0
      for(int star = 1; star <= ar[i]/10; star++)//each star is a value of 10 
	{
	  cout << "*";//show star
	}
      cout << endl;
    }
  cout << endl;



}
