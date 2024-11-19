/* Bismillahir Rahmanir Raheem */
/* Shaid Meheraj */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N = 1e5+5;
bool vis[N];
bool pathVisit[N];
vector<int> adj[N];
bool cycle;
void dfs(int parent)
{
    vis[parent] = true;
    pathVisit[parent] = true;
    //cout << parent << endl;
    for(int child : adj[parent])
    {
        if(pathVisit[child]) //pathvisit jodi theke jay taile cycle ache
        {
            cycle = true; 
        }
        if(!vis[child])
        {
            dfs(child);
        }
        // backtracking ekhan theke shuru hobe
    }
    pathVisit[parent] = false;
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
    }
    memset(vis, false, sizeof(vis));
    memset(pathVisit, false, sizeof(pathVisit));
    cycle = false;
    for(int i=0; i<n; i++)
    {
        if(!vis[i])
        {
            dfs(i);
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



