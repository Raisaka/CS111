/************************************************************************
Jared Falcon
CS111
11/10/20

This program will call multiple functions using a variety of header files.
It will ask for the users account information and county code. The user
will be able to purchase as many items as they want. At the end of the 
program they will receive an invoice of their total, discount(depending 
on the month), Taxes, and shipping cost(depending on the weight of the items).
 ***********************************************************************/
#include <iostream>
#include <iomanip>
#include "input.h"
#include "/cs/slott/hw/17mailOrderA.h"
#include "/cs/slott/hw/28mailOrderB.h"
#include "/cs/slott/hw/mailOrderC.h"
using namespace std;
void getCustomerInfo(int& acc, int& m, int& d, int& y, char& code);
void getItemsInfo(double& total, int& weight);

int main()
{
  int account;//stores account number
  int m;//stores month
  int d;//stores day
  int y;//stores year
  char c;//stores county letter
  
  double totalPr;//total price
  int pounds;//total weight
  
  double DISC;//discount storage
  double TAX;//tax storage
  double SHIP;//shipping storage
  
  getCustomerInfo(account, m, d, y, c);//calling function for customer info

  getItemsInfo(totalPr, pounds);//calling function for customer items
  
  DISC = calcDiscount(totalPr, m);//returns discount and stores it in DISC
  SHIP = calcShipping(pounds);//returns shipping and stores it in SHIP
  TAX = calculateSalesTax(totalPr, DISC, c);//returns tax and stores it in TAX
  outputInvoice1(account, c, m, d, y);//calling function to display invoice 1
  outputInvoice2(totalPr, DISC, TAX, SHIP);//calling function to display invoice 2
  



  return 0;
}
/*****************************************************************
acc for the customer account
m for the month
d for the day
y for the year
code for the county Letter

This function will prompt the user to enter their account information.
The date and their county code. It will reject invalid inputs. 
****************************************************************/
void getCustomerInfo(int& acc, int& m, int& d, int& y, char& code)
{
  //caling getInt to reject invalid integer values
  cout << "Enter an account number: ";
  acc = getInt(1000, 9999, "An account number must be 1000-9999. Enter again: "); 
  cout << endl;
  //caling getInt to reject invalid integer values
  cout << "Enter a month: ";
  m = getInt(1, 12, "A month must be 1-12. Enter again: ");
  cout << endl;

  //caling getInt to reject invalid integer values
  cout << "Enter a day: ";
  d = getInt(1, 31, "A day must be 1-31. Enter again: ");
  cout << endl;

  //caling getInt to reject invalid integer values
  cout << "Enter a year: ";
  y = getInt(2000, 2100, "A year must be 2000-2100. Enter again: ");
  cout << endl;
  
  cout << "Enter a county code. Enter S, O, or L: ";
  cin >> code;
  while(code != 'S' && code != 'O' && code != 'L')//using a while loop to reject invalid county codes
    {
      cout << "Invalid county code. Enter uppercase S, O, or L: ";
      cin >> code;
    }
  cout << endl;
}
/**************************************************************
total for the total price of items
weight for the total weight of items
price to call getDouble function
heavy to call getInt function
YN to call getYN function

This function will ask the user for the price and weight of their 
items and will ask if they want to buy more after each item. It will
reject invalid inputs for each category. The function will return
total price of items and total weight.
 *************************************************************/
void getItemsInfo(double& total, int& weight)
{
  double price;//used for calling function getDouble
  int heavy = 0;//used for calling function getInt
  char YN;//used for calling fucntion getYN
  
  cout << "Do you want to order an item? Enter Y or N: ";
  YN = getYN("Invalid response. Enter Y or N: ");//getYN is called to reject invalid inputs
  cout << endl;

  
  while(YN != 'N')//while loop will run as long as YN is not 'n' or 'N'
    {
      //user enters a double price and its checked by getDouble function for validity
      cout << left << setw(4) << " " << "Enter a price: ";
      price = getDouble(0.00, 999.99, "    A price must be between 0.00 and 999.99. Enter again: ");
      // cout << left << setw(4) << " " << price;
      total += price;
      cout << endl;
      
      //user enters an integer weight and its checked by getInt function for validity
      cout << left << setw(4) << " " << "Enter a weight: ";
      heavy = getInt(0, 99, "    A weight must be between 0 and 99. Enter again: ");
      weight += heavy;
      cout << endl;
      
      //user enters 'Y' or 'N' if they would like to keep buying items
      cout << "Do you want to order another item? Enter Y or N: ";
      YN = getYN("Invalid response. Enter Y or N: ");
      cout << endl;
    }
  

}
