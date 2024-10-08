//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
bool visit[10000] = {false};
// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {

        vector<int> v;
        queue<int>q;
        q.push(V);
        v.push_back(0);
        visit[V] = true;
        while(!q.empty())
        {
            int f = q.front();
            q.pop();
            for(auto x : adj[f])
            {
                if(adj[x] == false)
                {
                    q.push(x);
                    visit[x] = true;
                    v.push_back(x);

                }
            }
        }
        return v;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
