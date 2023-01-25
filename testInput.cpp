/*****************************************************************************
Jared Falcon
This template was written by Kazumi Slott for CS111
11-01-20

This main tests getInt(), getDouble() and getYN() in input.h
*****************************************************************************/
#include <iostream>
using namespace std;
#include "input.h"//include input functions

int main()
{
  int age;//stores getInt()
  int test;//stores getInt() for test
  double GPA;//stores getDouble()
  char ANS;//stores getYN()

  //input an age with the set range and default message if bad input
  cout << "Enter an age: ";
  age = getInt(0, 200, "An age must be between 0 and 200. Enter again: ");
  cout << "age = " << age << endl;
  cout << endl;
  //input a test score with the set range and default message if bad input
  cout << "Enter a test score: ";
  test = getInt(0, 100, "Test score must be between 0 and 100. Enter again: ");
  cout << "score = " << test << endl;
  //Test getInt()
  //get a test score. It should be between 0 and 100.
  cout << endl;
  //input a double number for GPA within range and default message if bad input
  cout << "Enter your GPA: ";
  GPA = getDouble(0.00, 4.00, "A GPA must be between 0.00 and 4.00. Enter again: ");
  cout << "GPA = " << GPA << endl;
  cout << endl;
  //Test getDouble()
  //get a gpa. It should be between 0.00 and 4.00.
  
  //input Y or N, if input is y or n, the function will convert it to Y or N, display message if bad input
  cout << "Are you a college student? Enter Y or N: ";
  ANS = getYN("Your response must be Y or N. Enter again: ");
  cout << "ans = " << ANS << endl;
  //Test getYN()
  //Ask if the user is a college student. It should only accept Y, y, N or n.
  //getYN() returns Y or N only.
  cout << endl;

  return 0;
}
