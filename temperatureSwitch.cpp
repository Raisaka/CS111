/*********************************************************************
Jared Falcon
CS111
10/11/20

This program will use a switch statement to convert temperatures, 
Fahrenheit and Celsius. It will take both lower and uppercase characters
for the initial temperature. It will reject any other characters.
 ********************************************************************/
#include <iostream>
#include <iomanip>//used for manipulators

using namespace std;

int main()
{
  char temp;//stores the type of temperature as a character 
  int F;//stores Fahrenheit temperature
  int C;//stores Celsius temperature
  double Fah;//stores the conversion from Fahrenheit to Celsius
  double Cel;//stores the conversion form Celsius to Fahrenheit

  //asks the user for the temp
  cout << "Which temperature do you have? Enter F for Fahrenheit or C for Celsius?: ";
  cin >> temp;
  cout << fixed << setprecision(2);//shows 2 decimal points
  switch(temp)//switch checking cases entered for temp
    {
    case 'f'://Fahrenheit in lowercase
    case 'F'://Fahrenheit in uppercae
      cout << "Enter a temperature in Fahrenheit: ";
      cin >> F;
      Fah = (F-32)*5/9;//stores F to C calculation
      cout << F << " Fahrenheit " << "= " << Fah << " Celsius" << endl;//dislplays the conversion
      break;//stops the program 
    case 'c'://Celsius in lowercase
    case 'C'://Celsius in uppercase
      cout << "Enter a temperature in Celsius: ";
      cin >> C;
      Cel = (9.0/5*C+32);//stores C to F calculation
      cout << C << " Celsius " << "= " << Cel << " Fahrenheit" << endl;//displays conversion
      break;//stops program
    default://if temp does not match any of the cases it will display invalid 
      cout << "Invalid choice!" << endl;
    }
  cout << endl;//makes a new line



  return 0;
}
