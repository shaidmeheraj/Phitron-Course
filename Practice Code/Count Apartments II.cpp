/* Bismillahir Rahmanir Raheem */
/* Shaid Meheraj */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N = 1e3;
char a[N][N];
bool visit[N][N];
int n, m;
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
vector<pair<int, int>> p;
vector<int> v;

bool valid(int i, int j)
{
    if(i<0 || i>=n || j<0 || j>=m) return false;
    else return true;
}
int bfs(int si, int sj)
{
    queue<pair<int, int>>q;
    q.push({si, sj});
    int cnt = 1;
    visit[si][sj] = true;


    while(!q.empty())
    {
        pair<int, int> f = q.front();
        q.pop();

        for(int i=0; i<4; i++)
        {
            int ci = f.first + d[i].first;
            int cj = f.second + d[i].second;

            if(valid(ci, cj) && visit[ci][cj])
            {
                q.push({ci, cj});
                cnt++;
                visit[ci][cj] = false;
            }
        }
    }
    if(cnt == 1) return cnt;
    else return cnt-1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    memset(visit, false, sizeof(visit));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            char c;
            cin >> c;
            a[i][j] = c;

            if(a[i][j] == '.')
            {
                p.push_back({i, j});
                visit[i][j] = true;
            }
        }
    }

    for(int i=0; i<p.size(); i++)
    {
        int first= p[i].first;
        int second = p[i].second;
        if(visit[first][second] == true)
        {
            int c = bfs(first, second);
            v.push_back(c);
        }
    }
    if(v.empty())
    {
        cout << 0 << endl;
        return 0;
    }
    sort(v.begin(), v.end());
    for(int x : v)
    {
        cout << x << " ";
    }

    return 0;
}

//Alhamdulillah...
