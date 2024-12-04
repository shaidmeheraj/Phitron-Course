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
//vector<int> v;

bool valid(int i, int j)
{
    if(i>=0 && i<n && j>=0 && j<m && a[i][j] == '.' && visit[i][j]==false) return true;
    return false;
}
bool bfs(int si, int sj, int di, int dj)
{
    queue<pair<int, int>>q;
    q.push({si, sj});
    visit[si][sj] = true;
    //int cnt = 0;

    while(!q.empty())
    {
        pair<int, int> f = q.front();
        q.pop();
        //cnt++;
        if(f.first == di && f.second == dj)
        {
            return true;
        }
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
    return false;
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
    int si, sj, di, dj;
    cin >> si >> sj >> di >> dj;
    memset(visit, false, sizeof(visit));
    
    if(bfs(si, sj, di, dj))
    {
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }

    return 0;
}

//Alhamdulillah...
