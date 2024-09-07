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
     vector<pair<int, int>>v;
     while(e--)
     {
         int a, b;
         cin >> a >> b;
         v.push_back(make_pair(a, b)); //v.push_back({a, b}); also correct
     }

     // for each loop
     for(pair<int, int> x : v) //pair<int, int> == auto
     {
         cout << x.first << " " << x.second << endl;
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




