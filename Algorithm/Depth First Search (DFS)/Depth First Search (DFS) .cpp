#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int> v[N];
bool visit[N];
void dfs(int src)
{
    cout << src << endl;
    visit[src] = true;
    for(int child : v[src])
    {
        if(visit[child] == false)
        {
            dfs(child);
        }
    }
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
    int src;
    cin >> src;
    dfs(src);
}

