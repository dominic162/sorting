/*
    Given packets of chocolate and number of students. Find the min difference of chocolate if all students are given exactly 1 packet of chocolate.
*/

#include<iostream>
#include<algorithm>
using namespace std;

class solution{
    public:
        int* makearr(int n);
        
        int mdiff(int* arr, int n, int m);
};

int solution::mdiff(int* arr, int n, int m){

    if(m < n){
        return -1;
    }

    sort(arr,arr+n);
    int ans=arr[m-1]-arr[0];
    int cdiff;
    for(int i=m;i<n;i++){
        cdiff=arr[i]-arr[i-m+1];
        if(cdiff<ans){
            ans=cdiff;
        }
    }

    return ans;
}

int* solution::makearr(int n){
    int* arr = new int[n];

    cout<<"Enter chocolates in each packet: ";
    
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }

    return arr;
}

int main(){

    int n;
    cout<<"Enter number of packets of chocolate: ";
    cin>>n;

    solution sl;
    int* arr=sl.makearr(n);

    int m;
    cout<<"Enter number of students: ";
    cin>>m;

    cout<<"Min diff is "<<sl.mdiff(arr, n ,m);

    return 0;
}