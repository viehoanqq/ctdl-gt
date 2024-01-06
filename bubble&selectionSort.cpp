#include <iostream>
using namespace std;
class test{
    private :
        int arr[10];
        int n;
    public:
        void nhap(){
            cin>>n;
            for (int i=0;i<n;i++)
            {
                cin>>arr[i];
            }
        }
        void xuat(){
            for (int i=0;i<n;i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
        
        // bubbleSort
        void bubbleSortAsc()
        {
            for (int i=0;i<n-1;i++)
            for (int j=0;j<n-i-1;j++){
                if (arr[j] > arr[j+1])
                {
                    swap (arr[j] ,arr[j+1]);
                }
            }
        }
        void bubbleSortDesc(){
            for (int i=0;i<n-1;i++){
                for (int j=0;j<n-i-1;j++){
                    if (arr[j] < arr[j+1])
                    {
                        swap(arr[j],arr[j+1]);
                    }
                }
            }
        }
        
        
        //selection
        void selectionSortAsc(){
            for (int i=0;i<n-1;i++)
            for (int j=i+1;j<n;j++)
            if (arr[i] > arr[j]){
                swap(arr[i],arr[j]);
            }
        }
        
        void selectionSortDesc(){
            for (int i=0;i<n-1;i++)
            for (int j=i;j<n;j++)
            if (arr[i] < arr[j]) {
                swap(arr[i],arr[j]);
            }
        }
        
        
        //insertion

};
int main()
{
    test t;
    t.nhap();
    //t.bubbleSortAsc();
    //t.bubbleSortDesc();
    //t.selectionSortAsc();
    //t.selectionSortDesc();
    t.xuat();
}
