#include <iostream>
using namespace std;
class search{
    private :
        int n;
        int arr[10];
    public:
        void nhap(){
            cout<<"nhap: ";
            cin>>n;
            for (int i=0;i<n;i++){
                cin>>arr[i];
            }
        }
        void sort(){
            for (int i=0;i<n-1;i++)
            for (int j=i;j<n;j++)
            if (arr[i] > arr[j]){
                swap(arr[i],arr[j]);
            }
        }
        int count(){
            return n;
        }
        
        int linearSearch(){
            int a;
            cin>>a;
            for (int i=0;i<n;i++)
            if (arr[i] == a)
                return i;
            return -1;
        }
        
        int  binarySearch(int l,int r){
            int a;
            cin>>a;
            while (l<=r){
                int mid = l+(r-l)/2;
                if (arr[mid] == a) return mid;
                else if (a > mid)
                        l=mid+1;
                    else 
                        r=mid-1;
            }
            return -1;
            
            
        }
        int binarySearch2(int l,int r,int target){
            if (l > r ) return -1;
            int mid = l + (r-l)/2;
            if (arr[mid] == target) return mid;
            if (target < mid) return binarySearch2(l,mid-1,target);
            else return binarySearch2(mid+1,r,target);
        }
};

int main(){
    search test;
    test.nhap();
    test.sort(); // vi thuat toan tim kiem nhi phan can phai dung mang da sap xep
    cout<<test.binarySearch2(0,test.count()-1,3);
}
