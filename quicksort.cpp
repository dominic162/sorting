/*
	Quicksort algo
*/


#include<bits/stdc++.h>
using namespace std;


/* 
Lomuto partition:- pivot is last element
If position of pivot is given then first swap pivot and last element after that use lomuto partition.
*/
int partition(int a[],int low,int high){
	int i=low-1;
	for(int j=low;j<=high-1;j++){

		if(a[j]<a[high]){
			i++;
			swap(a[i],a[j]);
		}
	}
	swap(a[i+1],a[high]);
	return (i+1);
}

void quicksort(int a[],int start,int end){
	begin:
		if(start<end){
			int pi;
			pi=partition(a,start,end);


			quicksort(a,start,pi-1);
			start=pi+1;
			//quicksort(a,pi+1,end);
			goto begin; // tailcall elimination
		}
}

int main(){
	int n;
	cout<<"Enter number of elements: ";
	cin>>n;
	cout<<"Enter elements: ";
	int *arr=new int [n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	quicksort(arr,0,n-1);

	cout<<"Sorted array is: "<<endl;
	for(int i=0;i<n;i++){
		cout<<arr[i]<<endl;
	}
	return 0;
}