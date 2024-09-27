/* Bismillahir Rahmanir Raheem */
/* Shaid Meheraj */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N = 1005;
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;
char a[N][N];
bool visit[N][N];
vector<int> v;

bool valid(int i, int j)
{
    if(i>=0 && i<n && j>=0 && j<m && a[i][j] == '.' && visit[i][j]==false) return true;
    return false;
}
int bfs(int si, int sj)
{
    queue<pair<int, int>>q;
    q.push({si, sj});
    visit[si][sj] = true;
    int cnt = 0;

    while(!q.empty())
    {
        pair<int, int> f = q.front();
        q.pop();
        cnt++;

        for(int i=0; i<4; i++)
        {
            int ci = f.first + d[i].first;
            int cj = f.second + d[i].second;

            if(valid(ci, cj) == true)
            {
                q.push({ci, cj});
                visit[ci][cj] = true;
            }
        }
    }
    return cnt;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> a[i][j];
        }
    }
    memset(visit, false, sizeof(visit));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(a[i][j] == '.' && visit[i][j] == false)
            {
                int sz = bfs(i, j);
                v.push_back(sz);
            }
        }
    }

    sort(v.begin(), v.end());
    for(int x : v)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

//Alhamdulillah...
