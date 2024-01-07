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
        
        void insertionSortASC() {
        for (int i = 1 ;i < n; i++) {
        int j = i;
        while (j >= 1 && arr[j] < arr[j-1]) {
            swap(arr[j],arr[j-1]);
            j--;
        }
        }
        }
        
        void insertionSortDESC() {
        for (int i = 1 ;i < n; i++) {
        int j = i;
        while (j >= 1 && arr[j] > arr[j-1]) {
            swap(arr[j],arr[j-1]);
           j--;
        }
        }
        }
        
        void countingSortASC(){
            int max =arr[0];
            for (int i=0;i<n;i++){
                if (arr[i] > max) max = arr[i];
            }
            
            int count[max] = {0};
            for (int i=0;i<n;i++){
                count[arr[i]]++;
            }
            
            int k=0;
            for (int i=0;i<=max;i++){
                while(count[i] > 0){
                    arr[k]=i;
                    k++;
                    count[i]--;
                }
            }
        }
        
        
        void countingSortDESC(){
            int max =arr[0];
            for (int i=0;i<n;i++){
                if (arr[i] > max) max = arr[i];
            }
            
            int count[max] = {0};
            for (int i=0;i<n;i++){
                count[arr[i]]++;
            }
            
            int k=0;
            for (int i=max;i>=0;i--){
                while(count[i] > 0){
                    arr[k]=i;
                    k++;
                    count[i]--;
                }
            }
        }
        
        

};
int main()
{
    test t;
    t.nhap();
    //t.insertionSortASC();
    //t.insertionSortDESC();
    //t.countingSortASC();
    //t.countingSortDESC();
    t.xuat();
}