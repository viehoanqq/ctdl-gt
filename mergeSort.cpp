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
        
        
        
        // ------------------ ASC -----------------------
        void mergeASC(int arr[],int l,int r,int mid){
            int n1=mid-l+1;
            int n2= r - mid;
            int left[n1];
            int right[n2];
            
            // tach pt cua mang arr cho 2 mang left va right
            for (int i=0;i<n1;i++){
                left[i]=arr[l+i];
            }
            for (int i=0;i<n2;i++){
                right[i] = arr[mid+1+i];
            }
            
            //gop 2 mang da chia vao mang arr da sap xep
            int i=0;
            int j=0;
            int k=l;
            while(i<n1 && j<n2){
                if (left[i] < right[j]){
                    arr[k] = left[i];
                    i++;
                    k++;
                }
                else{
                    arr[k] = right[j];
                    j++;
                    k++;
                }
            }   
            
            //tiep tuc xep vao arr neu con du 
            while(i<n1){
                arr[k] = left[i];
                i++;
                k++;
            }
            while (j<n2){
                arr[k] = right[j];
                j++;
                k++;
            }
        }
        
        void mergeSortASC(int arr[],int l,int r){
            if (l < r){
                int mid = l + (r-l)/2;
                mergeSortASC(arr,l,mid);
                mergeSortASC(arr,mid+1,r);
                mergeASC(arr,l,r,mid);
            }
        }
        
        void testMergeSortASC(){
            mergeSortASC(arr,0,n-1);
        }
        
        
        
        //-----------------------DESC-----------------
        void mergeDESC(int arr[],int l,int r,int mid){
            int n1= mid -l +1;
            int n2= r -mid;
            
            int left[n1];
            int right[n2];
            for (int i=0;i<n1;i++){
                left[i] = arr[i+l];
            }
            for (int i=0;i<n2;i++){
                right[i] = arr[mid+i+1];
            }
            
            int i=0;
            int j=0;
            int k=l;
            while (i<n1 && j<n2){
                if (left[i] > right[j]){
                    arr[k]=left[i];
                    i++;
                    k++;
                }
                else{
                    arr[k] = right[j];
                    j++;
                    k++;
                }
            }
            
            while (i<n1){
                arr[k] = left[i];
                i++;
                k++;
            }
            while (j<n2){
                arr[k] = right[j];
                j++;
                k++;
            }
            
            
        }
        
        void mergerSortDESC(int arr[],int l,int r){
            if(l<r){
                int mid = l+(r-l)/2;
                mergerSortDESC(arr,l,mid);
                mergerSortDESC(arr,mid+1,r);
                mergeDESC(arr,l,r,mid);
            }
        }
        void testMergeSortDESC(){
            mergerSortDESC(arr,0,n-1);
        }

};
int main()
{
    test t;
    t.nhap();
    //t.testMergeSortASC();
    //t.testMergeSortDESC();
    t.xuat();
}