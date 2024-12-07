/* Bismillahir Rahmanir Raheem */
/* Shaid Meheraj */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N = 1e5+5;
const int INF = 1e9;
//vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
//char a[N][N];
//bool visit[N][N];
vector<pair<int, int>> v[N];
int dis[N];
// class cmp
// {
//     public :
//     bool operator()(pair<int, int>a, pair<int, int> b)
//     {
//         return a.second > b.second;
//     }
// };
void dijkstra(int src, int n)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>pq;
    
    for(int i=1; i<=n; i++)
    {
        dis[i] = INF;
    }
    dis[src] = 0;
    pq.push({src, 0});
    
    while(!pq.empty())
    {
        pair<int, int> f = pq.top();
        pq.pop();
        int node = f.first;
        int cost = f.second;
        
        if(cost > dis[node]) continue;
        
        for(pair<int, int> child : v[node])
        {
            int childN = child.first;
            int childC = child.second;
            if(cost + childC < dis[childN])
            {
                dis[childN] = cost + childC;
                pq.push({childN, dis[childN]});
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
        int a, b, w;
        cin >> a >> b >> w;
        v[a].push_back({b, w});
    }
    int src;
    cin >> src;
    dijkstra(src, n);
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
