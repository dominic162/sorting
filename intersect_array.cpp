/*
    Given 2 arrays return intersection of them;
*/

#include<iostream>
#include<vector>
using namespace std;

class solution{

    public:
        vector<int> mergedarray(int* a, int* b, int n, int m);

};

vector<int> solution::mergedarray(int* a, int* b, int n, int m){
    vector<int> v1;

    int i=0,j=0;
    while(i < n && j < m){
        if(i > 0 && a[i]==a[i-1]){
            i++;
            continue;
        }

        if(a[i]==b[j]){
            v1.push_back(a[i]);
            i++;
            j++;
        }
        else{
            if(a[i] > b[j]){
                j++;
            }
            else{
                i++;
            }
        }

    }

    return v1;
}

int main(){

    int n;
    cout<<"Enter number of elements in 1st array: ";
    cin>>n;

    int* arr1 = new int[n];
    cout<<"Enter elements of array: "; 
    for(int i=0;i<n;++i){
        cin>>arr1[i];
    }

    int m;
    cout<<"Enter number of elements in 2nd array: ";
    cin>>m;

    int* arr2 = new int[m];
    cout<<"Enter elements of array: "; 
    for(int i=0;i<m;++i){
        cin>>arr2[i];
    }

    solution sl;
    vector<int> v1=sl.mergedarray(arr1, arr2, n, m);

    cout<<"Intersecting array is: ";
    for(int i=0;i<v1.size();i++){
        cout<<v1[i]<<" ";
    }

    return 0;
}