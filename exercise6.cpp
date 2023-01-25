#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
  ifstream fin;
  fin.open("scores.txt");
  if(fin.is_open())
    {
      cout << "File open" << endl;
    }
  else
    {
      cout << "File is broke" << endl;
    }
  

  string name;
  double score1;
  double score2;
  double avg;
  cout << "********************" << endl;
  while(fin >> name >> score1 >> score2)
    {
      avg = (score1 + score2) / 2;
      cout << fixed << showpoint << setprecision(1);
      cout << left << setw(10) << name;
      cout << right << setw(10) << avg << endl;
    }
  fin.close();








  return 0;
}
