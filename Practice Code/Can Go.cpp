/* Bismillahir Rahmanir Raheem */
/* Shaid Meheraj */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N = 1e5+5;
const ll INF = 1e18;
//vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
//char a[N][N];
//bool visit[N][N];
// vector<pair<int, int>> v[N];
// ll dis[N];
void dijkstra(int src, int n, vector<pair<int, ll>> v[], vector<ll> &dis)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>pq;
    
    dis.assign(n+1, INF);
    dis[src] = 0;
    pq.push({0, src});
    
    while(!pq.empty())
    {
        pair<ll, int> f = pq.top();
        pq.pop();
        ll cost = f.first;
        int node = f.second;
        
        if(cost > dis[node]) continue;
        
        for(pair<int, int> child : v[node])
        {
            int childN = child.first;
            int childC = child.second;
            if(dis[node] + childC < dis[childN])
            {
                dis[childN] = dis[node] + childC;
                pq.push({dis[childN], childN});
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

    vector<pair<int, ll>> v[n+1];
    while(e--)
    {
        int a, b;
        ll w;
        cin >> a >> b >> w;
        v[a].push_back({b, w});
    }
    int src;
    cin >> src;
    vector<ll> dis;
    dijkstra(src, n, v, dis);
    int t;
    cin >> t;
    while(t--)
    {
        int des, cost;
        cin >> des >> cost;
        if(dis[des] <= cost) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    


    return 0;
}

//Alhamdulillah...
