/*
    Given intervals. Merge overlapping intervals;
*/

#include<iostream>
#include<vector>
using namespace std;

class interval{
    public:
        int start;
        int  end;
};

class solution{
    public:
        vector<interval> add_interval(int n);
        
        vector<interval> merge_interval(vector<interval>,int n);

        void disp_merge_inter(vector<interval> arr);
};

void solution::disp_merge_inter(vector<interval> arr){
    cout<<"\nMerged array is: ";
    
    for(int i=0;i<arr.size();++i){
        cout<<arr[i].start<<" "<<arr[i].end<<endl;
    }
    
    return ;
}

vector<interval> solution::merge_interval(vector<interval> arr,int n){
    int vsize=arr.size();
    if(vsize<=1){
        return arr;
    }

    vector<interval> ans;
    interval rans;
    rans.start=arr[0].start;
    rans.end=arr[0].end;

    for(int i=1;i<n;++i){
        if(rans.end>=arr[i].start){
            rans.end=max(rans.end,arr[i].end);
        }
        else{
            ans.push_back(rans);
            rans.start=arr[i].start;
            rans.end=arr[i].end;
        }
    }
    ans.push_back(rans);
    return ans;

}

vector<interval> solution::add_interval(int n){
            vector<interval> inter(n);
            cout<<"Enter intervals: ";
            int a,b;
            for(int i=0;i<n;i++){
                cin>>a>>b;
                inter[i].start=a;
                inter[i].end=b;
            }
            return inter;
        }

int main(){

    int n;
    cout<<"Enter number of intervals: ";
    cin>>n;
    solution sl;
    vector<interval> arr=sl.add_interval(n);

    vector<interval> ans=sl.merge_interval(arr,n);

    sl.disp_merge_inter(ans);
    return 0;
}