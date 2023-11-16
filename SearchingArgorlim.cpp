#include <iostream>
using namespace std;
int search(int arr[],int n,int val)
{
	for (int i=0;i<n;i++)
	{
		if ( arr[i] == val)
		return i;
	}
	return -1;
}

int BinarySearch(int arr[],int l,int r,int val)
{
	if ( r>=l){

	int mid= l+(r-l)/2;
	if ( arr[mid] == val) return mid;
	if (arr[mid] > val) return BinarySearch(arr,l,mid-1,val);
 	return BinarySearch(arr,mid+1,r,val);	
	}
	return -1;
}
void nhap(int arr[],int &n)
{
	cout<<"n = "; cin>>n;
	for (int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
}
int main()
{
	int arr[100],n;
	nhap(arr,n);
	//cout<<search(arr,n,10);
	cout<<endl<<BinarySearch(arr,0,n-1,3);
}
