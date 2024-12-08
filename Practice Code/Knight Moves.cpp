/* Bismillahir Rahmanir Raheem */
/* Shaid Meheraj */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N = 1005;
vector<pair<int, int>> d = { {2,1},{-2,-1},{-2,1},{2,-1},{1,2},{-1,-2},{-1,2},{1,-2}};
int n, m;
int level[110][110];
bool vis[110][110];
//vector<int> v;

bool valid(int i, int j)
{
    if(i<0 || i>=n || j<0 || j>=m) return false;
    return true;
}
void bfs(int si, int sj)
{
    queue<pair<int, int>>q;
    q.push({si, sj});
    level[si][sj] = 0;
    vis[si][sj] = true;
    //int cnt = 0;

    while(!q.empty())
    {
        pair<int, int> f = q.front();
        q.pop();
       // cnt++;
        int fi = f.first;
        int fj = f.second;
        for(auto child : d)
        {
            int ci = fi + child.first;
            int cj = fj + child.second;
            if(valid(ci , cj) && vis[ci][cj] == false)
            {
                vis[ci][cj] = true;
                level[ci][cj] = level[fi][fj] + 1;
                q.push({ci, cj});
            }
        }
    }
    //return cnt;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b, x, y;
    int t;
    cin >> t;
    while(t--)
    {
        memset(level, -1, sizeof(level));
        memset(vis, false, sizeof(vis));

        cin >> n >> m >> a >> b >> x >> y;
        bfs(a, b);

        if(valid(x, y) && vis[x][y]) cout << level[x][y] << endl;
        else cout << -1 << endl;
    }

    return 0;
}

//Alhamdulillah...
