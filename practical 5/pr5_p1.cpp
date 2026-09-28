#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string song;
    Node *prev;
    Node *next;

    Node(string s)
    {
        song = s;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList
{
    Node *head;
    Node *tail;

public:
    DoublyLinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void addAtBeginning(string song)
    {
        Node *newNode = new Node(song);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

        cout << "Song added at beginning.\n";
    }

    void addAtEnd(string song)
    {
        Node *newNode = new Node(song);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        cout << "Song added at end.\n";
    }

    void insertAfterSong(string target, string song)
    {
        Node *temp = head;

        while (temp != NULL && temp->song != target)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "Song not found.\n";
            return;
        }

        Node *newNode = new Node(song);

        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != NULL)
        {
            temp->next->prev = newNode;
        }
        else
        {
            tail = newNode;
        }

        temp->next = newNode;

        cout << "Song inserted after " << target << ".\n";
    }

    void removeFirst()
    {
        if (head == NULL)
        {
            cout << "Playlist is empty.\n";
            return;
        }

        Node *temp = head;

        if (head == tail)
        {
            head = tail = NULL;
        }
        else
        {
            head = head->next;
            head->prev = NULL;
        }

        delete temp;

        cout << "First song removed.\n";
    }

    int countSongs()
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

    void display()
    {
        if (head == NULL)
        {
            cout << "Playlist is empty.\n";
            return;
        }

        cout << "Playlist: ";

        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->song << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main()
{
    DoublyLinkedList playlist;

    int choice;
    string song, target;

    do
    {
        cout << "\n===== MUSIC PLAYLIST MENU =====\n";
        cout << "1. Add Song at Beginning\n";
        cout << "2. Add Song at End\n";
        cout << "3. Insert Song After Given Song\n";
        cout << "4. Remove First Song\n";
        cout << "5. Count Songs\n";
        cout << "6. Display Playlist\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            cout << "Enter song name: ";
            getline(cin, song);
            playlist.addAtBeginning(song);
            playlist.display();
            break;

        case 2:
            cout << "Enter song name: ";
            getline(cin, song);
            playlist.addAtEnd(song);
            playlist.display();
            break;

        case 3:
            cout << "Enter existing song name: ";
            getline(cin, target);

            cout << "Enter new song name: ";
            getline(cin, song);

            playlist.insertAfterSong(target, song);
            playlist.display();
            break;

        case 4:
            playlist.removeFirst();
            playlist.display();
            break;

        case 5:
            cout << "Total Songs = " << playlist.countSongs() << endl;
            playlist.display();
            break;

        case 6:
            playlist.display();
            break;

        case 7:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid Choice.\n";
        }

    } while (choice != 7);

    return 0;
}