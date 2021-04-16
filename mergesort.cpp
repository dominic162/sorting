//merge sort
#include<bits/stdc++.h>
using namespace std;

void merge(int *marr,int s,int m,int e){ //merge arrays
    
    int i,j=0,n1=m-s+1,n2=e-m;
    int *l=new int [n1];
    int *r=new int [n2];
    for(i=s;i<=m;i++){
        l[j]=marr[i];
        j++;
    }
    j=0;
    for(i=m+1;i<=e;i++){
        r[j]=marr[i];
        j++;
    }
    i=0;
    j=0;
    while(i<n1 && j<n2){
        if(l[i]<r[j]){
            marr[s]=l[i];
            i++;
        }
        else{
            marr[s]=r[j];
            j++;
        }
        s++;
    }
    if(i==n1){
        for(;j<n2;j++){
            marr[s]=r[j];
            s++;
        }
    }
    else{
        for(;i<n1;i++){
            marr[s]=l[i];
            s++;
        }
    }
    return ;
}

void mergesort(int *copyarr,int start,int end){ //divide array in two halves
    int middle; 
    if(start==end){
        return ;
    }
    middle=(start+end)/2;
    mergesort(copyarr,start,middle);
    mergesort(copyarr,middle+1,end);
    merge(copyarr,start,middle,end);
    return ;
}

int main(){
    int n;
    cout<<"Enter number of elements in array:- ";
    cin>>n;
    int *arr=new int [n];
    cout<<"Enter elements of array:- ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    mergesort(arr,0,n-1);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}