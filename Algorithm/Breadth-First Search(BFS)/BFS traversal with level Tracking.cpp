/* Bismillahir Rahmanir Raheem */
/* Shaid Meheraj */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
vector<int> v[1005]; //globally vector created
bool visited[1005]; //visited bool function globally
int level[1005];
void bfs(int src)
{
     queue<int>q; //queue for push which value are already visited
     q.push(src);
     visited[src]=true; //when a node visited then set true, otherwise create infinity loop
     level[src] = 0; //i know, src is 0 index so level zero
     while(!q.empty())
     {
         int parent = q.front();
         q.pop();
         cout << parent << endl;
         for(int child : v[parent]) //for each loop
         {
             if(visited[child] == false) //remember , if visited false then work. otherwise infinity loop occers
             {
                 q.push(child);
                 visited[child]=true; //again, visited true;
                 level[child] = level[parent] + 1; // child is more than 1 by parents
             }
         }
     }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, e;
     cin >> n >> e;
     while(e--)
     {
         int a, b; // input edge
         cin >> a >> b;
         v[a].push_back(b); // list edge connected
         v[b].push_back(a); //both side because undirectional
     }
     int src; // which source start, suppose 0
     cin >> src;
     memset(visited, false, sizeof(visited)); // all visited index are initially zero before calling bfs
     memset(level, -1, sizeof(level));
     bfs(src); // calling bfs

     for(int i=0; i<n; i++)
     {
         cout << i << " " << level[i] << endl;
     }

    return 0;
}

//Alhamdulillah...






