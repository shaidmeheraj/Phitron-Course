/* Bismillahir Rahmanir Raheem */
/* Shaid Meheraj */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
void solve(void)
{
   int n, e;
   cin >> n >> e;
   vector<int> matrix[n]; //int a[n] array mean every index = int so vector<int>a[n] means every index = vector
   while(e--)
   {
       int a, b;
       cin >> a >> b;

       //for Undirected Graph
       matrix[a].push_back(b);
       matrix[b].push_back(a);
   }

   // for index 0 element
   for(int i=0; i<matrix[0].size(); i++)
   {
       cout << matrix[0][i] << " ";
   }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    while(t--)
    {
        solve();
    }

    return 0;
}

//Alhamdulillah...




