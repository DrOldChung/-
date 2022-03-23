#include<iostream>
#include<vector>
using namespace std;

void qsort(int left,int right,vector<int>&vec){
    if(left>=right)
        return;
    int i=left-1,j=right+1;
    int mid = vec[left+(right-left)/2];
    while(i<j){
        while(vec[++i]<mid);
        while(vec[--j]>mid);
        if(i<j){
            swap(vec[i],vec[j]);
        }
    }
    qsort(left,j,vec);
    qsort(j+1,right,vec);
}
int main(){
    int n;
    cin>>n;
    vector<int>vec(n,0);
    for(int i=0;i<n;++i){
        cin>>vec[i];
    }
    qsort(0,n-1,vec);
    
    for(auto i:vec)
        cout<<i<<' ';
}
