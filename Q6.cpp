#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int noOfCourses;
    cin>>noOfCourses;
    int j  = 1;
    vector<vector<int>>adj(noOfCourses+1);
    for(int i=0;i<noOfCourses;i++){
        int prereq;
        cin>>prereq;
        for(int k=0;k<prereq;k++){
            int val;
            cin>>val;
            adj[val].push_back(j);
        }
        j++;
    }
    vector<int>indegree(noOfCourses+1,0);
    for(int i=1;i<=noOfCourses;i++){
        for(auto it:adj[i]){
            indegree[it]++;
        }
    }
    queue<int>d;
    for(int i=1;i<indegree.size();i++){
        if(indegree[i]==0){
            d.push(i);
        }
    }
    vector<int>topo;
    while(!d.empty()){
        int node = d.front();
        topo.push_back(node);
        d.pop();
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                d.push(it);
            }
        }
    }
    if(topo.size() == noOfCourses){
        for(auto it:topo){
            cout<<it<<" ";
        }
    }
    else{
        cout<<-1<<endl;
    }
    return 0;
}
