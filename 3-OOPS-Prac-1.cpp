/*
Write a C++ program to store roll numbers of 
student in array who attended training program in
random order. Write function for searching whether 
particular student attended training program
or not, using Linear search and binary search. 
Compare these two algorithms with respect to the
number of comparisons required to find the given students. (Mandatory)
*/
#include <iostream>
using namespace std;

class StudentSearch
{
private:
    int roll[100];
    int sortedRoll[100];
    int n;

public:

    // Input student roll numbers
    void input()
    {
        cout << "Enter number of students: ";
        cin >> n;

        cout << "Enter students' roll numbers: ";

        for (int i = 0; i < n; i++)
        {
            cin >> roll[i];
            sortedRoll[i] = roll[i];
        }
    }

    // Sort array using Bubble Sort
    void sortArray()
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (sortedRoll[j] > sortedRoll[j + 1])
                {
                    int temp = sortedRoll[j];
                    sortedRoll[j] = sortedRoll[j + 1];
                    sortedRoll[j + 1] = temp;
                }
            }
        }
    }

    // Linear Search
    void linearSearch(int target)
    {
        int comparisons = 0;

        for (int i = 0; i < n; i++)
        {
            comparisons++;

            if (roll[i] == target)
            {
                cout << "\nLinear Search: Student found";
                cout << "\nIndex: " << i;
                cout << "\nComparisons: " << comparisons << endl;
                return;
            }
        }

        cout << "\nLinear Search: Student not found";
        cout << "\nComparisons: " << comparisons << endl;
    }

    // Binary Search
    void binarySearch(int target)
    {
        sortArray();

        int left = 0;
        int right = n - 1;
        int comparisons = 0;

        while (left <= right)
        {
            int mid = (left + right) / 2;
            comparisons++;

            if (sortedRoll[mid] == target)
            {
                cout << "\nBinary Search: Student found";
                cout << "\nIndex in sorted array: " << mid;
                cout << "\nComparisons: " << comparisons << endl;
                return;
            }
            else if (sortedRoll[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        cout << "\nBinary Search: Student not found";
        cout << "\nComparisons: " << comparisons << endl;
    }
};

int main()
{
    StudentSearch s;
    int target;

    s.input();

    cout << "\nEnter roll number to search: ";
    cin >> target;

    s.linearSearch(target);
    s.binarySearch(target);

    return 0;
}
