/******************************************************
Jared Falcon
CS111
11/18/20

This program will fill an array of size 10 to random numbers
from 0-100. It will be able to print the array and sort the 
array in descending order (largest to smallest).
 *****************************************************/
#include <iostream>
#include <cstdlib>

using namespace std;

void selectionSort(int array[], int N);
void fillArray(int array[], int s);
void printArray(const int array[], int s);

int main()
{
  const int SIZE = 10;
  int AR[SIZE];//declare an array using SIZE
  srand(time(0));//used for random numbers

  //fill the array with 10 random numbers between 0 and 100
  fillArray(AR, SIZE);//fills the array
  printArray(AR, SIZE);//prints unsorted array
  selectionSort(AR, SIZE);//sorts array in descending order
  printArray(AR, SIZE);//prints sorted array
  
  
  
  
  return 0;
}


//change this function so it will sort the numbers in descending order: largest down to smallest
/******************************************************
array[] used for our array
N for size of the array
smallIndex used for storing the smaller number in the array
temp used for storing a number temporarly

This function will sort the array in descending order.
 *****************************************************/
void selectionSort(int array[], int N) 
{
  int smallIndx; //the index of the smallest value
  int temp; //temporary variable that holds the smallest value

  //last is the last index in unsorted portion
  for(int last = N-1; last >= 1; last--) 
    {
      smallIndx = 0; //assume the first item is the smallest
      //find the smallest in unsorted portion ([0..last])
      for(int i = 1; i <= last; i++) 
	{
	  if(array[i] < array[smallIndx]) //The current item is smaller 
	    smallIndx = i;
	}

      //swap the smallest  with the last item in the unsorted portion
      temp = array[smallIndx]; 
      array[smallIndx] = array[last]; 
      array[last] = temp;
    } 
}
/*********************************************************
array[] used for our array
s for size of the array
random used to store and fill our array with random numbers

This function will fill our array with random numbers.
 ********************************************************/
void fillArray(int array[], int s)
{
  int random;//stores random numbers
  
  for(int i = 0; i < s; i++)//loop to go through the array
    {
      random = rand() % 100 + 1;//creates and instance of a random number from 0-100
      array[i] = random;//fill the array with a random number
    }
}
/***********************************************************
array[] used for our array
s for size of the array

This fucntion will print our filled array with the random numbers.
 **********************************************************/
void printArray(const int array[], int s)
{
  for(int i = 0; i < s; i++)//loop to go through the array
    {
      cout << array[i] << " ";//print 10 random numbers from 0-100
    }
  cout << endl;
}
