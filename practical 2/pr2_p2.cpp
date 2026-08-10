#include <iostream>
using namespace std;

int main()
{
    int n,find;
    cout << "Enter total number of books : ";
    cin >> n;
    int bcode[n];
    cout << "Enter books code : ";
    for (int i = 0; i < n; i++)
    {
        cin >> bcode[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (bcode[j] > bcode[j + 1])
            {
                int temp = bcode[j];
                bcode[j] = bcode[j + 1];
                bcode[j + 1] = temp;
            }
        }
    }
    cout<<"Enter Code of Book which you want to find : ";
    cin>>find;

    int start = 0;
    int end = n - 1;
    int mid = (start + end) / 2;

    while (start <= end)
    {
        if(bcode[mid]==find)
        {
            cout<<"The book is at "<<mid+1<<" position"<<endl;
        }

        else if(bcode[mid]>find)
        {
            end=mid-1;
        }

        else
        {
            start = mid+1;
        }
    }

    return 0;
}
