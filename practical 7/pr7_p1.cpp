#include <iostream>
using namespace std;

class Queue
{
    int arr[100];
    int front, rear, size;

public:
    Queue(int n)
    {
        size = n;
        front = -1;
        rear = -1;
    }

    void join(int token)
    {
        if (rear == size - 1)
        {
            cout << "Error: Queue is Full" << endl;
            return;
        }

        if (front == -1)
            front = 0;

        rear++;
        arr[rear] = token;

        cout << "Front Token: " << arr[front] << endl;
    }

    void serve()
    {
        if (front == -1 || front > rear)
        {
            cout << "Error: Queue is Empty" << endl;
            return;
        }

        cout << "Served Token: " << arr[front] << endl;
        front++;

        if (front > rear)
        {
            front = -1;
            rear = -1;
        }

        if (front != -1)
            cout << "Front Token: " << arr[front] << endl;
        else
            cout << "Queue is Empty" << endl;
    }
};

int main()
{
    int n;
    cout << "Enter Queue Capacity: ";
    cin >> n;

    Queue q(n);

    int choice, token;

    do
    {
        cout << "\n1. Join (Issue Token)";
        cout << "\n2. Serve Token";
        cout << "\n3. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Token Number: ";
            cin >> token;
            q.join(token);
            break;

        case 2:
            q.serve();
            break;

        case 3:
            cout << "Program Ended";
            break;

        default:
            cout << "Invalid Choice";
        }

    } while (choice != 3);

    return 0;
}