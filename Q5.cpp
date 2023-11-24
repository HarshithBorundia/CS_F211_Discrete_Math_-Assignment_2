#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool dfs(vector<int>&visited,vector<vector<int>>adj,int i,int color){
    visited[i] = color;
    for(auto it:adj[i]){
        if(visited[it]==-1){
            bool val1 = dfs(visited,adj,it,!color);
            if(val1==false) return val1;
        }
        else if(visited[it]==color)return false;
    }
    return true;
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
    vector<int>color(n+1,-1);
    int cnt = 0;
    for(int i=1;i<n+1;i++){
        if(color[i]==-1){
           bool val =  dfs(color,adj,i,0);
            if(val==false){
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    cout<<"YES"<<endl;
    return 0;
}
