#include <iostream> //outputInvoice1 uses cout                                                                                  
#include <iomanip>  //for setw                                                                                              
using namespace std;

/**********************************************************
pr is the total price of all the items the customer is buying.
mo is the month when the customer is placing an order.

This function calculates a discount amount as follows and returns it.
Month orderedDiscount on total sale amount (before tax)
Jan – May 5%
Jun – Aug 10%
Sep – Dec 15%
**********************************************************/
double calcDiscount(double pr, int mo)//you may not change parameters  
{
  // double total;
  if(mo >= 1 && mo < 6)//checks range for 1-5
    {
      return pr * .05;//returns 5% discount
    }
  else if(mo >= 6 && mo < 9)//checks range for 6-8
    {
      return pr * .10;//returns 10% discount
    }
  else//checks remaining range 9-12
    {
      return pr * .15;//returns 15% discount 
    }

}
 
/********************************************************
acc is the account number
co is the county code (uppercase S, O or L) 
m is month
d is day
y is year

This function will output the top half of the invoice.
********************************************************/

void outputInvoice1(int acc, char co, int m, int d, int y)//you may not change parameters  
{
  cout << endl;
  cout << left << setw(25) << "ACCOUNT NUMBER" << "COUNTY" << endl;//25 spaces 
  cout << left << setw(25) << acc;//25 spaces
  if(co == 'S')//if co is S its for San diego
    {
      cout << "San Diego" << endl;
    }
  else if(co == 'O')//if co is O its for Orange county
    {
      cout << "Orange County" << endl;
    }
  else if(co == 'L')//if co is L its for LA county
    {
      cout << "LA county" << endl;
    }
  cout << endl;
  cout << "DATE OF SALE " << m << "/" << d << "/" << y << endl;//display date with month, day, year
}



