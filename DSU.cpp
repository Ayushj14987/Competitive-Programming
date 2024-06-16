#include<bits/stdc++.h>
#include<cmath>
using namespace std;
#define int long long
class DisjointSet{
    vector<int>rank,parent,size;
public:
    //initializing disjoint set
    DisjointSet(int n){
        rank.assign(n+1,0);
        parent.assign(n+1,0);
        size.assign(n+1,1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
    }
    // path compression plus finding ultimate parent
    int findpar(int node){
        if(node==parent[node]){
            return node;
        }
        parent[node] =  findpar(parent[node]);
        return parent[node];
    }
    void unionbyrank(int u,int v){
        int ul_u = findpar(u);
        int ul_v = findpar(v);
        if(ul_u == ul_v)return;
        if(rank[ul_u]<rank[ul_v]){
            parent[ul_u] = ul_v;
        }
        else if(rank[ul_v]<rank[ul_u]){
            parent[ul_v] = ul_u;
        }
        else{
            parent[ul_u] = ul_v;
            rank[ul_v]++;
        }
    }
    void unionbysize(int u,int v){
        int ul_u = findpar(u);
        int ul_v = findpar(v);
        if(ul_u==ul_v)return;
        if(size[ul_u]<size[ul_v]){
            parent[ul_u] = ul_v;
            size[ul_v] += size[ul_u];
        }
        else{
            parent[ul_v] = ul_u;
            size[ul_u] += size[ul_v];
        }
    }
};
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    DisjointSet ds(7);
    // Union by rank code commented out
    /* 
    ds.unionbyrank(1,2);
    ds.unionbyrank(2,3); 
    ds.unionbyrank(4,5); 
    ds.unionbyrank(6,7); 
    ds.unionbyrank(5,6); 
    if(ds.findpar(3)==ds.findpar(7)){
        cout<<"Same"<<endl;
    }    
    else{
        cout<<"Not Same"<<endl;
    }
    ds.unionbyrank(3,7);
    if(ds.findpar(3)==ds.findpar(7)){
        cout<<"Same"<<endl;
    }    
    else{
        cout<<"Not Same"<<endl;
    }
    */
   // Union by size code active
    DisjointSet(7);
    ds.unionbysize(1,2);
    ds.unionbysize(2,3);
    ds.unionbysize(4,5);
    ds.unionbysize(6,7);
    ds.unionbysize(5,6);
    if(ds.findpar(3)==ds.findpar(7)){
        cout<<"Same"<<endl;
    }
    else{
        cout<<"Not Same"<<endl;
    }
    ds.unionbysize(3,7);
    if(ds.findpar(3)==ds.findpar(7)){
        cout<<"Same"<<endl;
    }
    else{
        cout<<"Not Same"<<endl;
    }
}