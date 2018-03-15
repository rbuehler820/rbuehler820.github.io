// Fig. 3.9: AccountTest.cpp
// Displaying and updating Account balances.
#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

//3.9 & 4.36
class Account {
public:
	// Account constructor with two parameters  
	Account(std::string accountName, double initialBalance)
		: name{ accountName } { // assign accountName to data member name
		if (initialBalance > 0) { // if the initialBalance is valid
			balance = initialBalance; // assign it to data member balance
		}
	}

	// function that deposits (adds) only a valid amount to the balance
	void deposit(int depositAmount) {
		if (depositAmount > 0) { // if the depositAmount is valid
			balance = balance + depositAmount; // add it to the balance 
		}
	}

	// function that withdraws (subtracts) only a valid amount to the balance
	void withdraw(int withdrawAmount) {
		if (withdrawAmount > 0 && balance >= withdrawAmount) { // if the withdrawAmount is valid
			balance = balance - withdrawAmount; // remove it from the balance 
		}
	}

	// function returns the account balance
	double getBalance() const {
		return balance;
	}

	// function that sets the name
	void setName(std::string accountName) {
		name = accountName;
	}

	// function that returns the name
	std::string getName() const {
		return name;
	}
private:
	std::string name; // account name data member 
	double balance{ 0 }; // data member with default initial value
};

//3.13
void displayAccount(Account accountToDisplay) {
	printf("\n%s: balance is $%.2f\n", accountToDisplay.getName().c_str(), accountToDisplay.getBalance());
	//cout << "\n" << accountToDisplay.getName() << ": " << accountToDisplay.getName() << " balance is $"
		//<< accountToDisplay.getBalance() << endl;
}

//3.10
class Invoice {
public:
	Invoice(string partNumber, string partDescription, int partQuantity, int pricePerItem)
		: number{ partNumber }, description{ partDescription } {
		if (partQuantity > 0)
		{
			quantity = partQuantity;
		}
		if (pricePerItem > 0)
		{
			ppi = pricePerItem;
		}
	}

	void setNumber(string partNumber) {
		number = partNumber;
	}
	void setDescription(string partDescription) {
		description = partDescription;
	}
	void setQuantity(int partQuantity) {
		quantity = partQuantity;
	}
	void setPPI(int pricePerItem) {
		ppi = pricePerItem;
	}

	string getNumber() const {
		return number;
	}
	string getDescription() const {
		return description;
	}
	int getQuantity() const {
		return quantity;
	}
	int getPPI() const {
		return ppi;
	}

	int getInvoiceAmount() {
		if (quantity < 0) quantity = 0;
		if (ppi < 0) ppi = 0;
		return quantity * ppi;
	}

private:
	string number{ "0" }, description{ "error" };
	int quantity{ 0 }, ppi{ 0 };
};

//3.12
class Date {
public:
	Date(int day, int month, int year)
		: myDay{ day }, myYear{ year } {
			if (month < 1 || month > 12)
				myMonth = 1;
		}

	void setDay(int day)
	{
		myDay = day;
	}
	void setMonth(int month)
	{
		myMonth = month;
	}
	void setYear(int year)
	{
		myYear = year;
	}

	int getDay() const {
		return myDay;
	}
	int getMonth() const {
		return myMonth;
	}
	int getYear() const {
		return myYear;
	}

	string displayDate() {
		return to_string(myMonth) + "/" + to_string(myDay) + "/" + to_string(myYear);
	}
private:
	int myDay{ 1 }, myMonth{ 1 }, myYear{ 1974 };
};
int main() 
{
   Account account1{"Jane Green", 50};
   Account account2{"John Blue", -7}; 

   // display initial balance of each object
   /*3.13
   cout << "account1: " << account1.getName() << " balance is $"
      << account1.getBalance(); 
   cout << "\naccount2: " << account2.getName() << " balance is $"
      << account2.getBalance(); 
	  */
   displayAccount(account1);
   displayAccount(account2);
   cout << "\n\nEnter deposit amount for account1: "; // prompt
   int depositAmount;
   cin >> depositAmount; // obtain user input
   cout << "adding " << depositAmount << " to account1 balance";
   account1.deposit(depositAmount); // add to account1's balance

   // display balances
   /*3.13
   cout << "\n\naccount1: " << account1.getName() << " balance is $"
      << account1.getBalance(); 
   cout << "\naccount2: " << account2.getName() << " balance is $"
      << account2.getBalance(); 
	  */
   displayAccount(account1);
   displayAccount(account2);
   cout << "\n\nEnter deposit amount for account2: "; // prompt
   cin >> depositAmount; // obtain user input
   cout << "adding " << depositAmount << " to account2 balance";
   account2.deposit(depositAmount); // add to account2 balance
   
   // display balances
   /*3.13
   cout << "\n\naccount1: " << account1.getName() << " balance is $"
      << account1.getBalance(); 
   cout << "\naccount2: " << account2.getName() << " balance is $"
      << account2.getBalance() << endl; 
	  */
   displayAccount(account1);
   displayAccount(account2);
   //3.10
   Invoice invoice1{ "4129041Z", "Fake Part", 3, 4 };
   cout << "\n\nInvoice 1:" << invoice1.getNumber() << " Desc: " << invoice1.getDescription() << endl;
   cout << "Quantity: " << to_string(invoice1.getQuantity()) << " PPI: " << to_string(invoice1.getPPI()) << " = $" << to_string(invoice1.getInvoiceAmount()) << endl;

   //3.12
   Date date1{ 7, 13, 2018 };
   cout << date1.displayDate() << endl;
   date1.setMonth(5);
   cout << date1.displayDate() << endl;

} 