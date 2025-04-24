/* Bismillahir Rahmanir Raheem */
/* Shaid Meheraj */
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
char ar[N][N];
bool vis[N][N];
int level[N][N];
vector<pair<int,int>> d={{0,1},{0,-1},{-1,0},{1,0}};
map<pair<int,int>,pair<int,int>> mp;


int row ,col;
int si,sj,di,dj;
bool flag=false;

bool valid(int i,int j)
{
    if(i<0 || i>=row || j<0 || j>=col || ar[i][j]=='#') return false;
    else return true;
}


void bfs(int si,int sj)
{
    queue<pair<int,int>> q;
    q.push({si,sj});
    vis[si][sj]=true;
    level[si][sj]=0;
    while(!q.empty())
    {
        pair<int,int> p=q.front();
        int pi=p.first;
        int pj=p.second;
        q.pop();
        for(int i=0;i<4;i++)
        {
           int ci=pi + d[i].first;
           int cj=pj + d[i].second;
          if(ci==di && cj==dj) flag=true;
            if(valid(ci,cj) && !vis[ci][cj] )
           {
                vis[ci][cj]=true;
                level[ci][cj]= level[pi][pj] + 1;
                mp[{ci,cj}]={pi,pj};
                q.push({ci,cj});        
           }
        }
        
    }
}
int main()
{
    cin >> row >> col;
    memset(vis,false,sizeof(vis));
    memset(level,-1,sizeof(level));
    
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
          cin >> ar[i][j];

            if(ar[i][j]=='R')
            {
              si=i;
              sj=j;
            } 
            if(ar[i][j]=='D')
            {
              di=i;
              dj=j;
            }    
        }
    }
 
    bfs(si,sj);
   if(flag)
   {
        int  u = mp[{di,dj}].first;
        int  v = mp[{di,dj}].second;
        while(u != si || v != sj)
        {
          ar[u][v]='X';
          int  tempU = mp[{u,v}].first;
          int tempV = mp[{u,v}].second;
          u=tempU;
          v=tempV;
        }
   } 
      for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
          cout << ar[i][j];
   
        }
        cout << endl;
    }
    
}

//Alhamdulillah...