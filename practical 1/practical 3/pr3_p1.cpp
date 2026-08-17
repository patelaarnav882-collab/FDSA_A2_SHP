#include <iostream>
using namespace std;

void BubbleSorting(int n, int a[])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
			{
				int temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}
		}
	}

	cout << "Sorted by Bubble Sorting : " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << endl;
	}
}
void selectionSorting(int n, int a[])
{
	for (int i = 0; i < n; i++)
	{
		int min = i;

		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[min])
			{
				min = j;
			}
		}
		int temp = a[min];
		a[min] = a[i];
		a[i] = temp;
	}

	cout << "Sorted By Selection Sort : " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << endl;
	}
}

void InsertionSorting(int n, int a[])
{
	
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }

	cout << "Sorted By Insertion Sort : " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << endl;
	}
}
int main()
{
	int n;
	cout << "Enter Total Number of Students : ";
	cin >> n;
	int a[n];
	cout << "Enter Marks of all the students : ";
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	BubbleSorting(n, a);
	selectionSorting(n, a);
	InsertionSorting(n, a);

	return 0;
}