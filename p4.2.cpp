#include <iostream>
#include <string>
using namespace std;

class Paranthesis
{
private:    
        char S[100];
        string expr;
        int top;

public:
        Paranthesis()
        {
            top = -1;
        }

        int isEmpty()
        {
            if (top == - 1)
            {
                return 1;
            }
            else 
                return 0;
        }

        int isFull()
        {
            if (top == - 1)
            {
                return 1;
            }
            else 
                return 0;
        }

        void push(char x)
        {
            if (isFull() == 0)
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

        void input(){}

        void isBalanced()
        {
            top = -1;
            for(int i = 0; expr[i] != '\0'; i++)
            {
                char ch = expr[i];

                if (ch == '(' || ch == '{' || ch == '[')
                {
                    if (isFull() == 1)
                    {
                        return 0;
                    }
                    push(ch);

                }
                else if (ch == ')' || ch == '}' || ch == ']')
                {
                    if 
                }
            }
        }
};


int main()
{

}