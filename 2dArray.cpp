/*****************************************************************
Jared Falcon
CS111
11-19-20

This program will fill a 2D array with students test scores. A 
fucntion will show the table with the results of their tests. The
table will also show the average for each test as well as each 
students average. 
*****************************************************************/ 
#include <iostream>
#include <iomanip>
using namespace std;

//declare 2 constants for the sizes of the 2 dimensional array
const int NUM_STU = 5; 
const int NUM_TEST = 3;
void showTable(const int scores[][NUM_TEST]);
void fillArray(int scores[NUM_STU][NUM_TEST]);
int main()
{
  //declare the 2 dimensional array and initialize the array using the initialization list
  //  int scores[NUM_STU][NUM_TEST] = { {45, 67, 78}, {78, 88, 56}, {86, 96, 78}, {78, 77, 67}, {67, 57, 57} };

  int scores[NUM_STU][NUM_TEST];//2D array to for number of tests and scores
  fillArray(scores);//function for filling array
  showTable(scores);//displays scores table

  return 0;
}
/***********************************************************
int scores[][NUM_TEST] to read the scores
int total to store the test average
average to store the students tests average

This function will fill the array with test scores from each student.
 **********************************************************/
void showTable(const int scores[][NUM_TEST])
{
  int total;//store tests scores
  int average;//stores students scores
  //Show the lables for the table
  cout << setw(8) << "Test#" << setw(8) << "Stu 1" << setw(8) << "Stu 2" << setw(8) << "Stu 3" 
       << setw(8) << "Stu 4" << setw(8) << "Stu 5" << setw(10) << "Average" << endl;

  //????????? Show the table using a nested for loop here
  for(int test = 0; test < NUM_TEST; test++)//shows the test in order
    {
      total = 0;//start test total at 0
      cout << setw(8) << test + 1;
      for(int stu = 0; stu < NUM_STU; stu++)//shows each score
	{
	  total = total + scores[stu][test];//adds each score from each test
	  
	  cout << setw(8) << scores[stu][test];//show each test score
	  //total = total + scores[stu][test];
	  //cout << "total";
	  // cout << setw(10) << (double)total/NUM_STU;
	}
      
      cout << fixed << setprecision(1);
      cout << setw(10) << (double)total/NUM_STU;//show the test average
      cout << endl;
    }
  cout << "Average" << setw(9);
  for(int stu = 0; stu < NUM_STU; stu++)//will go through each students scores
    {
      average = 0;//start average at 0
      for(int test = 0; test < NUM_TEST; test++)//each student will get an average 
	{
	  average = average + scores[stu][test];//adds all three test average for each student 
	  //cout << setw(10) << average << endl;;
	}
    
      cout << (double)average/NUM_TEST << setw(8);//average test score for each student
      //      cout << endl;
    }
  cout << endl << endl;
}
/**********************************************************************
int scores[NUM_STU][NUM_TEST] to fill in the slots of the array

This fucntion will be able to fill a 2D array with students test scores.
 *********************************************************************/
void fillArray(int scores[NUM_STU][NUM_TEST])
{
  
  for(int test = 0; test < NUM_TEST; test++)//starts at test 1
    {
      cout << "Enter scores for Test #" << test + 1 << endl;// first test
      
      for(int stu = 0; stu < NUM_STU; stu++)//give each student a score for test 1 and so on
	{
	  cout << "     Student #" << stu + 1 << ": ";
	  cin >> scores[stu][test];//fill the array with the scores
	}
      cout << endl;
    }

  //  cout << endl;
}
