/*
Pizza parlour accepting maximum M orders. Orders are served in first come first served basis.
Order once placed cannot be cancelled. Write C++ program to simulate the system using circular
queue using array.
*/

#include <iostream>
#include <cstring>
using namespace std;

class PizzaParlour
{
    char orders[5][30];
    int front, rear;

public:
    PizzaParlour()
    {
        front = rear = -1;
    }

    // Add order
    void addOrder(const char order[])
    {
        if ((rear + 1) % 5 == front)
            cout << "Pizza parlour is full.\n";
        else
        {
            if (front == -1)
                front = 0;

            rear = (rear + 1) % 5;
            strcpy(orders[rear], order);

            cout << "Order accepted: " << order << endl;
        }
    }

    // Serve order
    void serveOrder()
    {
        if (front == -1)
            cout << "No orders to serve.\n";
        else
        {
            cout << "Order served: " << orders[front] << endl;

            if (front == rear)
                front = rear = -1;
            else
                front = (front + 1) % 5;
        }
    }

    // Display orders
    void displayOrders()
    {
        if (front == -1)
            cout << "Queue is empty.\n";
        else
        {
            int i = front;

            while (true)
            {
                cout << orders[i] << endl;

                if (i == rear)
                    break;

                i = (i + 1) % 5;
            }
        }
    }
};

int main()
{
    PizzaParlour p;

    p.addOrder("Pizza 1");
    p.addOrder("Pizza 2");
    p.addOrder("Pizza 3");

    cout << "\nCurrent Orders:\n";
    p.displayOrders();

    p.serveOrder();
    p.serveOrder();

    cout << "\nAfter Serving:\n";
    p.displayOrders();

    p.addOrder("Pizza 4");
    p.addOrder("Pizza 5");

    cout << "\nFinal Orders:\n";
    p.displayOrders();

    return 0;
}
