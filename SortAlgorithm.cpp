#include <iostream>
using namespace std;
void bubbleSort(int a[],int n)
{
	for (int i=0;i<n-1;i++)
	for (int j=0;j<n-i-1;j++)
	{
		if ( a[j] > a[j+1])
		{
			swap(a[j],a[j+1]);
		}
	}
}

void selectionSort(int a[],int n)
{
	for (int i=0;i<n-1;i++)
	{
		for (int j=i+1;j<n;j++)
		{
			if ( a[i] > a[j])
			swap(a[i] , a[j]);
		}
	}
}

void insertionSort(int a[],int n)
{
	for (int i=0;i<n;i++)
	{
		int j=i;
		while (j>=1 && a[j]<a[j-1])
		{
			swap(a[j],a[j-1]);
			j--;
		}
	}
}

void countingSort(int a[],int n)
{
	int arr[10];
	for (int i=0;i<10;i++) arr[i] =0;
	for (int i=0;i<n;i++)
	{
		arr[a[i]]++;
	}
	int k=0;
	for (int i=0;i<10;i++)
		for (int j=0;j<arr[i];j++)
		{
			a[k]=i;
			k++;
		}
	
}

void nhap(int a[],int &n)
{
	cout<<"n = "; cin>>n;
	for (int i=0;i<n;i++)
	{
		cin>>a[i];
	}
}
void xuat(int a[],int n)
{
	for (int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
}
int main()
{
	int a[100],n;
	nhap(a,n);
	//bubbleSort(a,n);
	//selectionSort(a,n);
	//insertionSort(a,n);
	//countingSort(a,n);
	xuat(a,n);
	
}
