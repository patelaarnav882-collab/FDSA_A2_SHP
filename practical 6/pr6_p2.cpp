#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string page;
    Node *next;

    Node(string p)
    {
        page = p;
        next = NULL;
    }
};

class BrowserHistory
{
    Node *top;

public:
    BrowserHistory()
    {
        top = NULL;
    }

    void visit(string url)
    {
        Node *newNode = new Node(url);
        newNode->next = top;
        top = newNode;

        cout << "Visited: " << url << endl;
        cout << "Current Page: " << top->page << endl;
    }

    void back()
    {
        if (top == NULL)
        {
            cout << "No pages in history." << endl;
            return;
        }

        if (top->next == NULL)
        {
            cout << "Cannot go back. No previous page available." << endl;
            cout << "Current Page: " << top->page << endl;
            return;
        }

        Node *temp = top;
        top = top->next;
        delete temp;

        cout << "Back Operation Successful." << endl;
        cout << "Current Page: " << top->page << endl;
    }

    ~BrowserHistory()
    {
        while (top != NULL)
        {
            Node *temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main()
{
    BrowserHistory browser;

    int n;
    cout << "Enter number of operations: ";
    cin >> n;

    cout << "\n1 = Visit Page\n2 = Back\n";

    for (int i = 0; i < n; i++)
    {
        int choice;
        cout << "\nEnter operation: ";
        cin >> choice;

        if (choice == 1)
        {
            string url;
            cout << "Enter page name: ";
            cin >> url;
            browser.visit(url);
        }
        else if (choice == 2)
        {
            browser.back();
        }
        else
        {
            cout << "Invalid Operation!" << endl;
        }
    }

    return 0;
}