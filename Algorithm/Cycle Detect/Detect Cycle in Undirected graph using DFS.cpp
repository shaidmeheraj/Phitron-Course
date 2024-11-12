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
void dfs(int parent)
{
    vis[parent] = true;
    //cout << parent << endl;
    for(int child : adj[parent])
    {
        if(vis[child]== true && child != parentArray[parent] )
        {
            cycle = true;
        }
        if(!vis[child])
        {
            parentArray[child] = parent;
            dfs(child);
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



