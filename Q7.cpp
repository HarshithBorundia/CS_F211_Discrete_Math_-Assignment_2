#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void dfs(vector<int>&visited,vector<vector<int>>adj,int i){
    visited[i] = 1;
    for(auto it:adj[i]){
        if(visited[it]==-1){
            dfs(visited,adj,it);
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    for(int i=0;i<m;i++){
        int val1,val2;
        cin>>val1>>val2;
        adj[val1].push_back(val2);
        adj[val2].push_back(val1);
    }
    vector<int>visited(n+1,-1);
    int cnt = 0;
    for(int i=1;i<n+1;i++){
        if(visited[i]==-1){
            dfs(visited,adj,i);
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
