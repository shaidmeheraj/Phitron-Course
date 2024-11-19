#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
const int INF = 1e9;
vector<pair<int, int>> v[N];
int dis[N];
void dijkstra(int src)
{
    queue<pair<int, int>> q;
    q.push({src, 0});
    dis[src] = 0;
    while(!q.empty())
    {
        pair<int, int> parent = q.front();
        q.pop();
        int node = parent.first;
        int cost = parent.second;
        // child gula pair hiseve ber hobe
        for(pair<int, int> child : v[node])
        {
            int childNode = child.first;
            int childCost = child.second;
            if(cost + childCost < dis[childNode]) //cost tar nijer ta
            {
                dis[childNode] = cost + childCost;
                q.push({childNode, dis[childNode]});
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while(e--)
    {
        int a, b, c; //c for cost
        cin >> a >> b >> c;
        v[a].push_back({b,c});
        v[b].push_back({a, c});
    }
    for(int i=0; i<n; i++)
    {
        dis[i] = INT_MAX;
    }
    //memset(dis, INF, sizeof(dis));
    dijkstra(0);
    for(int i=0; i<n; i++)
    {
        cout << i << " -> " << dis[i] << endl;
    }
    return 0;
}