/***********************************************************************
Jared Falcon
CS111
10/9/20

This program will ask the user for the date, their company's name, and the
quantity they would like to purchase. A discount will be issued if the 
company reaches a certain threshhold for the different discounts.
20%, 30%, 40%, 50% The program will reject negative values for the quantity
input and won't display an invoice if the quantity is 0. 
 **********************************************************************/
#include <iostream> 
#include <iomanip>//used for manipulators

using namespace std;

int main()
{
  
  string date;//stores date
  string company;//stores company name
  int quantity;//stores quantity
  double price;//stores the quantity * the price of the software (99)
  double discount;//stores the discount ( price * different discounts)
  double total;// stores the total after the discount is subtracted
  
  //asks the user for date, quantity, and company
  cout << "Enter today's date (mm/dd/yy): ";
  cin >> date;
  cin.ignore();//will ignore the enter key from cin
  cout << "Enter your company name: ";
  getline(cin, company);//gets the whole name with spaces and clears the queue
  cout << "Enter the quantity you would like to purchase: ";
  cin >> quantity;
  
  if(quantity < 0)//if the qunatity is negative, display error
    {
      cout << endl;
      cout << "Invalid quantity!" << endl;
    }
  else if(quantity == 0)//if qunatity is 0, display message
    {
      cout << endl;
      cout << "Hope you decide to buy our software in the future." << endl;
    }
  else//if the quantity is more 1 or more enter check how much 
    {
      price = quantity * 99.0;//will store the price for the quantity * the software price

      if(quantity < 10)//the quantity was less than 10 but more than 0 (no discount) display invoice
	{
	  
	  discount = price * 0;//no discount
	  
	}
      else if(quantity >= 10 && quantity < 20)//quantity in between 10-19
	{
	  
	  discount = price * .20;//20% discount and invoice
	  
       }
      else if(quantity >= 20 && quantity < 50)//quantity in between 20-49
	{
	  
	  discount = price * .30;//30% discount and invoice
	  
	}
      else if(quantity >= 50 && quantity < 100)//quantity in between 50-99
       {

          discount = price * .40;//40% discount and invoice
 
       } 
      else if(quantity >= 100)//anything 100 and over will get a 50% discount
	{

	  discount = price * .50;//50% discount and invoice
	 
	}


total = price - discount;//the total after the discount is taken if any

cout << endl;//make a new line
cout << left << "Invoice for " << company << endl;//displays company name invoice
cout << endl;//make new line
cout << fixed << setprecision(2);//will make the .00 show in the numbers
//will display the invoice with alignments and decimals for the numbers
cout << left << setw(30) << "Price before discount " << right << setw(10) << " $ " << right << setw(10) << price << endl;
cout << left << setw(30) << "Discount "  << right << setw(10) << " $ " << right << setw(10) << discount << endl;
cout << left << setw(30) << "Total Due " << right << setw(10) << " $ " << right << setw(10) << total << endl;


        }
cout << endl;






      





 return 0;
}
