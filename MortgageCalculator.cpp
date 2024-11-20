//////////////////////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-223																//
//																									//
//	Type of Assignment:	Final	  	 															    //
//	Problem Number:	1		 																		//
//	Section Number	401		 																		//
//	Author:	Adam Stahly																				//
//	Due Date: 12/06/2023		 																	//
//	File Name:				FinalTwo.cpp															//
//																									//
//	Purpose of Program:																				//
//								Determine the monthly payment on a home mortgage.		    		//
//																									//
//																									//
//	Algorithm:																						//
//    1. Declare an array of ten HomeMorgage objects    								     	    //
//        2. Fill HomeMorgage array with data from input file                                       //
//        3. Output data into the Payments text file                                                //
//      4. Close output file                                                                        //
//       																							//		
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream> //for cout
#include <fstream> //for files
#include <string> //for string
#include "HomeMorgage.H" //include HomeMorgage class
#include <cstdlib> //for exit
#include <iomanip> //for setprecision
void retrieveData(HomeMorgage<double> Morgages[]);

using namespace std;

int main()
{

    HomeMorgage<double> Morgages[10]; //declares array of ten objects


    retrieveData(Morgages); //gets data from file and stores in array


    //opens input file
    ofstream outFile("Payments.txt");

    if (!outFile.is_open()) //if file does not open
    {
        cout << "File not Found";
        exit(0);
    }

    while (outFile) //while the file is open
    {
        for (int i = 0; i < 10; i++)
        {
            //puts data into file
            outFile << Morgages[i].getaccountNumber() << ' ';
            outFile << setprecision(2) << fixed << Morgages[i].getPayment() << ' ';
            outFile << setprecision(2) << fixed << Morgages[i].getTotalPayback() << ' ';
            outFile << endl;
        }

        outFile.close(); //closes file
    }
    return 0;
}

//function definition
//reads data from input file
void retrieveData(HomeMorgage<double> Morgages[])
{
    string* accountNumberPrt; //declare pointers
    double* loanPrt, * ratePrt;
    int* yearsPrt;

    //declare variables
    string accountNumber; //holds a five digit number identifing the account
    string loan, rate; //hold loan and intrest rate
    string years; //holds years of loan

    accountNumberPrt = &accountNumber; //sets the address of accountNumber equal to a string pointer



    ifstream inFile("Accounts.txt"); //open input file
    if (!inFile.is_open()) //if file can not be opened
    {
        cout << "File not found";
        exit(0); //end program
    }
    for (int j = 0; j < 10; j++)
    {
        getline(inFile, accountNumber, ' '); //reads data until a space is encountered 
        getline(inFile, loan, ' ');
        getline(inFile, rate, ' ');
        getline(inFile, years); //reads data until \n is encountered

        double l = stod(loan); //converts string values into doubles
        double r = stod(rate);
        int y = stoi(years); //converts a string value into a int

        loanPrt = &l; //sets addresses of variables to there respective pointers
        ratePrt = &r;
        yearsPrt = &y;


        //inserts value of pointers into the current Morgages array
        Morgages[j].setaccountNumber(*accountNumberPrt);
        Morgages[j].setLoan(*loanPrt);
        Morgages[j].setRate(*ratePrt);
        Morgages[j].setYears(*yearsPrt);


    }

    inFile.close(); //closes file
}








