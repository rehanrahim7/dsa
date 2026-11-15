/*
Second year Computer Engineering class, set A of students like Vanilla Ice-cream and set B of
students like butterscotch ice-cream. Write C++ program to store two sets using linked list.
compute and display-
a) Set of students who like both vanilla and butterscotch
b) Set of students who like either vanilla or butterscotch or not both
c) Number of students who like neither vanilla nor butterscotch
*/
#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    int rollNo;
    string name;
    Node *next;

    Node(int r, string n)
    {
        rollNo = r;
        name = n;
        next = NULL;
    }
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    // Add a student at the end
    void addStudent(int rollNo, string name)
    {
        Node *newNode = new Node(rollNo, name);

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        Node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    // Check whether a roll number exists
    bool search(int rollNo)
    {
        Node *temp = head;

        while (temp != NULL)
        {
            if (temp->rollNo == rollNo)
            {
                return true;
            }

            temp = temp->next;
        }

        return false;
    }

    // Display all students
    void display()
    {
        if (head == NULL)
        {
            cout << "No students found.\n";
            return;
        }

        Node *temp = head;

        while (temp != NULL)
        {
            cout << "Roll No: " << temp->rollNo
                 << ", Name: " << temp->name << "\n";

            temp = temp->next;
        }
    }

    // Display students present in both sets
    void displayIntersection(LinkedList &B)
    {
        Node *temp = head;
        bool found = false;

        while (temp != NULL)
        {
            if (B.search(temp->rollNo))
            {
                cout << temp->rollNo << " "
                     << temp->name << "\n";
                found = true;
            }

            temp = temp->next;
        }

        if (!found)
        {
            cout << "No common students.\n";
        }
    }

    // Display students who like either ice cream, but not both
    void displayEitherNotBoth(LinkedList &B)
    {
        Node *temp = head;
        bool found = false;

        while (temp != NULL)
        {
            if (!B.search(temp->rollNo))
            {
                cout << temp->rollNo << " "
                     << temp->name << "\n";
                found = true;
            }

            temp = temp->next;
        }

        temp = B.head;

        while (temp != NULL)
        {
            if (!search(temp->rollNo))
            {
                cout << temp->rollNo << " "
                     << temp->name << "\n";
                found = true;
            }

            temp = temp->next;
        }

        if (!found)
        {
            cout << "No students found.\n";
        }
    }

    // Count students in a set
    int countStudents()
    {
        int count = 0;
        Node *temp = head;

        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }

        return count;
    }

    // Count students present in both sets
    int countCommon(LinkedList &B)
    {
        int count = 0;
        Node *temp = head;

        while (temp != NULL)
        {
            if (B.search(temp->rollNo))
            {
                count++;
            }

            temp = temp->next;
        }

        return count;
    }
};

int main()
{
    LinkedList vanilla, butterscotch;

    int n, rollNo;
    string name;

    cout << "Enter number of students who like Vanilla: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter roll number and name: ";
        cin >> rollNo >> name;
        vanilla.addStudent(rollNo, name);
    }

    cout << "\nEnter number of students who like Butterscotch: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter roll number and name: ";
        cin >> rollNo >> name;
        butterscotch.addStudent(rollNo, name);
    }

    cout << "\nStudents who like both ice creams:\n";
    vanilla.displayIntersection(butterscotch);

    cout << "\nStudents who like either ice cream, but not both:\n";
    vanilla.displayEitherNotBoth(butterscotch);

    int totalStudents;

    cout << "\nEnter total number of students in the class: ";
    cin >> totalStudents;

    int neither = totalStudents - vanilla.countStudents() - butterscotch.countStudents() + vanilla.countCommon(butterscotch);

    cout << "\nNumber of students who like neither ice cream: "
         << neither << "\n";

    return 0;
}
