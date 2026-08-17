#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "Sorted By Bubble Sort : " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
    cout<<endl;
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    cout << "Sorted By Selection Sort : " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
    cout<<endl;
}

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    cout << "Sorted By Insertion Sort : " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
    cout<<endl;
}

int main()
{
    int n;
    cout<<"Enter Total Number of buckets : ";
    cin >> n;

    int arr[n];

    cout<<"Enter Colour codes of Each Buckets : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout<<endl;
    bubbleSort(arr, n);
    selectionSort(arr, n);
    insertionSort(arr, n);

    return 0;
}