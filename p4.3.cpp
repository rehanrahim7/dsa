#include <iostream>
using namespace std;

class JobQueue
{
private:
        char Q[5][30];
        int front, rear;

public:
        JobQueue()
        {
            front = rear = -1;
        }

        int isEmpty()
        {
            if (front == -1)
                return 1;
            else 
                return 0;
        }

        int isFull()
        {
            if (rear == 4)
                return 1;
            else 
                return 0;
        }

        void addJob(char jobName[])
        {
            if (isFull() == 1)
            {
                cout << "";
                
            }
            else if (isEmpty() == 1)
            {
                front = rear = 0;

                int i = 0;
                while (jobName[i] != '\0')
                {
                    Q[rear][i] = jobName[i];
                    i++;
                }
                    Q[rear][i] = '\0';

                    cout << "\nJob added: " << jobName << "\n";
            
        }


};

int main()
{
    return 0;
}