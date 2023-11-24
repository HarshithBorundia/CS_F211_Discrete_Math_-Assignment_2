#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void dfs(vector<int>&vis,vector<int>&temp,int x,vector<vector<int>>adj){
    vis[x] = 1;
    temp.push_back(x);
    for(auto it:adj[x]){
        if(!vis[it]){
            dfs(vis,temp,x,adj);
        }
    }
}
int main()
{
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    vector<vector<int>>adj(n+1);
    vector<vector<int>>adjReverse(n+1);
    for(int i=0;i<m;i++){
        int val1,val2;
        cin>>val1>>val2;
        adj[val1].push_back(val2);
        adjReverse[val2].push_back(val1);
    }
    vector<int>temp1;
    vector<int>temp2;
    vector<int>vis1(n+1,0);
    vector<int>vis2(n+1,0);
    dfs(vis1,temp1,x,adjReverse);
    dfs(vis2,temp2,y,adjReverse);
    vector<int>temp3;
    vector<int>temp4;
    vector<int>vis3(n+1,0);
    vector<int>vis4(n+1,0);
    dfs(vis3,temp3,x,adj);
    dfs(vis4,temp4,y,adj);
    for(int i=0;i<temp1.size();i++){
        int val = temp1[i];
        bool val1 = false;
        for(auto it:temp2){
            if(val==it){
                cout<<val<<" ";
                val1 = true;
                break;
            }
        }
        if(val1==true){
            break;
        }
    }
    for(int i=0;i<temp3.size();i++){
        int val = temp3[i];
        bool val1 = false;
        for(auto it:temp4){
            if(val==it){
                cout<<val<<" ";
                val1 = true;
                break;
            }
        }
        if(val1==true){
            break;
        }
    }

    return 0;
}
