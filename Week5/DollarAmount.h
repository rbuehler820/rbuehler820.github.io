// Fig. 5.8: DollarAmount.h
// DollarAmount class stores dollar amounts as a whole numbers of pennies
#include <string>
#include <cmath> 
#include "stdafx.h"
#include <iostream>

class DollarAmount {
public:
   // initialize amount from an int64_t value
   //explicit DollarAmount(int64_t value) : amount{value} { }

   //5.30
	DollarAmount(int dol, int cen) :
		dollars{ dol }, pennies{ cen } {}

   // add right's amount to this object's amount
   void add(DollarAmount right) {
      // can access private data of other objects of the same class
      //amount += right.amount; 
	   dollars += right.dollars;
	   pennies += right.pennies;
   }

   // subtract right's amount from this object's amount
   void subtract(DollarAmount right) {
	   // can access private data of other objects of the same class
	   //amount -= right.amount;
	   dollars -= right.dollars;
	   pennies -= right.pennies;
   }

   //5.31
   void divide(int value) {
	   int amount{ dollars * 100 + pennies };
	   amount = amount / value;
	   dollars = amount / 100;
	   pennies = amount % 100;
   }

   // uses integer arithmetic to calculate interest amount, 
   // then calls add with the interest amount
   void addInterest(int rate, int divisor) {
      // create DollarAmount representing the interest
	  //5.32
	  int rounding{ (rate % 2 == 0 ? divisor / 2 : 0) };
	  int amount{ dollars * 100 + pennies };
	  int interestAmount{ (amount * rate + rounding) / divisor };
      DollarAmount interest{
		  //(amount * rate + divisor / 2) / divisor
		  interestAmount / 100, interestAmount % 100
      };

      add(interest); // add interest to this object's amount
   }

   int roundCents(int cents)
   {
	   return 0;
   }

   // return a string representation of a DollarAmount object
   std::string toString() const {
      std::string dollarsSTR{std::to_string(dollars)};
      std::string centsSTR{std::to_string(std::abs(pennies))};
      return dollarsSTR + "." + (centsSTR.size() == 1 ? "0" : "") + centsSTR;
   }
private:
   //int64_t amount{0}; // dollar amount in pennies
	int dollars{ 0 };
	int pennies{ 0 };
};