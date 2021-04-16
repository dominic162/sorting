/*
    Count sort;
*/

#include<iostream>
using namespace std;

class solution{
    public:
        int* make_arr(int n);

        void count_sort(int* arr,int n,int k);

        void disp_arr(int* arr,int n);
};

void solution::disp_arr(int* arr,int n){
    cout<<"\nArray elements are: ";
    for(int i=0;i<n;++i){
        cout<<arr[i]<<" ";
    }
    return ;
}

void solution::count_sort(int* arr, int n, int k){
    int* freq= new int [k+1];
    for(int i=0;i<=k;++i){
        freq[i]=0;
    }

    for(int i=0;i<n;++i){
        freq[arr[i]]++;
    }
    
    for(int i=1;i<=k;++i){
        freq[i]+=freq[i-1];
    }

    int* output= new int[n];
    for(int i=n-1;i>=0;i--){
        output[freq[arr[i]]-1]=arr[i];
        freq[arr[i]]--;
    }
    for(int i=0;i<n;i++){
        arr[i]=output[i];
    }
    delete [] output;
    delete [] freq;

    return ;

}

int* solution::make_arr(int n){
    int* arr = new int[n];

    cout<<"Enter elements of array: ";
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    return arr;

}

int main(){
    solution sl;
    int n;
    cout<<"Enter number of elements in array: ";
    cin>>n;
    int* arr = sl.make_arr(n);

    int k;
    cout<<"Enter range of array elements: ";
    cin>>k;

    sl.count_sort(arr, n ,k);

    sl.disp_arr(arr,n);
    return 0;
}