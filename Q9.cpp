#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>adj(n+1);
    for(int i=0;i<m;i++){
        int val1,val2,val3;
        cin>>val1>>val2>>val3;
        adj[val1].push_back({val2,val3});
        adj[val2].push_back({val1,val3});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>vis(n+1,0);
    pq.push({0,1});
    int sum = 0;
    while(!pq.empty()){
        int wt = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if(vis[node]==1)continue;
        vis[node]=1;
        sum+=wt;
        for(auto it:adj[node]){
            int adjNode = it.first;
            int edgeWt = it.second;
            if(!vis[adjNode]){
                pq.push({edgeWt,adjNode});
            }
        }
    }
    cout<<sum<<endl;

    return 0;
}
