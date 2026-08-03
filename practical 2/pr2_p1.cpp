#include<iostream>
using namespace std;

int main()
{
    int n;
    string find;
    int found = 0;
    cout<<"Enter number of vehicles: ";
    cin>>n;
    string num_plte[n];
    cout<<"Enter Number Plates of the vehicles : ";
    for(int i=0;i<n;i++)
    {
        cin>>num_plte[i];
    }

    cout<<"Enter Number Plate of the vehicle which you want to find : ";
    cin>>find;

    for(int i=0;i<n;i++)
    {
        if(num_plte[i]==find)
        {
            cout<<"The is on "<<i+1<<" parking lot"<<endl;
            found++;
            break;
        }
    }

    if(!found)
    {
        cout<<"The vehicle is not found or it must be exited"<<endl;
    }
    return 0;
}
