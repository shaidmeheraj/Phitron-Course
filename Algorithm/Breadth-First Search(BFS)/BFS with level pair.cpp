/* Bismillahir Rahmanir Raheem */
/* Shaid Meheraj */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
vector<int> v[1005]; //globally vector created
bool visited[1005]; //visited bool function globally
void bfs(int src, int des)
{
     queue<pair<int, int>>q; //queue for push which value are already visited
     q.push({src, 0});
     visited[src]=true; //when a node visited then set true, otherwise create infinity loop
     bool get_des = false;
     while(!q.empty())
     {
         pair<int, int> p = q.front();
         q.pop();
         int parent = p.first;
         int level = p.second;
         if(parent == des)
         {
             cout << level << endl;
             get_des = true;
         }
         for(int child : v[parent]) //for each loop
         {
             if(visited[child] == false) //remember , if visited false then work. otherwise infinity loop occers
             {
                 q.push({child, parent+1});
                 visited[child]=true; //again, visited true;
         }
     }
     if(get_des == false)
     {
         cout << -1 << endl;
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
     bfs(src, 6); // calling bfs for 0 to 6 level

    return 0;
}

//Alhamdulillah...







