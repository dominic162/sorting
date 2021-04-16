/*
    Given a array find kth largest element.
    In this sol lomuto partition is used because it is more efficient on average.
    Another sol can be sorting adn then returning arr[k-1];
*/


#include<iostream>
using namespace std;

class solution{
    public:
        int* makearr(int n);
        int klargest(int* arr,int n, int k);

        int lomuto_part(int* arr,int l,int h);
};

int* solution::makearr(int n){
    int* arr = new int[n];
    cout<<"Enter elements of array: ";
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }

    return arr;
}

int solution::lomuto_part(int* arr, int l ,int h){
    int ans=l-1;

    for(int i=l;i<h;++i){
        if(arr[i]<arr[h]){
            ans++;
            swap(arr[ans],arr[i]);
        }
    }
    ans++;
    swap(arr[ans],arr[h]);
    return ans;
}

int solution::klargest(int* arr,int n,int k){
    
    int l=0,r=n-1;
    while(l <= r){
        int p = this->lomuto_part(arr,l,r);

        if(p == k-1){
            return arr[p];
        }
        else{

            if(p > k-1){
                r=p-1;
            }
            else{
                l=p+1;
            }

        }
    }
    return -1;
}

int main(){
    
    int n;
    cout<<"Enter number of elements of array: ";
    cin>>n;
    solution sl;

    int* arr = sl.makearr(n);

    int k;
    cout<<"Enter value of k: ";
    cin>>k;
    
    cout<<k<<" greatest element is "<<sl.klargest(arr,n,k);


    return 0;
}