/*
Write a C++ program to compute following operations on String:
a) To display word with the longest length
b) To determines the frequency of occurrence of particular character in the string
c) To check whether given string is palindrome or not
d) To display index of first appearance of the substring
e) To count the occurrences of each word in a given string
*/
#include <iostream>
#include <string>
using namespace std;

class StringOps
{
private:
    string str;

public:

    // Input string
    void input()
    {
        cout << "Enter a string: ";
        getline(cin, str);
    }

    // a) Display longest word
    void longestWord()
    {
        string word = "", longest = "";

        for (int i = 0; i <= str.length(); i++)
        {
            if (str[i] == ' ' || str[i] == '\0')
            {
                if (word.length() > longest.length())
                    longest = word;

                word = "";
            }
            else
            {
                word += str[i];
            }
        }

        cout << "Longest word is: " << longest << endl;
    }

    // b) Frequency of a character
    void charFreq()
    {
        char ch;
        int count = 0;

        cout << "Enter character to search: ";
        cin >> ch;

        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == ch)
                count++;
        }

        cout << "Frequency of '" << ch << "' is: "
             << count << endl;
    }

    // c) Check palindrome
    void checkPalindrome()
    {
        int start = 0;
        int end = str.length() - 1;
        bool palindrome = true;

        while (start < end)
        {
            if (str[start] != str[end])
            {
                palindrome = false;
                break;
            }

            start++;
            end--;
        }

        if (palindrome)
            cout << "String is a palindrome" << endl;
        else
            cout << "String is not a palindrome" << endl;
    }

    // d) First appearance of substring
    void subIndex()
    {
        string sub;
        int pos = -1;

        cout << "Enter substring to search: ";
        getline(cin >> ws, sub);

        for (int i = 0; i < str.length(); i++)
        {
            int j = 0;

            while (j < sub.length() &&
                   i + j < str.length() &&
                   str[i + j] == sub[j])
            {
                j++;
            }

            if (j == sub.length())
            {
                pos = i;
                break;
            }
        }

        if (pos != -1)
            cout << "First appearance index: " << pos << endl;
        else
            cout << "Substring not found" << endl;
    }

    // e) Count occurrences of each word
    void wordFrequency()
    {
        string words[100];
        bool counted[100] = {false};
        string word = "";
        int n = 0;

        for (int i = 0; i <= str.length(); i++)
        {
            if (str[i] == ' ' || str[i] == '\0')
            {
                if (word != "" && n < 100)
                {
                    words[n] = word;
                    n++;
                }

                word = "";
            }
            else
            {
                word += str[i];
            }
        }

        cout << "Word frequencies:" << endl;

        for (int i = 0; i < n; i++)
        {
            if (counted[i])
                continue;

            int count = 1;

            for (int j = i + 1; j < n; j++)
            {
                if (words[i] == words[j])
                {
                    count++;
                    counted[j] = true;
                }
            }

            cout << words[i] << " : " << count << endl;
        }
    }
};

int main()
{
    StringOps s;

    s.input();

    s.longestWord();
    s.charFreq();
    s.checkPalindrome();
    s.subIndex();
    s.wordFrequency();

    return 0;
}