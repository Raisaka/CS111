/******************************************************************************
Jared Falcon
CS111
12/3/20

This program will use am employee struct that stores different information for 
employees. There will be several functions that will range from printing the
employees to giving raises to all the employees.
 *****************************************************************************/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

struct employee//struct employee
{
  string firstName;//stores first name
  string lastName;//stores last name
  char gender;//stores gender
  double hourly;//stores pay
  int ID;//stores ID
  int age;//stores age
};
void readData(employee m[], employee f[], int s, int& male, int& female);
void printEmployee(const employee& s);
void printAllEmp(const employee E[], int s);
void outfileArray(const employee E[], int s);
employee findOldest(const employee E[], int s);
void giveRaise(employee E[], double R, int s);
void giveRaiseToOneEmployee(double R, employee& e);
void combineArray(employee ALL[], const employee m[], int M, const employee f[], int F);
void findEmp(const employee E[], int size);
void sortEmployees(employee E[], int size);

int main()
{
  //const int allEmp[SIZE*2];
  const int SIZE = 100;//const size of 100
  employee allEmp[SIZE*2];
  employee mAr[SIZE];//male array
  employee fAr[SIZE];//female array
  int men;//stores actual size of male array
  int women;//actual array size
  //string person;
  // employee emp;
  //calls all the readData function and will also call all the printing functions
  
  cout << "-----------------------ReadData()-------------------------" << endl;
  readData(mAr, fAr, SIZE, men, women);
  cout << "There are " << men << " male and " << women << " female employees." << endl;
  cout << "-----------------------printEmployee()--------------------" << endl;
  printEmployee(fAr[0]);
  cout << "-----------------------printEmployee()--------------------" << endl;
  printEmployee(mAr[0]);
  cout << "-----------------------printAllEmp()----------------------" << endl;
  printAllEmp(mAr, men);
  cout << "-----------------------printAllEmp()----------------------" << endl;
  printAllEmp(fAr, women);
  cout << "-----------------------outfileArray()---------------------" << endl;
  outfileArray(mAr, men);
  // outfileArray(fAr, women);
  //calls function to find the oldest person in a given array
  cout << "-----------------------findOldest()-----------------------" << endl;
  employee OLD = findOldest(mAr, men);//stores returned struct 
  cout << OLD.firstName << endl; 
  cout << "-----------------------giveRaise()------------------------" << endl;
  giveRaise(fAr, .055, SIZE);//5.5% raise to all women
  printAllEmp(fAr, women);
  cout << "-----------------------giveRaise()------------------------" << endl;
  giveRaise(mAr, .05, SIZE);//5% raise to all men
  printAllEmp(mAr, men);
  cout << "-----------------------giveRaiseToOneEmployee()-----------" << endl;
  giveRaiseToOneEmployee(.02, fAr[1]);//raise to one employee by 2%
  printEmployee(fAr[1]);
  cout << "-----------------------giveRaiseToOneEmployee()-----------" << endl;
  giveRaiseToOneEmployee(.50, mAr[0]);//raise to one employee by 50%
  printEmployee(mAr[0]);
  cout << "-----------------------combineArray()---------------------" << endl;
  combineArray(allEmp, mAr, men, fAr, women);
  printAllEmp(allEmp, men+women);
  cout << "----------------------findEmp()---------------------------" << endl;
  findEmp(allEmp, men+women);
  cout << "----------------------findEmp()---------------------------" << endl;
  findEmp(allEmp, men+women);
  cout << "----------------------sortEmployees()---------------------" << endl;
  sortEmployees(allEmp, men+women);
  printAllEmp(allEmp, men+women);

  return 0;
}
/*******************************************************************
employee m[] is the male array
employee f[] is the female array
s is the size of the array
male will store the amount of male employees
female will store the amount of female employees

This function will be able to read data from a file and store the 
employees on seperate arrays. It will also pass by reference the 
amount of female and male employees. 
 ******************************************************************/
void readData(employee m[], employee f[], int s, int& male, int& female)
{
  int mi = 0;//stores count for male employees
  int fi = 0;//stores count for female employees
  employee temp;//used to read the file and be able to use each variable in our employee struct
  //  int i = 0;
  
  ifstream fin;//creates instance of a file
  fin.open("employees.dat");//opens file with data

  if(!fin)//file doesnt open, display error
    {
      cout << "File does not exist!" << endl;
      exit(1);//force quit the program
    }
  else//otherwise read the file and store each variable in the appropriate array 
    {
      
      fin >> temp.firstName >> temp.lastName >> temp.gender >> temp.hourly >> temp.ID >> temp.age;//starts reading
      while(fin && mi < s && fi < s)//while there is still space in the array kepp reading
	{
	  if(temp.gender == 'F')//if the gender is female, store in female array
	    {
	      f[fi++] = temp;//store the whole employee in the given array at index++ 
	      
	      female = fi;//fi has the number of female employees and will transfer it to female 
	    }
	  else//otherwise they are male employees 
	    {
	      m[mi++] = temp;//store the whole employee in the given array at index++
	      
	      male = mi;//mi has the number of male employees and will transfer it to male
	    }
	  fin >> temp.firstName >> temp.lastName >> temp.gender >> temp.hourly >> temp.ID >> temp.age;//keep reading
	  }
      fin.close();//close the file when done
    }


}
/***************************************************************************
const employee& e is the just one employee and not being changed

This function will print just one specific employee
 **************************************************************************/
