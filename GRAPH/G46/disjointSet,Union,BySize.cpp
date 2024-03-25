// #include <bits/stdc++.h>
// using namespace std;

// class DisjointSet {
//     vector<int> rank, parent, size; 
// public: 
//     DisjointSet(int n) {
//         rank.resize(n+1, 0); 
//         parent.resize(n+1);
//         size.resize(n+1); 
//         for(int i = 0;i<=n;i++) {
//             parent[i] = i; 
//             size[i] = 1; 
//         }
//     }

//     int findUPar(int node) {
//         if(node == parent[node])
//             return node; 
//         return parent[node] = findUPar(parent[node]); 
//     }

//     void unionByRank(int u, int v) {
//         int ulp_u = findUPar(u); 
//         int ulp_v = findUPar(v); 
//         if(ulp_u == ulp_v) return; 
//         if(rank[ulp_u] < rank[ulp_v]) {
//             parent[ulp_u] = ulp_v; 
//         }
//         else if(rank[ulp_v] < rank[ulp_u]) {
//             parent[ulp_v] = ulp_u; 
//         }
//         else {
//             parent[ulp_v] = ulp_u; 
//             rank[ulp_u]++; 
//         }
//     }

//     void unionBySize(int u, int v) {
//         int ulp_u = findUPar(u); 
//         int ulp_v = findUPar(v); 
//         if(ulp_u == ulp_v) return; 
//         if(size[ulp_u] < size[ulp_v]) {
//             parent[ulp_u] = ulp_v; 
//             size[ulp_v] += size[ulp_u]; 
//         }
//         else {
//             parent[ulp_v] = ulp_u;
//             size[ulp_u] += size[ulp_v]; 
//         }
//     }
// }; 
// int main() {
//     DisjointSet ds(7);
//     ds.unionBySize(1, 2); 
//     ds.unionBySize(2, 3); 
//     ds.unionBySize(4, 5); 
//     ds.unionBySize(6, 7); 
//     ds.unionBySize(5, 6); 
//     // if 3 and 7 same or not 
//     if(ds.findUPar(3) == ds.findUPar(7)) {
//         cout << "Same\n"; 
//     }
//     else cout << "Not same\n"; 

//     ds.unionBySize(3, 7); 

//     if(ds.findUPar(3) == ds.findUPar(7)) {
//         cout << "Same\n"; 
//     }
//     else cout << "Not same\n"; 
// 	return 0;
// }













// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// const int MOD = 1e9 + 7;

// int f(vector<vector<long long>>& grid, vector<vector<long long>>& do, int n, int m, int i, int j) {
//     if (i < 0 || i >= n || j < 0 || j >= m) {
//         return 0;
//     }

//     if (i == 0 && j == 0) {
//         return grid[i][j];
//     }

//     if (do[i][j] != -1) {
//         return do[i][j];
//     }

//     long long left = f(grid, do, n, m, i, j - 1);
//     long long up = f(grid, do, n, m, i - 1, j);

//     do[i][j] = max(left, up) + grid[i][j];
//     do[i][j] %= MOD;

//     return do[i][j];
// }

// int main() {
//     int n, m;
//     cin >> n >> m;
//     vector<vector<long long>> grid(n, vector<long long>(m));
    
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             cin >> grid[i][j];
//         }
//     }
//     vector<vector<long long>> do(n, vector<long long>(m, -1));

//     long long result = f(grid, do, n, m, n - 1, m - 1);

//     cout << result << endl;

//     return 0;
// }

#include <bits/stdc++.h>
// #include <vector>

using namespace std;

class UnionFind {
private:
    vector<int> parent, size;

public:
    UnionFind(int n) {
        parent.resize(n);
        size.assign(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    void unionBySize(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }

    int getSize(int x) {
        return size[find(x)];
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    UnionFind dsu(n);
    int components = n;
    int largestComponent = 1;

    vector<int> results;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        if (dsu.find(a - 1) != dsu.find(b - 1)) {
            components--;

            int sizeA = dsu.getSize(a - 1);
            int sizeB = dsu.getSize(b - 1);

            dsu.unionBySize(a - 1, b - 1);
            int newSize = dsu.getSize(a - 1);

            largestComponent = max(largestComponent, newSize);

            results.push_back(components);
            results.push_back(largestComponent);
        } else {
            results.push_back(components);
            results.push_back(largestComponent);
        }
    }

    for (int i = 0; i < results.size(); i += 2) {
        cout << results[i] << " " << results[i + 1] << endl;
    }

    return 0;
}

