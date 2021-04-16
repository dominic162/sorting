/*
    Given a array of even and odd elements. Manipulate array such that all even elements come after all odd elements.
    Position of even elements doesn't matter to even elements.
*/

#include<iostream>
using namespace std;

class solution{
    public:
        int* makearr(int n);
        
        void segregate(int* arr, int n);

        void show_arr(int* arr,int n);
};

void solution::show_arr(int* arr, int n){
    cout<<"\nArray elements are: ";
    for(int i=0;i<n;++i){
        cout<<arr[i]<<" ";
    }
}

void solution::segregate(int* arr, int n){

    int pos=0;
    for(int i=0;i<n;i++){
        if(arr[i] < 0){
            swap(arr[i],arr[pos]);
            pos++;
        }
    }

}

int* solution::makearr(int n){
    int* arr= new int[n];
    cout<<"Enter array elements: ";
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
    int* arr = sl.makearr(n);

    sl.segregate(arr,n);

    sl.show_arr(arr,n);

    return 0;
}