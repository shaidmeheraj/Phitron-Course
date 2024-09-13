#include<bits/stdc++.h>
using namespace std;
vector<int> v[1000];
bool visit[1000];

bool dfs(int src)
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
    memset(visit, false, sizeof(visit));
    int c=0;
    for(int i=0; i<n; i++)
    {
        if(!visit[i]){
            dfs(i);
            c++;
        }
    }
    cout << "component : " << c << endl;
    return 0;
}
