#include <iostream>
using namespace std;

class TrayStack
{
    int *stack;
    int top;
    int capacity;

public:
    TrayStack(int n)
    {
        capacity = n;
        stack = new int[capacity];
        top = -1;
    }

    void push(int tray)
    {
        if (top == capacity - 1)
        {
            cout << "Error: Stack Overflow (Counter is full)" << endl;
            return;
        }

        top++;
        stack[top] = tray;

        cout << "Placed Tray: " << tray << endl;
        cout << "Current Top Tray: " << stack[top] << endl;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Error: Stack Underflow (Counter is empty)" << endl;
            return;
        }

        cout << "Taken Tray: " << stack[top] << endl;
        top--;

        if (top == -1)
            cout << "Current Top Tray: None (Stack Empty)" << endl;
        else
            cout << "Current Top Tray: " << stack[top] << endl;
    }

    ~TrayStack()
    {
        delete[] stack;
    }
};

int main()
{
    int n, operations;

    cout << "Enter stack capacity: ";
    cin >> n;

    TrayStack s(n);

    cout << "Enter number of operations: ";
    cin >> operations;

    cout << "\n1 = Place Tray\n2 = Take Tray\n";

    for (int i = 0; i < operations; i++)
    {
        int choice;
        cout << "\nEnter operation: ";
        cin >> choice;

        if (choice == 1)
        {
            int tray;
            cout << "Enter tray number: ";
            cin >> tray;
            s.push(tray);
        }
        else if (choice == 2)
        {
            s.pop();
        }
        else
        {
            cout << "Invalid Operation!" << endl;
        }
    }

    return 0;
}