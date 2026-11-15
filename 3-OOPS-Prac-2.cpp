/*
Write a C++ program to store first year percentage of students in array. Write function for
sorting array of floating point numbers in ascending order using
a) Selection Sort
b) Bubble sort and display top five scores.
*/

#include <iostream>
using namespace std;

class StudentSort
{
private:
    float percentage[100], selection[100], bubble[100];
    int n;

public:

    void displayOriginal()
    {
        display(percentage);
    }

    // Input student percentages
    void input()
    {
        cout << "Enter number of students: ";
        cin >> n;

        cout << "Enter student percentages:\n";

        for (int i = 0; i < n; i++)
        {
            cout << "Student " << i + 1 << ": ";
            cin >> percentage[i];

            selection[i] = percentage[i];
            bubble[i] = percentage[i];
        }
    }

    // Display percentages
    void display(float arr[])
    {
        for (int i = 0; i < n; i++)
        {
            cout << "Student " << i + 1 << ": "
                 << arr[i] << "%" << endl;
        }
    }

    // Display top five scores
    void topFive(float arr[])
    {
        cout << "\nTop five scores:\n";

        for (int i = n - 1; i >= 0 && i >= n - 5; i--)
        {
            cout << arr[i] << "%" << endl;
        }
    }

    // Selection Sort
    void selectionSort()
    {
        for (int i = 0; i < n - 1; i++)
        {
            int minIndex = i;

            for (int j = i + 1; j < n; j++)
            {
                if (selection[j] < selection[minIndex])
                {
                    minIndex = j;
                }
            }

            if (minIndex != i)
            {
                float temp = selection[i];
                selection[i] = selection[minIndex];
                selection[minIndex] = temp;
            }
        }

        cout << "\nAfter Selection Sort:\n";
        display(selection);
    }

    // Bubble Sort
    void bubbleSort()
    {
        for (int i = 0; i < n - 1; i++)
        {
            bool swapped = false;

            for (int j = 0; j < n - i - 1; j++)
            {
                if (bubble[j] > bubble[j + 1])
                {
                    float temp = bubble[j];
                    bubble[j] = bubble[j + 1];
                    bubble[j + 1] = temp;

                    swapped = true;
                }
            }

            if (!swapped)
                break;
        }

        cout << "\nAfter Bubble Sort:\n";
        display(bubble);

        topFive(bubble);
    }
};

int main()
{
    StudentSort s;

    s.input();

    cout << "\nBefore sorting:\n";
    s.displayOriginal();

    s.selectionSort();
    s.bubbleSort();

    return 0;
}
