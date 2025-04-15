/* Bismillahir Rahmanir Raheem */
/* Shaid Meheraj */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N = 1e5+5;
int sz[N];
int par[N];
void initial(int n)
{
    for(int i=0; i<=n; i++)
    {
        sz[i]=1;
        par[i]=-1;
    }
}
int find(int i)
{
    if(par[i] == -1) return i;
    int head = find(par[i]);
    par[i] = head;
    return head;
}
void unionKrbo(int i, int j)
{
    int id1=find(i);
    int id2=find(j);
    if(sz[id1] > sz[id2])
    {
        par[id2] = id1;
        sz[id1]++;
    }
    else{
        par[id1]=id2;
        sz[id2]++;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, e;
    cin >> n >> e;
    initial(n);
    int ans=0;
    while(e--)
    {
        int a, b;
        cin >> a >> b;
        int head1=find(a);
        int head2=find(b);
        if(head1 == head2) ans++;
        else {
            unionKrbo(a, b);
        }
    }
    cout << ans << endl;
    return 0;
}

//Alhamdulillah...



