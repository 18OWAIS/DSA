#include<stdio.h>
#include<iostream>
#include<list>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

void dfs(int node,unordered_map<int,bool> &visited,unordered_map<int,list<int>>& adj, vector<int>&component){
    //ans store
    component.push_back(node);

    visited[node]=true;


    //hr connected node ke liye recursive clall
    for(auto i:adj[node]){
        if(!visited[i])
        {
            dfs(i,visited,adj,component);
        }
    }    
}

vector<vector<int>>depthFirstSearch (int v,int e ,vector<vector<int>> &edges){

    unordered_map<int,list<int>> adj;

    //preparing adjacency list
    for(int i=0;i<edges.size();i++){
        int u= edges[i][0];
        int v= edges[i][1];

        adj[u].push_back(v);        
        adj[v].push_back(u);
            }

    vector<vector<int>> ans;

    unordered_map<int,bool> visited;

    for(int i=0; i<v;i++)
    {
        if(!visited[i])
        {
            vector<int> component;
            dfs(i,visited,adj,component);
            ans.push_back(component);
        }
    }
    return ans;
}