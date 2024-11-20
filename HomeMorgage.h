#ifndef HOMEMORGAGE_H
#define HOMEMORGAGE_H
#include <iostream> // For cout 
#include <string> //For string

using namespace std;
template <typename T> //declare a template
class HomeMorgage;

double getTerm(int);
template <typename T>
class HomeMorgage {
private:
	string accountNumber; //holds a five digit number identifing the account
	T loan, //holds the loan amount
		rate; //holds the intrest rate
	T years; //holds the years on loan

public:

	//constructors
	HomeMorgage(string a, T l, T r, T y)
	{
		accountNumber = a;
		loan = l;
		rate = r;
		years = y;
	}
	HomeMorgage()
	{
		accountNumber = " ";
		loan = 0;
		rate = 0;
		years = 0;
	}

	//destructor
	
	
	//mutators
	void setaccountNumber(string a)
	{
		accountNumber = a;
	}
	void setLoan(T l)
	{
		loan = l;
	}
	void setRate(T r)
	{
		rate = r;
	}
	void setYears(T y)
	{
		years = y;
	}

	//accessors
	friend double getTerm(int);
	T getPayment()
	{
		T term = getTerm(years); //call getTerm friend function
		return ((loan) * (rate / 12) * (term)) / (term-1);
	}
	string getaccountNumber()
	{
		return accountNumber;
	}
	T getTotalPayback()
	{
		T term = getTerm(years);
		return getPayment() * term;
	}
	T getLoan()
	{
		return loan;
	}
	T getRate()
	{
		return rate;
	}
	T getYears()
	{
		return years;
	}
	

};

//friend function calculates and returns term
double getTerm(int years)
{
	return 12 * years;
}

#endif