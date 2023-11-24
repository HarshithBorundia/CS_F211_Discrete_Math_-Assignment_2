#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool val  = false;
void dfs(int src,vector<int>&vis,vector<vector<int>>adj,vector<int>&temp,int dest){
    vis[src]=1;
    temp.push_back(src);
    if(src==dest && val ==false){
        val = true;
        cout<<temp.size()<<endl;
        for(auto it:temp){
            cout<<it<<" ";
        }
    }
    for(auto it:adj[src]){
        if(!vis[it]){
            dfs(it,vis,adj,temp,dest);
        }
    }
    temp.pop_back();
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>>adj(n+1);
    for(int i=1;i<=n-1;i++){
        int val1,val2;
        cin>>val1>>val2;
        adj[val1].push_back(val2);
        adj[val2].push_back(val1);
    }
    int u,v;
    cin>>u>>v;
    vector<int>vis(n+1,0);
    vector<int>temp;
    dfs(u,vis,adj,temp,v);

    return 0;
}
