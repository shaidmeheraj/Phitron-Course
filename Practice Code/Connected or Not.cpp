/* Bismillahir Rahmanir Raheem */
/* Shaid Meheraj */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N = 1e3;
vector <int> v[N];
bool isConnected(int s, int d)
{
    if(s==d) return true;
    bool flag = false;
    for(int i=0; i<v[s].size(); i++)
    {
        if(v[s][i] == d) flag = true;
    }
    return flag;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, e;
    cin >> n >> e;

    while(e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    int q;
    cin >> q;
    while(q--)
    {
        int c, d;
        cin >> c >> d;

        if(isConnected(c, d) == true) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}

//Alhamdulillah...
