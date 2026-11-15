/*
Write a C++ program to read a given ‘N’ digit number and print the reverse of the number.
Analyse the space and time complexity of the program.
*/

#include <iostream>
using namespace std;

class NumberReverser
{
    long long num;
    long long reverseNum;
    
public: 


	NumberReverser()
	{
   		num = 0;
		reverseNum = 0;
   	}

	void acceptInput()
    {
    	cout << "\nEnter the number to be reversed: ";
    	cin >> num;
    }

   	void calculateReverse()
    {
        long long temp = num;
	
        while (temp != 0)
        {
        	long long lastDigit = temp % 10;
        	reverseNum = reverseNum * 10 + lastDigit;
        	temp /= 10;
        }
    }	
	
    void display()
    {
    	cout << "\nOriginal Number: " << num;
    	cout << "\nReversed Number: " << reverseNum << endl;
    }	
};

int main()
{
    NumberReverser r;

    r.acceptInput();
    r.calculateReverse();
    r.display();

    return 0;
}

/*
Question 1: Who told you to change the original number?
To avoid this, we will create a copy of the original number, and store the copy in temp,
and keep the original number as private data member to protect its data.

*/
