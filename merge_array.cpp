/*
    Given 2 array. find their intersection;
*/

#include<iostream>
#include<vector>
using namespace std;

class solution{
    public:
        vector<int> mergearr(int* arr1,int n,int* arr2, int m);
        int* makearr(int n);
};

int* solution::makearr(int n){
    
    int* arr=new int[n];
    cout<<"Enter elements: ";
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }    

    return arr;
}

vector<int> solution::mergearr(int* arr1, int n , int* arr2 , int m){
    vector<int> v1;

    int i=0,j=0,pre=INT_MIN;
    while(i<n && j<m){

        if(arr1[i]<arr2[j]){
            if(arr1[i]!=pre){
                v1.push_back(arr1[i]);
                pre=arr1[i];
            }
            i++;
        }
        else{
            if(arr2[j]!=pre){
                v1.push_back(arr2[j]);
                pre=arr2[j];
            }
            j++;
        }

    }

    while(i<n){
        if(arr1[i]!=pre){
            v1.push_back(arr1[i]);
            pre=arr1[i];
        }
        i++;
    }

    while(j<m){
        if(arr2[j]!=pre){
            v1.push_back(arr2[j]);
            pre=arr2[j];
        }
        j++;
    }

    return v1;
}

int main(){

    solution sl;
    int n;
    cout<<"Enter number of elements in 1st array: ";
    cin>>n;

    int* arr1 = sl.makearr(n);
    

    int m;
    cout<<"Enter number of elements in 2nd array: ";
    cin>>m;
    int* arr2 = sl.makearr(m);

    
    vector<int> v1=sl.mergearr(arr1, n , arr2 , m);

    cout<<"Union of arrays is: ";
    for(int i=0;i<v1.size();++i){
        cout<<v1[i]<<" "; 
    }

    return 0;
}