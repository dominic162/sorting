/*
    Heap sort
*/


#include<iostream>
using namespace std;

class solution{
    public:
        int* make_arr(int n);

        void heap_sort(int* arr,int n);

        void build_heap(int* arr,int n);

        void heapify(int* arr,int n,int root);

        void disp_arr(int* arr,int n);
};

void solution::disp_arr(int* arr,int n){
    for(int i=0;i<n;++i){
        cout<<arr[i]<<" ";
    }
}

void solution::heapify(int* arr,int n,int root){
    
        int largest=root,li=2*root+1,ri=2*root+2;
        if(li<n && arr[li]>arr[largest]){
            largest=li;
        }
        if(ri<n && arr[ri]>arr[largest]){
            largest=ri;
        }
        if(largest!=root){
            swap(arr[largest],arr[root]);
            root=largest;
            heapify(arr,n,largest);
            
        }
}

void solution::build_heap(int* arr,int n){
    for(int i=(n-1)/2;i>=0;i--){
        heapify(arr,n,i);
    }

}

void solution::heap_sort(int* arr,int n){
    build_heap(arr,n);

    for(int i=n-1;i>=1;i--){
        swap(arr[i],arr[0]);
        heapify(arr,i,0);
    }

}

int* solution::make_arr(int n){
    int* arr = new int [n];

    cout<<"Enter elements of array: ";
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    return arr;
}

int main(){

    int n;
    cout<<"Enter number of elements in array: ";
    cin>>n;

    solution sl;
    int* arr = sl.make_arr(n);

    sl.heap_sort(arr,n);

    sl.disp_arr(arr,n);

    return 0;
}