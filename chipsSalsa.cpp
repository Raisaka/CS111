/***************************************************************
Jared Falcon
CS111
11/13/20

This program will simulate a salsa sales program that will use 
two arrays of the same size. One array stores the salsa names
and the other will store the amount of times they were sold.
 **************************************************************/

#include <iostream>
#include <iomanip>
#include "input.h"

using namespace std;
void fillJarsSoldArray(string salsas[], int sales[], int s);
void printSales(string salsas[], int sales[], int s);
int getTotal(int sales[], int s);
void getHighestLowestSelling(int sales[], int s, int& highInd, int& lowInd);

int main()
{
  const int SIZE = 5;//for our array size
  string SALSAS[] = {"mild", "medium", "sweet", "hot", "zesty"};//initialize array with given salsa names
  int SALES[SIZE];//sales array set to size 5
  int total;//stores our total salsa sales
  int HIGHEST;//stores index of highest selling salsa
  int LOWEST;//stores index of lowest selling salsa


  fillJarsSoldArray(SALSAS, SALES, SIZE);//call fillJars function
  printSales(SALSAS, SALES, SIZE);//print the salsa sales
  total = getTotal(SALES, SIZE);//store the total salsa sales in total
  getHighestLowestSelling(SALES, SIZE, HIGHEST, LOWEST);//finds highest and lowest selling salsas
  
  cout << endl;
  cout << "The total number of jars sold is " << total << endl;//display total
  cout << "The highest selling type is " << SALSAS[HIGHEST] << endl;//display highest selling salsa
  cout << "The lowest selling type is " << SALSAS[LOWEST] << endl;;//display lowest selling salsa
  cout << endl;

  return 0;
}
/*******************************************************
salsas[] is our salsa names array
sales[] is our sales array
s is for the array size

THis function will fill the amount of salsas sold and reject
invalid values.
 ******************************************************/
void fillJarsSoldArray(string salsas[], int sales[], int s)
{
  int amount;// used to call our getInt() fucntion to reject values
  
  for(int i = 0; i < s; i++)//for loop to go through each salsa name a give them a sales amount
    {
      cout << "Enter the number of jars sold for " << salsas[i] << ": ";//display each salsa
      amount = getInt(0, 1000000, "Invalid. Enter a number between 0 and 1000000: ");//function to reject values
      cout << endl;
      sales[i] = amount;//store the amount entered in each array slot for sales[] array
    }

}
/*********************************************************
salsas[] is our salsa names array
sales[] is our sales array
s is for the array size

THis fucntion will print the sales of each salsa 
 ********************************************************/
void printSales(string salsas[], int sales[], int s)
{
  for(int i = 0; i < s; i++)//for loop to go through each array and display its information
    {
      cout << left << setw(10) << salsas[i];
      cout << right << setw(5) << sales[i] << endl;
    }

}
/************************************************************
sales[] is our sales array
s is for the array size

This fucntion will return the total of all salsa sales
 ***********************************************************/
int getTotal(int sales[], int s)
{
  int total = 0;//store total sales
  for(int i = 0; i < s; i++)//for loop to go though the array 
    {
      total += sales[i];//add total from each slot to total 
    }
  return total;//return total

}
/************************************************************
sales[] is our sales array
s is for the array size
highInd to store the index of highest selling salsa
lowInd  to store the index of lowest selling salsa

This function will compare sales of all the salsas and find the
highest and lowest selling salsas index
 ***********************************************************/
void getHighestLowestSelling(int sales[], int s, int& highInd, int& lowInd)
{
  int highest = 0;//store highest selling salsa index
  int lowest = 0;//stores lowest selling salsa index
  for(int i = 1; i < s; i++)//for loop to compare the highest
    {
      if(sales[i] > sales[highest])//if another index has a higher value than index 0, that value is now the highest
	{
	  highest = sales[i];// stores new value in highest
	  highInd = i;//highInd stores index for highest
	}
      if(sales[i] < sales[lowest])//same as the other except lowest
	{
	  lowest = sales[i];//stores lowest value to compare
	  lowInd = i;//stores lowest index
	}
    }
}
