/*
    Bucker sort. use only when data is uniformly distributed over a range.(It is best in this case)
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class solution{
    public:
        int* make_arr(int n);

        void bucket_sort(int* arr,int n,int k);

        void disp_arr(int* arr,int n);
};

void solution::disp_arr(int* arr,int n){

    cout<<"\nArray elements are: ";
    for(int i=0;i<n;++i){
        cout<<arr[i]<<" ";
    }

}

void solution::bucket_sort(int* arr,int n,int k){

    vector<int> bucket[k];  //make k buckets
    int mval=arr[0];    //find max value in arr to get range
    for(int i=1;i<n;++i){
        mval=max(mval,arr[i]);
    }
    mval++; //increment max val by one
    int bi;
    for(int i=0;i<n;++i){   
        bi=(k*arr[i])/mval; //to get index of bucket for current element
        bucket[bi].push_back(arr[i]);
    }
    int index=0;
    for(int i=0;i<k;i++){
        sort(bucket[i].begin(),bucket[i].end());    //sort individual buckets
        for(int j=0;j<bucket[i].size();++j){    
            arr[index]=bucket[i][j];    //add elements to array from each sorted buckets
            index++;
        }
    }

}

int* solution::make_arr(int n){

    int* arr= new int[n];
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

    int* arr=sl.make_arr(n);
    int k;
    cout<<"Enter number of buckets: ";
    cin>>k;
    
    sl.bucket_sort(arr,n,k);

    sl.disp_arr(arr,n);

    return 0;
}