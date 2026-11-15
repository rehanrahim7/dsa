/*
In any language program mostly syntax error occurs due to unbalancing delimiter such as (),
{},[]. Write C++ program using stack to check whether given expression is well parenthesized
or not.
*/

#include <iostream>
#include <string>
using namespace std;

class Parenthesis
{
    char S[100];
    string expr;
    int top;

public:
    Parenthesis()
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

    // Input expression
    void inputExpression()
    {
        cout << "Enter an expression: ";
        getline(cin, expr);
    }

    // Check balanced parentheses
    int isBalanced()
    {
        top = -1;

        for (int i = 0; i < expr.length(); i++)
        {
            char ch = expr[i];

            if (ch == '(' || ch == '{' || ch == '[')
                push(ch);

            else if (ch == ')' || ch == '}' || ch == ']')
            {
                if (top == -1)
                    return 0;

                char x = pop();

                if ((ch == ')' && x != '(') ||
                    (ch == '}' && x != '{') ||
                    (ch == ']' && x != '['))
                    return 0;
            }
        }

        return (top == -1);
    }

    // Display result
    void displayResult()
    {
        if (isBalanced())
            cout << "Expression is well parenthesized.\n";
        else
            cout << "Expression is NOT well parenthesized.\n";
    }
};

int main()
{
    Parenthesis p;

    p.inputExpression();
    p.displayResult();

    return 0;
}
