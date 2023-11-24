#include <iostream>
#include <bits/stdc++.h>
using namespace std;

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
    vector<int>dist(n+1,1e9);
    queue<int>d;
    d.push(1);
    dist[1]=0;
    while(!d.empty()){
        int val = d.front();
        d.pop();
        for(auto it:adj[val]){
            if(dist[val]+1<dist[it]){
                dist[it] = dist[val]+1;
                d.push(it);
            }
        }
    }
    if(dist[n]==1e9)cout<<-1<<endl;
    else cout<<dist[n]<<endl;

    return 0;
}
