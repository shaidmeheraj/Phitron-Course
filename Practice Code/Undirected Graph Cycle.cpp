//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    private:
    bool dfs(int node, int parent, vector<int>& vis, vector<vector<int>>& adj)
    {
        vis[node] =1;
        for(auto child : adj[node])
        {
            if(!vis[child])
            {
                if(dfs(child, node, vis, adj)) return true;
            }
            else if(child != parent) return true;
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        int v=adj.size();
        vector<int>vis(v,0);
        for(int i=0; i<v; i++)
        {
            if(!vis[i])
            {
                if(dfs(i, -1, vis, adj)) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends