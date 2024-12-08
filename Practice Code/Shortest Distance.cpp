/* Bismillahir Rahmanir Raheem */
/* Shaid Meheraj */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N = 1e5+5;
const ll INF = 1e15;
void dijkstra(int shuru, int n, vector<vector<pair<int, ll>>>& v, vector<ll>& dis)
{
    dis.assign(n+1, INF);
    dis[shuru] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    pq.push({0, shuru});

    while(!pq.empty())
    {
        pair<ll, int> top = pq.top();
        ll d = top.first;
        int node = top.second;

        pq.pop();

        if(d > dis[node]) continue;

        for(auto child : v[node]) {
        int childN = child.first;
        ll childC = child.second;

       if (dis[node] + childC < dis[childN]) {
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
    ll n, e;
    cin >> n >> e;
    vector<vector<pair<int, ll>>>v(n+1);
    // for(int i=1; i<=n; i++)
    // {
    //     dis[i][i] = 0;
    // }
    while(e--)
    {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        //if(a==b) continue;
        v[a].push_back({b, c});
    }
    
    int q;
    cin >> q;
    
    vector<pair<int, int>> quer(q);
    for(int i=0; i<q; i++)
    {
        cin >> quer[i].first >> quer[i].second;
    }

    vector<vector<ll>> dis(n+1, vector<ll> (n+1, -1));


    for(int i=1; i<=n; i++)
    {
        vector<ll> d;
        dijkstra(i, n, v, d);
        for(int j=1; j<=n; j++)
        {
            if(d[j] != INF)
            {
                dis[i][j] = d[j];
            }
        }
    }

    for (auto ans : quer) {
    int x = ans.first;
    int y = ans.second;

    cout << dis[x][y] << endl;
    }

    return 0;
}

//Alhamdulillah...



