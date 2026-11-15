/*
A palindrome is a string of character that’s the same forward and backward. Typically,
punctuation, capitalization, and spaces are ignored. For example, “Poor Dan is in a droop” is a
palindrome, as can be seen by examining the characters “poor danisina droop” and observing
that they are the same forward and backward. One way to check for a palindrome is to reverse
the characters in the string and then compare with them the original-in a palindrome, the
sequence will be identical. Write C++ program with functions-
a) To print original string followed by reversed string using stack
b) To check whether given string is palindrome or not
*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Palindrome
{
    char S[100];
    string str;
    int top;

public:
    Palindrome()
    {
        top = -1;
    }

    // Push character
    void push(char x)
    {
        if (top < 99)
            S[++top] = x;
    }

    // Pop character
    char pop()
    {
        if (top == -1)
            return '\0';

        return S[top--];
    }

    // Input string
    void inputString()
    {
        cout << "Enter a string: ";
        getline(cin, str);
    }

    // Display reverse
    void displayReverse()
    {
        string reverse = "";

        for (int i = 0; i < str.length(); i++)
            push(str[i]);

        while (top != -1)
            reverse += pop();

        cout << "\nOriginal string: " << str;
        cout << "\nReversed string: " << reverse << endl;
    }

    // Check palindrome
    void checkPalindrome()
    {
        top = -1;

        for (int i = 0; i < str.length(); i++)
        {
            if (isalpha(str[i]))
                push(tolower(str[i]));
        }

        int flag = 1;

        for (int i = 0; i < str.length(); i++)
        {
            if (isalpha(str[i]))
            {
                if (tolower(str[i]) != pop())
                {
                    flag = 0;
                    break;
                }
            }
        }

        if (flag == 1)
            cout << "\nString is a Palindrome.\n";
        else
            cout << "\nString is not a Palindrome.\n";
    }
};

int main()
{
    Palindrome p;

    p.inputString();
    p.displayReverse();
    p.checkPalindrome();

    return 0;
}
