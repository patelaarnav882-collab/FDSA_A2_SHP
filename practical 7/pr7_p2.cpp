#include <iostream>
using namespace std;

class Node
{
public:
    int patientId;
    Node *next;

    Node(int id)
    {
        patientId = id;
        next = NULL;
    }
};

class Queue
{
    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    void arrive(int id)
    {
        Node *newNode = new Node(id);

        if (front == NULL)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Front Patient: " << front->patientId << endl;
    }

    void attend()
    {
        if (front == NULL)
        {
            cout << "Error: No patients in the ward." << endl;
            return;
        }

        Node *temp = front;
        cout << "Attended Patient: " << front->patientId << endl;

        front = front->next;
        delete temp;

        if (front == NULL)
            rear = NULL;

        if (front != NULL)
            cout << "Front Patient: " << front->patientId << endl;
        else
            cout << "Ward is Empty" << endl;
    }
};

int main()
{
    Queue q;
    int choice, id;

    do
    {
        cout << "\n1. Arrive Patient";
        cout << "\n2. Attend Patient";
        cout << "\n3. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Patient ID: ";
            cin >> id;
            q.arrive(id);
            break;

        case 2:
            q.attend();
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