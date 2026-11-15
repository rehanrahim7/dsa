/*
Write a C++ program to read numeric values from the user till the users explicitly stops the input.
Perform addition on all these input numbers and print the result. (Do not use an array or any
other data structure for storing these numbers. The numbers are read from user on fly). Analyse
the space and time complexity of the program.
*/
#include<iostream>
using namespace std;

class AddSum
{
	double sum;

public: 

	AddSum()
	{
		sum = 0.0;
	}
	
	void calculateSum()
	{
		double num;
		char choice;
		
		do 
		{
			cout << "\nEnter a number: ";
			cin >> num;
			
			sum += num;
			
			cout << "\nDo you want to enter another number (y/n): ";
			cin >> choice;
			
		} while (choice == 'y' || choice == 'Y');
	
	}
	
	void displaySum()
	{
		cout << "\n--------------------------" << endl;
		cout << "\nSum of numbers: " << sum << endl;
		cout << "\n--------------------------" << endl;
	}

};

int main()
{	
	AddSum s;
	
	s.calculateSum();
	s.displaySum();

	return 0;
}

