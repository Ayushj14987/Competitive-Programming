#include<bits/stdc++.h>
#include<cmath>
using namespace std;
typedef long long ll;
class SEGTree{
    vector<int>seg;
    public:
    SEGTree(int n){
        seg.resize(4*n+1);
    }
    void build(int ind,int low, int high,int arr[]){
        if(low==high){
            seg[ind] = arr[low];
            return;
        }
        int mid = (low+high)/2;
        build(2*ind+1,low,mid,arr);
        build(2*ind+2,mid+1,high,arr);
        seg[ind] = min(seg[2*ind+1],seg[2*ind+2]);
    }
    int query(int ind,int low,int high, int l, int r){
        //complete overlap l low high r
        if(low>=l && r>=high){
            return seg[ind];
        }
        //no overlap l r low high || low high l r
        if(low>r || high<l){
            return INT_MAX;
        }
        int mid =  (low+high)>>1;
        int left = query(2*ind+1,low,mid,l,r);
        int right = query(2*ind+2,mid+1,high,l,r);
        return min(left,right);
    }
    void update(int ind,int low,int high, int i, int val){
        if(low==high){
            seg[ind] = val;
            return;
        }
        int mid = (low+high)>>1;
        if(i<=mid){
            update(2*ind+1,low,mid,i,val);
        }
        else{
            update(2*ind+2,mid+1,high,i,val);
        }
        seg[ind] = min(seg[2*ind+1],seg[2*ind+2]);
    }
    void print(){
        for(int i=0; i<seg.size(); i++){
            cout<<seg[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    SEGTree sg(n);
    sg.build(0,0,n-1,a);
    sg.print()
}