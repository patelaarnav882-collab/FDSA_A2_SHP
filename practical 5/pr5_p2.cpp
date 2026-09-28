#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string name;
    Node *next;
    Node *prev;

    Node(string n)
    {
        name = n;
        next = prev = NULL;
    }
};

class CircularDLL
{
    Node *head;

public:
    CircularDLL()
    {
        head = NULL;
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "Circle is empty.\n";
            return;
        }

        Node *temp = head;
        cout << "Students: ";

        do
        {
            cout << temp->name << " ";
            temp = temp->next;
        } while (temp != head);

        cout << endl;
    }

    void join(string name)
    {
        Node *newNode = new Node(name);

        if (head == NULL)
        {
            head = newNode;
            head->next = head;
            head->prev = head;
        }
        else
        {
            Node *last = head->prev;

            last->next = newNode;
            newNode->prev = last;

            newNode->next = head;
            head->prev = newNode;
        }

        cout << name << " joined the circle.\n";
    }

    void joinAfter(string target, string name)
    {
        if (head == NULL)
        {
            cout << "Circle is empty.\n";
            return;
        }

        Node *temp = head;

        do
        {
            if (temp->name == target)
            {
                Node *newNode = new Node(name);

                newNode->next = temp->next;
                newNode->prev = temp;

                temp->next->prev = newNode;
                temp->next = newNode;

                cout << name << " joined after " << target << ".\n";
                return;
            }

            temp = temp->next;

        } while (temp != head);

        cout << "Student not found.\n";
    }

    void leave(string name)
    {
        if (head == NULL)
        {
            cout << "Circle is empty.\n";
            return;
        }

        Node *temp = head;

        do
        {
            if (temp->name == name)
            {
                // Only one node
                if (temp->next == temp)
                {
                    head = NULL;
                    delete temp;
                }
                else
                {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;

                    if (temp == head)
                        head = head->next;

                    delete temp;
                }

                cout << name << " left the circle.\n";
                return;
            }

            temp = temp->next;

        } while (temp != head);

        cout << "Student not found.\n";
    }
};

int main()
{
    CircularDLL circle;

    int choice;
    string name, target;

    do
    {
        cout << "\n===== MENU =====\n";
        cout << "1. Student Join (End)\n";
        cout << "2. Student Join After\n";
        cout << "3. Student Leave\n";
        cout << "4. Display Circle\n";
        cout << "5. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            cout << "Enter student name: ";
            getline(cin, name);
            circle.join(name);
            circle.display();
            break;

        case 2:
            cout << "Enter existing student: ";
            getline(cin, target);

            cout << "Enter new student: ";
            getline(cin, name);

            circle.joinAfter(target, name);
            circle.display();
            break;

        case 3:
            cout << "Enter student to leave: ";
            getline(cin, name);

            circle.leave(name);
            circle.display();
            break;

        case 4:
            circle.display();
            break;

        case 5:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 5);

    return 0;
}