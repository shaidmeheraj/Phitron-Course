/* Bismillahir Rahmanir Raheem */
/* Shaid Meheraj */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N = 1e5+5;
bool vis[N];
int parentArray[N];
vector<int> adj[N];
bool cycle;
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    vis[s] = true;
    while(!q.empty())
    {
        int parent = q.front();
        cout << parent << endl;
        q.pop();
        for(int child : adj[parent])
        {
            if(vis[child]== true && parentArray[parent]!= child)
            {
                cycle = true;
            }
            if(!vis[child])
            {
                vis[child] = true;
                parentArray[child] = parent;
                q.push(child);
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, e;
    cin >> n >> e;
    while(e--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    memset(parentArray, -1, sizeof(parentArray));
    cycle = false;
    for(int i=0; i<n; i++)
    {
        if(!vis)
        {
            bfs(i);
        }
    }
    if(cycle)
    {
        cout << "Cycle found" << endl;
    }
    else cout << "Cycle not found" << endl;
    return 0;
}

//Alhamdulillah...



