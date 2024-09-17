/* Bismillahir Rahmanir Raheem */
/* Shaid Meheraj */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N = 1e5+5;
bool visited[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, e;
    cin >> n >> e;
    vector<int> v[n];
    while(e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int q;
    cin >> q;
    while(q--)
    {
        int src;
        cin >> src;

        if(v[src].size() > 0)
        {
            vector<int>v1;
            for(int i=v[src].size()-1; i>=0; i--)
           {
            v1.push_back(v[src][i]);
            }
            sort(v1.begin(), v1.end(), greater<int>());
            for(int x : v1)
            {
            cout << x << " ";
            }
           cout << endl;

        }
        else cout << -1 << endl;
    }
    return 0;
}

//Alhamdulillah...





