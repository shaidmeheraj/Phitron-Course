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
   int matrix[n][n];
   memset(matrix, 0, sizeof(matrix)); // for all value, initially set at 0
   while(e--)
   {
       int a, b;
       cin >> a >> b;

       //For undirected Graph
       matrix[a][b] = 1;
       matrix[b][a] = 1;
   }
   for(int i=0; i<n; i++)
   {
       for(int j=0; j<n; j++)
       {
           cout << matrix[i][j] << " ";
       }
       cout << endl;
   }

   // check connected or not
   if(matrix[3][4] == 1) cout << "Connected" << endl;
   else cout << "Not Connected" << endl;
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




