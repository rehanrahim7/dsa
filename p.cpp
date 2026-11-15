#include <iostream>
#include <string>
using namespace std;

class Node 
{

public:
        string name;
        long prn;
        Node *next;

        Node(string n, long p)
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
            Node *temp = new Node(name, prn);
            temp->next = head;
            head = temp;
        }

        void deletePresident()
        {
            if (head == NULL)
                return;

            Node *temp = head;
            head = head->next;
            delete temp;
        }

        void AddMemSec(string name, long prn)
        {
            Node *temp = new Node(name, prn);
            
            if (head == NULL)
            {
                head = temp;
            }
            else 
            {
                Node *p = head;
                while(p->next != NULL)
                {
                    p = p->next;
                }
                p->next = temp;
            }
        }

        void DeleteSec()
        {
            if (head == NULL)
            {
                return;
            }

            Node *temp = head;

            if(head->next == NULL)
            {
                delete head;
                head = NULL;
                return;
            }
            
            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }

            delete temp->next;
            temp->next = NULL;
        }

        void deleteMember(long prn)
        {
            Node *temp = head, *prev = NULL;

            while (temp != NULL && temp->prn != prn)
            {
                prev = temp;
                temp = temp->next;
            }

            if (temp == NULL)
                return;

            if (prev == NULL)
                head = temp->next;
            else
                prev->next = temp->next;

            delete temp;
        }
  

        int countMembers()
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
        

        void concetanate(LinkedList &B)
        {
            if (head == NULL)
                head = B.head;
            else
            {
                Node *temp = head;
                while (temp->next != NULL)
                    temp = temp->next;

                temp->next = B.head;
            }

            B.head = NULL;
        }

        void display()
        {
            Node *temp = head;

            while (temp != NULL)
            {
                cout << "Name: " << temp->name
                    << " PRN: " << temp->prn << endl;
                temp = temp->next;
            }
        }   
};


int main()
{
    LinkedList A, B;
    int ch;
    string name;
    long prn;

    do
    {
        cout << "\n1.Add President";
        cout << "\n2.Add Member/Secretary";
        cout << "\n3.Delete President";
        cout << "\n4.Delete Secretary";
        cout << "\n5.Delete Member";
        cout << "\n6.Display Members";
        cout << "\n7.Count Members";
        cout << "\n8.Add Member to Division B";
        cout << "\n9.Concatenate Lists";
        cout << "\n10.Display Division B";
        cout << "\n0.Exit";
        cout << "\nEnter choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter name and PRN: ";
            cin >> name >> prn;
            A.addPresident(name, prn);
            break;

        case 2:
            cout << "Enter name and PRN: ";
            cin >> name >> prn;
            A.addMember(name, prn);
            break;

        case 3:
            A.deletePresident();
            break;

        case 4:
            A.deleteSecretary();
            break;

        case 5:
            cout << "Enter PRN: ";
            cin >> prn;
            A.deleteMember(prn);
            break;

        case 6:
            A.display();
            break;

        case 7:
            cout << "Total Members: " << A.countMembers();
            break;

        case 8:
            cout << "Enter name and PRN: ";
            cin >> name >> prn;
            B.addMember(name, prn);
            break;

        case 9:
            A.concatenate(B);
            cout << "Lists concatenated.";
            break;

        case 10:
            B.display();
            break;

        case 0:
            cout << "Program ended.";
            break;

        default:
            cout << "Invalid choice.";
        }

    } while (ch != 0);

    return 0;
}