#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool dfs(int node,vector<vector<int>>adj,vector<int>&vis,vector<int>&temp,int parent){
    vis[node] = 1;
    temp.push_back(node);
    for(auto it:adj[node]){
        if(!vis[it]){
            if(dfs(it,adj,vis,temp,node)==true) return true;
        }
        else if(parent!=it){
            temp.push_back(it);
            return true;
        }
    }
    temp.pop_back();
    return false;
}
int main()
{
    int n;
    int m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    for(int i=0;i<m;i++){
        int val1,val2;
        cin>>val1>>val2;
        adj[val1].push_back(val2);
        adj[val2].push_back(val1);
    }
    vector<int>vis(n+1,0);
    vector<int>temp;
    bool val = false;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(dfs(i,adj,vis,temp,-1)==true){
                val = true;
            }
        }
    }
    if(val==false) cout<<-1<<endl;
    else{
        int val1 = temp[temp.size()-1];
        int j = temp.size()-1;
        cout<<val1<<" ";
        j--;
        while(j>=0 && temp[j]!=val1){
            cout<<temp[j]<<" ";
            j--;
        }
    }
    return 0;
}
