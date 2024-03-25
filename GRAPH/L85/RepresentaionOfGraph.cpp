#include <bits/stdc++.h>
// #include<iostream>
// #include<map>
// #include<vector>
// #include<unordered_map>
// #include<list>
using namespace std;
template<typename T>

class graph{
    public:

    unordered_map<T,list<T>> adj;

    void addEdge(T u, T v, bool direction){

        // directionn =0 ->undirected
        // directionn =1 ->directed

        //create an edge from u to v
        adj[u].push_back(v);
       
        if(direction==0){
        adj[v].push_back(u);
        }

    }
        void printAdjList()
        {
            for(auto i:adj){
                cout<<i.first<<"->";
                for(auto j:i.second){
                    cout<<j<<", ";
                }
                cout<<endl;
            }
        }   

};


int main(){

    int n;
    cout<<"enter the number of nodes"<<endl;
    cin>>n;
    
    int m;
    cout<<"enter the number of edges"<<endl;
    cin>>m;

    graph<int> g;
     
     for (int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;

        //creating an undirected graph
        g.addEdge(u,v,0);

        //printing graph
     }
        g.printAdjList();

    return 0;
}


// #include<iostream>
// #include<map>
// #include<vector>
// #include<unordered_map>
// #include<list>
// using namespace std;

// class graph{
//     public:

//     unordered_map<T,list<T>> adj;

//     void addEdge(T u, T v, bool direction){

//         // directionn =0 ->undirected
//         // directionn =1 ->directed

//         //create an edge from u to v
//         adj[u].push_back(v);
       
//         if(direction==0){
//         adj[v].push_back(u);
//         }

//     }
//         void printAdjList()
//         {
//             for(auto i:adj){
//                 cout<<i.first<<"->";
//                 for(auto j:i.second){
//                     cout<<j<<", ";
//                 }
//                 cout<<endl;
//             }
//         }   

// };


// T main(){

//     T n;
//     cout<<"enter the number of nodes"<<endl;
//     cin>>n;
    
//     T m;
//     cout<<"enter the number of edges"<<endl;
//     cin>>m;

//     graph g;
     
//      for (T i=0;i<n;i++){
//         T u,v;
//         cin>>u>>v;

//         //creating an undirected graph
//         g.addEdge(u,v,0);

//         //printing graph
//      }
//         g.printAdjList();

//     return 0;
// }