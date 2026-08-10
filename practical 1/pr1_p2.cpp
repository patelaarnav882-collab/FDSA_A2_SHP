#include<iostream>
using namespace std;

int main()
{
    int n;
    int i,j;
    cout<<"Enter total number of items: ";
    cin>>n;
    int arr[n];
    cout<<"Enter number's of items: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    bool printed = false;
    for(i=0;i<n;i++)
    {
        int count = 1;
        for(j=i+1;j<n;j++)
        {
            if(arr[i]==arr[j])
            {
                count++;
            }
        }

        
        for (int k = 0; k < i; k++)
        {
            if (arr[i] == arr[k])
            {
                printed = true;
                break;
            }
        }

        if (count > 1 && !printed)
        {
            cout << "Repeated Book is : " << arr[i] << endl;
        }
    }
    
    if(printed==false)
    cout<<"NO book is Repeated !!!"<<endl;


    return 0;
}
