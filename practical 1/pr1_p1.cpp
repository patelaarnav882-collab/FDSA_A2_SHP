#include <iostream>
using namespace std;
int main() 
{
    int n;
    cout<<"Enter total number of items: ";
    cin>>n;
    int arr[n];
    cout<<"Enter number's of items: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int d;
    cout<<"Enter number of hours: ";
    cin>>d;
    
    for(int i=0;i<d;i++)
    {
        int temp = arr[0]; 

        for (int j = 0; j < n - 1; ++j) {
            arr[j] = arr[j + 1];
        }

        arr[n - 1] = temp; 
    }
    
    return 0;
}