void printEmployee(const employee& e)
{
  cout << fixed << setprecision(2);//show decimals
  cout << left << setw(10) << e.firstName << setw(10) << e.lastName << setw(10) << e.gender << setw(10) << e.hourly << setw(10) << e.ID << setw(10) << e.age << endl;

}
/***************************************************************************
const employee E[] this is either the male or female array
s is their size 

This function will display all the employees in the given array 
 **************************************************************************/
void printAllEmp(const employee E[], int s)
{
  for(int i = 0; i < s; i++)//for loop to print all the employees using another function
    {
      printEmployee(E[i]);//calls printEmployee() and loops the amount of times of the respective array
    }

}
/*************************************************************************
const employee E[] male or female array is passed
s is the size of given array

This function will print the last and first name of the employees in either 
the female or male array. It will prompt the user to create a new output file.
The last and first names will be saved in the created file.
 ************************************************************************/
void outfileArray(const employee E[], int s)
{
  string filename;//used to save/type filename
  employee temp;//not used
  ofstream fout;//creates instance for file output
  cout << "Enter the output file name: " << endl;
  cin >> filename;
  fout.open(filename.c_str());//opens the filename entered using a cstring function

  for(int i = 0; i < s; i++)//for loop to go through the given array and print out last and first names
    {
      fout << E[i].lastName << ", " << E[i].firstName << endl;
    } 
  
  fout.close();//close file

}
/*************************************************************************
const employee E[] pass either female or male array
s is the size of the given array

This function will return the whole struct with the oldest employee
 ************************************************************************/
employee findOldest(const employee E[], int s)
{
  // employee old;
  // employee OLDER;
  employee oldest;//create a struct to remember 
  //  oldest.firstName;
  oldest = E[0];//make the first person in the given array the oldest
  
  for(int i = 1; i < s; i++)//loop through the array
    {
      if(oldest.age < E[i].age)//compare the ages of the employees 
	{
	  oldest = E[i];//if another employee is older than the first one, then that employee is stored 

	}

    }

  return oldest;//return the whole struct of the oldest employee

}
/**************************************************************************
employe E[] passes either array female or male
R is the raise value
s is the size of array

This function will give a raise to all employees in the given array
 *************************************************************************/
void giveRaise(employee E[], double R, int s)
{
  double temp;//stores raise 
  for(int i = 0; i < s; i++)
    {
      temp = E[i].hourly * R;//multiplies employee wage by raise percentage and stores it in temp
      
      E[i].hourly += temp;//adds employee wage plus temp and stores it back in the hourly variable
    }

}
/*************************************************************************
R is the raise value
employee& e passes only one employee, instead of the whole array

This function will give a raise to just one specific employee.
 ************************************************************************/
void giveRaiseToOneEmployee(double R, employee& e)
{
  double temp;//stores raise value
  temp =  e.hourly*R;//multiplies wage and raise, stores it in temp

  e.hourly += temp;//adds temp(raise) and original wage to the hourly 
}
/************************************************************************
employee ALL[] is the new array that will include all employees
const employee m[] is the male array 
const employee f[] is the female array 
int M is the male size
int F is the female size

This function will combine the male and the female array. It will put 
both of the arrays in a new array.
 ***********************************************************************/
void combineArray(employee ALL[], const employee m[], int M, const employee f[], int F)
{
  //  int men = 0;
  int i;//index value 
  for(i = 0; i < M; i++)//for loop to go through and put the male array in first
    {
      ALL[i] = m[i];//copy to allEmp array
     
    }
  for(int j = 0; j  < F; j++, i++)//second for loop to copy female array, uses same i to fill in where it left off
    {
      ALL[i] = f[j];//copies females after males in the new array
    }

}
/**********************************************************************
const employee E[] will be able to use any array
int size is the size of the given array 

This function will look for an employee ID and tell whether or not it was 
found in the given array. The fuction should stop looking for the key 
as soon as it finds it. 
 *********************************************************************/
void findEmp(const employee E[], int size)
{
  //  bool found = false;
  int key;//key is the Id we are looking for 
  cout << "Enter the employee ID: ";
  cin >> key;
  bool found = false;//set our boolean variable to false
  int i;//declare our index first to be used outside the for loop
  for(i = 0;found==false && i < size; i++)//for loop will loop if the statement is still false or i < size
    {
      //           cout << "here!";
      if(key == E[i].ID)//compare the key we entered to the ID we are looking for 
	{
	  //  cout << "Here";
	  found = true;//if found the boolean variable is set to true (in order to exit loop early)
	 	  
	}
    }
  cout << endl;
  if(found == true)//if found, display the last and first name of the employee
    {
      cout << E[i-1].firstName << " " << E[i-1].lastName << endl;
    }
  else//if NOT found, display message 
    {
      cout << "There is no employee with ID " << key << endl;
    }
  cout << endl;
}
void sortEmployees(employee E[], int size)
{
  int first;//stores first index person
  employee temp;//temporary employee
 
  for(int last = size - 1; last >=1; last--)//last will be the last index value size - 1
    {
      
      first = 0;//will be the first index

      for(int i = 1; i <= last; i++)//will find the first name 
	{
	  if(E[i].firstName > E[first].firstName)//compares the two first names at index [1] and [0]
	    {
	      first = i;//first will take new index of the name in alphabetical order
	    }
	}
      //swaps the largest with the last item(name) in the unsorted area 
      temp = E[first];//store first employee into our employee temp
      E[first] = E[last];// last employee into first
      E[last] = temp;//temp into last
    }

}

