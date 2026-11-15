/*
Queues are frequently used in computer programming, and a typical example is the creation of
a job queue by an operating system. If the operating system does not use priorities, then the jobs
are processed in the order they enter the system. Write C++ program for simulating job queue.
Write functions to add job and delete job from queue.
*/

#include <iostream>
#include <cstring>
using namespace std;

class JobQueue
{
    char Q[5][30];
    int front, rear;

public:
    JobQueue()
    {
        front = rear = -1;
    }

    // Add job
    void addJob(const char job[])
    {
        if (rear == 4)
            cout << "Queue is full.\n";
        else
        {
            if (front == -1)
                front = 0;

            strcpy(Q[++rear], job);
            cout << "Job added: " << job << endl;
        }
    }

    // Delete job
    void deleteJob()
    {
        if (front == -1)
            cout << "Queue is empty.\n";
        else
        {
            cout << "Job processed: " << Q[front] << endl;

            if (front == rear)
                front = rear = -1;
            else
                front++;
        }
    }

    // Display jobs
    void display()
    {
        if (front == -1)
            cout << "Queue is empty.\n";
        else
        {
            for (int i = front; i <= rear; i++)
                cout << Q[i] << endl;
        }
    }

    // Display front job
    void getFront()
    {
        if (front == -1)
            cout << "Queue is empty.\n";
        else
            cout << "Next job: " << Q[front] << endl;
    }

    // Display last job
    void getRear()
    {
        if (front == -1)
            cout << "Queue is empty.\n";
        else
            cout << "Last job: " << Q[rear] << endl;
    }
};

int main()
{
    JobQueue q;

    q.addJob("Print_Document");
    q.addJob("Download_Document");
    q.addJob("Update_System");

    cout << "\nJobs in queue:\n";
    q.display();

    q.getFront();

    q.deleteJob();

    cout << "\nAfter deleting job:\n";
    q.display();

    q.getRear();

    return 0;
}
