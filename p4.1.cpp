#include <iostream>
#include <string>
using namespace std;

class Palindrome
{
private:
        char S[100];
        string str;
        int top;
public:
        Palindrome()
        {
            top = -1;
        }

        int isEmpty()
        {
            if (top == -1)
            {
                return 1;
            }
            else 
            {
                return 0;
            }
        }

        int isFull()
        {
            if (top == 99)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }

        void push(char x)
        {
            if (isFull() == 1)
            {
                top++;
                S[top] = x;
            }
        }


        char pop()
        {
            if (isEmpty() == 0)
            {
                char x = S[top];
                top--;
                return x;
            }
            return '\0';
        }

        int isAlphabet(char ch)
        {
            if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
            {
                return 1;
            }
            else 
            {
                return 0;
            }
        }

        char toLowerCase(char ch)
        {
            if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
            {
                return ch+32;
            }
            else 
            {
                return ch;
            }
        }

        void inputString()
        {
            cout << "Enter a string (max 99 char):";
        }

        void displayReverse()
        {
            int i = 0;
            string Reverse = "";

            while (str[i] != '\0')
            {
                push(str[i]);
                i++;
            }

            cout << "original: " << str;

            while (isEmpty() == 0)
            {
                Reverse += pop();
            }

            cout << "Reverse: " << Reverse;
        }

        void checkPalindrome()
        {   
            int i = 0;
            int flag = -1;

            top = -1;

            while (str[i] != '\0')
            {
                if (isAlphabet(str[i]) == 1)
                {
                    push(toLowerCase(str[i]));
                }
                i++;
            }
            i = 0;

            while (str[i] != '\0')
            {
                if (isAlphabet(str[i]) == 1)
                {
                    if(toLowerCase(str[i]) != pop())
                    {
                        flag = 0;
                        break;
                    }
                    
                }
                i++;
                
            }

            if 
        }
};