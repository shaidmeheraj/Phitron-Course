/* Bismillahir Rahmanir Raheem */
/* Shaid Meheraj */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
vector<int> v[1005]; //globally vector created
bool visited[1005]; //visited bool function globally
void bfs(int src)
{
     queue<int>q; //queue for push which value are already visited
     q.push(src);
     visited[src]=true; //when a node visited then set true, otherwise create infinity loop
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
     bfs(src); // calling bfs

    return 0;
}

//Alhamdulillah...





