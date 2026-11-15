/*
Department of Computer Engineering has student's club named 'Pinnacle Club'. Students of
second, third and final year of department can be granted membership on request. Similarly, one
may cancel the membership of club. First node is reserved for president of club and last node is
reserved for secretary of club. Write C++ program to maintain club member ‘information using
singly linked list. Store student PRN and Name. Write functions to:
a) Add and delete the members as well as president or even secretary.
b) Compute total number of members of club
c) Display members
d) Two linked lists exist for two divisions. Concatenate two lists.
*/

#include <iostream>
#include <string>
using namespace std;

class Node
{
public: 
        string name;
        long prn;
        Node *next;

        Node (string n, long p)
        {
            name = n;
            prn = p;
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

        void addPresident(string name, long prn)
        {
            Node *newNode = new Node(name, prn);
            newNode -> next = head;
            head = newNode;
        }

        void addMember(string name, long prn)
        {
            Node *newNode = new Node(name, prn);

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

        void deletePresident()
        {
            if (head == NULL)
            {
                cout << "Club is empty";
                return;
            }

            Node *temp = head;
            head = head->next;
            delete temp;
        }

        void deleteSecretary()
        {
            if (head == NULL)
            {
                cout << "Club is empty";
                return;
            }

            if (head->next == NULL)
            {
                delete head;
                head = NULL;
                cout << "Secretary deleted!";
                return;
            }

            Node *temp = head;
        

            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }
        }

        void deleteMember()
        {
            if(head == NULL){
                cout << "Club is empty";
                return;
            }

            Node *temp = head;
            Node *prev = NULL;

            if(temp == NULL)
            {
                cout << "Member not found";
                return;
            }

            if (prev == NULL)
            {
                head = temp->next;
            }
            else 
            {
                prev->next = temp->next;
            }

            delete temp;
        }
    
    void countMembers()
    {
        int count = 0;
        Node *temp = head;

        while (temp != NULL)
        {
            count++;
            temp = temp->next
        }

        cout << "Total members: " << count;
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "List is empty";
            return;
        }

        Node *temp = head;

        while (temp != NULL) // i != '\0'
        {
            cout << "";
            temp = temp->next; // i++
        }
    }

    void concatenate(LinkedList &other)
    {
        if(other.head == NULL)
        {
            return;
        }

        if (head == NULL){
            head = other.head;
        }

        else 
        {
            Node *temp = head;
            while (temp->next != NULL){
                temp = temp->next;
            }

            temp->next = other.head;
        }

        other.head = NULL;
    }

    void concatenate(LinkedList &other)
    {
        if (other.head == NULL)
        {
            return;
        }

        if (head == NULL)
        {
            head = other.head;
        }
        else
        {
            Node *temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = other.head;
        }

        other.head = NULL;
        cout << "Lists concatenated successfully.\n";
    }

    void concatenate (LinkedList &other)
    {
        if (other.head == NULL)
        {
            return;
        }

        if (head == NULL)
        {
            head = other.head;
        }
        else 
        {
            Node *temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = other.head;
        }
        other.head = NULL;
        cout << "List concatenated";
    }

};

int main()
{
    return 0;
}