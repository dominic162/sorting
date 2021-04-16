/*
    Given a array containing only 0, 1, 2. Sort it.
*/

#include<iostream>
using namespace std;

class Solution
{
    public:
    void sort012(int a[], int n)
    { 
        int low=0,mid=0,high=n-1;
        while(mid<=high){
            
            switch(a[mid]){
                
                case 0:
                    swap(a[low],a[mid]);
                    low++;
                    mid++;
                    break;
                case 1:
                    mid++;
                    break;
                case 2:
                    swap(a[mid],a[high]);
                    high--;
                    break;
                
            }
            
            
        }
    }
    
};

int main(){
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    int* arr= new int[n];

    cout<<"Enter elements of array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    Solution sl;
    sl.sort012(arr,n);

    cout<<"\nSorted array is: ";
    for(int i=0;i<n;++i){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}