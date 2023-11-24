#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class DisjointSet{
  vector<int>size;
  vector<int>parent;
  public:
      DisjointSet(int n){
         size.resize(n,1);
         parent.resize(n);
         for(int i=0;i<n;i++){
             size[i] = 1;
             parent[i] = i;
         }
     }
     int findUPar(int u){
         if(parent[u]==u) return u;
         return parent[u] = findUPar(parent[u]);
     }
     void unionBySize(int u , int v){
         int uPar = findUPar(u);
         int vPar = findUPar(v);
         if(uPar==vPar) return;
         if(size[uPar]<size[vPar]){
             parent[uPar] = vPar;
             size[vPar]+=size[uPar];
         }
         else{
             parent[vPar] = uPar;
             size[uPar]+= size[vPar];
         }
     }
};
int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,pair<int,int>>>adj(m);
    for(int i=0;i<m;i++){
        int val1,val2,val3;
        cin>>val1>>val2>>val3;
        adj[i]={val3,{val1,val2}};
    }
    sort(adj.begin(),adj.end());
    DisjointSet ds(n+1);
    int sum = 0;
    for(auto it:adj){
        int wt = it.first;
        int node1 = it.second.first;
        int node2 =  it.second.second;
        if(ds.findUPar(node1)!=ds.findUPar(node2)){
            sum+= wt;
            ds.unionBySize(node1,node2);
        }
    }
    cout<<sum<<endl;
    return 0;
}
