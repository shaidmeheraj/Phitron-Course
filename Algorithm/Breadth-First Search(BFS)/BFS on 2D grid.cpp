/* Bismillahir Rahmanir Raheem */
/* Shaid Meheraj */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N = 1e5+5;
bool visit[20][20];
char a[20][20];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}}; //matrix left, right, up, down
int dis[100][100];
int n, m;
bool valid(int i, int j)
{
    if(i<0 || i>=n || j<0 || j>=m) return false;
    return true;
}
void bfs(int si, int sj)
{
    queue<pair<int, int>>q;
    q.push({si, sj}); //source push in queue
    visit[si][sj] = true; //visit track
    dis[si][sj] = 0; //initially source 0
    while(!q.empty())
    {
        pair<int, int> f = q.front(); //front input in f
        q.pop();
        //cout << f.first << " " << f.second << endl;
        for(int i=0; i<4; i++)
        {
            int ci = f.first + d[i].first; //children = front first + vector first
            int cj = f.second + d[i].second;
            if(valid(ci, cj)==true && visit[ci][cj] == false)
            {
                q.push({ci, cj});
                visit[ci][cj] = true;
                dis[ci][cj] = dis[f.first][f.second] + 1; //child = source + 1;
            }
        }
    }
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
            cin >> a[i][j]; // input n x m matrics
        }
    }
    int si, sj; //matrix source
    cin >> si >> sj;
    memset(visit, false, sizeof(visit)); //all visit variable are initially false
    memset(dis, -1, sizeof(dis)); //all dis are not visited(-1)
    bfs(si, sj); //calling bfs
    cout << dis[0][3] << endl;
    return 0;
}

//Alhamdulillah...




