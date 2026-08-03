//With Recurssion
#include <iostream>
using namespace std;

int search(string plate[], int n, string target, int index)
{
    if (index == n)
        return -1;

    if (plate[index] == target)
        return index + 1;

    return search(plate, n, target, index + 1);
}

int main()
{
    int n;
    cout << "Enter number of vehicles: ";
    cin >> n;

    string plate[n];

    cout << "Enter license plate numbers:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> plate[i];
    }

    string target;
    cout << "Enter plate to search: ";
    cin >> target;

    int position = search(plate, n, target, 0);

    if (position == -1)
        cout << "License plate not found.";
    else
        cout << "License plate found at position: " << position;

    return 0;
}
