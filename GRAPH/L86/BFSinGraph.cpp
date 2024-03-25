#include <stdio.h>
#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

void prepareAdjList(unordered_map<int, set<int>> &adjList, vector<pair<int, int>> &edges)
{

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

void bfs(unordered_map<int, set<int>> &adjList, unordered_map<int, bool> &visited, vector<int> ans, int node)
{

    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        // store frontNode into ans
        ans.push_back(frontNode);

        // traverse all neighbours of front Node
        for (auto i : adjList[frontNode])
        {
            if (visited[i])
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{

    // for storing adjacency list
    unordered_map<int, set<int>> adjList;

    // for storing ans of bfs traversal
    vector<int> ans;

    // for identifying which node is visited during traversal
    unordered_map<int, bool> visited;

    // preparing adjacency list
    prepareAdjList(adjList, edges);

    // traverse all componenets of graph
    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i])
        {
            bfs(adjList, visited, ans, i);
        }
    }

    return ans;
}