#include<bits/stdc++.h>
using namespace std;
vector<int> v[1005];
bool visit[1005];
void shortest_path(int s, int d)
{
    queue<pair<int, int>>q;
    q.push({s, 0});
    visit[s] = true;
    bool get_des = false;
    while(!q.empty())
    {
        pair<int,int> p = q.front();
        q.pop();
        int node = p.first;
        int level = p.second;
        if(node == d)
        {
            cout << level << endl;
            get_des = true;
            return;
        }
        for(auto x : v[node])
        {
            if(visit[x] == false)
            {
                q.push({x, level+1});
                visit[x] = true;
            }
        }
    }
    if(get_des == false) cout << -1 << endl;
}
int main()
{
    int n, e;
    cin >> n >> e;
    while(e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int q;
    cin >> q;
    while(q--)
    {
        int s, d;
        cin >> s >> d;
        memset(visit, false, sizeof(visit));
        shortest_path(s, d);
    }
}
