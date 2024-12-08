/* Bismillahir Rahmanir Raheem */
/* Shaid Meheraj */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
class Edge
{
    public:
    int u, v;
    ll c;
    Edge(int u, int v, ll c)
    {
        this -> u = u;
        this -> v = v;
        this -> c = c;
    }
};
const int N = 1e3+5;
const long long INF = 1e18;
ll dis[N];
vector<Edge> EdgeList;
bool bellmanFord(int n, int src)
{
    for(int i=1; i<=n; i++)
    {
        dis[i] = INF;
    }
    dis[src] = 0;
    for(int i=1; i<=n-1; i++)
    {
        for(Edge ed : EdgeList)
        {
            int u, v;
            ll c;
            u = ed.u;
            v = ed.v;
            c = ed.c;
            if(dis[u] < INF && dis[u] + c < dis[v])
            {
                dis[v] = dis[u] + c;
            }
        }
    }
    //bool cycle = false;
    for(Edge ed : EdgeList)
    {
        int u, v;
        ll c;
        u = ed.u;
        v = ed.v;
        c = ed.c;
        if(dis[u] < INF && dis[u] + c < dis[v])
        {
            return true;
        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, e;
    cin >> n >> e;
   // vector<Edge> EdgeList;
    while(e--)
    {
        int u, v, c;
        cin >> u >> v >> c;
        EdgeList.push_back(Edge(u, v, c));
    }
    
    int src;
    cin >> src;

    if(bellmanFord(n, src)){
        cout << "Negative Cycle Detected"<< endl;
        return 0;
    }
    //dis[src] = 0;

    int t;
    cin >> t;
    while(t--)
    {
        int des;
        cin >> des;
        if(dis[des] != INF) cout << dis[des] << endl;
        else cout << "Not Possible" << endl;
    }
    
    return 0;
}

//Alhamdulillah...
