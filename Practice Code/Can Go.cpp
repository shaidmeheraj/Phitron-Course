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

bool valid(int i, int j)
{
    if(i>=0 && i<n && j>=0 && j<m && (a[i][j] == '.' || a[i][j]== 'B')) return true;
    return false;
}
bool bfs(int si, int sj)
{
    queue<pair<int, int>>q;
    q.push({si, sj});
    visit[si][sj] = true;

    while(!q.empty())
    {
        pair<int, int> f = q.front();
        q.pop();

        if(a[f.first][f.second] == 'B')
        {
            return true;
        }
        for(int i=0; i<4; i++)
        {
            int ci = f.first + d[i].first;
            int cj = f.second + d[i].second;

            if(valid(ci, cj) == true && visit[ci][cj] == false)
            {
                q.push({ci, cj});
                visit[ci][cj] = true;
            }
        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;

    pair<int, int> start;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> a[i][j];
            if(a[i][j] == 'A')
            {
                start = {i, j};
            }
        }
    }
    memset(visit, false, sizeof(visit));


    if(bfs(start.first, start.second))
    {
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;

    return 0;
}

//Alhamdulillah...




