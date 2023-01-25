#include <iostream>

using namespace std;
void showProgInfo();
void getInfo(string& person, char& G, int& Age);
bool verifyEligibility(char GG, int Old);
void printLetter(string NAME, char GGG, int age);
int main()
{
  string name;
  char g;
  int age;
  
  showProgInfo();
  getInfo(name, g, age);
  verifyEligibility(g, age);
  printLetter(name, g, age);
  

  return 0;
}
void showProgInfo()
{
  cout << "********************************************************************" << endl;
  cout << "This program will tell you if you are eligible to join the military." << endl;
  cout << "********************************************************************" << endl;

}
void getInfo(string& person, char& G, int& Age)
{

  cout << "Enter your first name: " << endl;
  cin >> person;
  cout << "Enter your gender m/f: " << endl;
  cin >> G;
  cout << "Enter your age: " << endl;
  cin >> Age;

} 
bool verifyEligibility(char GG, int Old)
{
  if(GG == 'm' && Old >= 18)
    {
    
      return true;
     
    }
  else
    {
      return false;
    }
}
void printLetter(string NAME, char GGG, int age)
{
 
  if(GGG == 'm' && age >= 18) 
  { 
    
    cout << "Dear " << NAME << " Please consider joining the military" << endl;
    
    }
  else
    {
      cout << "Not Eligible! Thank you for applying" << endl;
    }


}
