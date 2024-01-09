#include <iostream>
using namespace std;
class test{
    public :
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
        
        
        //-------------------------------ASC-------------------
        int partitionASC(int arr[], int low, int high) {
            int pivot = arr[high];  
            int i = (low - 1);  

            for (int j = low; j <= high - 1; j++) {
                if (arr[j] <= pivot) {
                i++; 
                swap(arr[i], arr[j]);
                }
            }
            swap(arr[i + 1], arr[high]);
            return (i + 1);
        }

        void quickSortASC(int arr[], int low, int high) {
            if (low < high) {
                int pi = partitionASC(arr, low, high);
                quickSortASC(arr, low, pi - 1);
                quickSortASC(arr, pi + 1, high);
            }
        }
        void testQuickSortASC(){
            quickSortASC(arr,0,n-1);
        }
        
        
        
        
        //-----------------DESC--------------------
        int partitionDESC(int arr[], int low, int high) {
            int pivot = arr[high];  
            int i = (low - 1);  

            for (int j = low; j <= high - 1; j++) {
                if (arr[j] >= pivot) {
                i++; 
                swap(arr[i], arr[j]);
                }
            }
            swap(arr[i + 1], arr[high]);
            return (i + 1);
        }

        void quickSortDESC(int arr[], int low, int high) {
            if (low < high) {
                int pi = partitionDESC(arr, low, high);
                quickSortDESC(arr, low, pi - 1);
                quickSortDESC(arr, pi + 1, high);
            }
        }
        void testQuickSortDESC(){
            quickSortDESC(arr,0,n-1);
        }


};
int main()
{
    test t;
    t.nhap();
    //t.testQuickSortASC();
    t.testQuickSortDESC();
    t.xuat();
}