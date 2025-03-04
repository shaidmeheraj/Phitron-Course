#include<bits/stdtr1c++.h>
using namespace std;
const int N = 1e5+5;
int par[N];
void dsu_initialize(int n)
{
    for(int i=0; i<n; i++)
    {
        par[i] = -1;
    }
    par[1] = 3;
    par[2] = 1;
}
int find(int node)
{
    if(par[node] == -1) return node;
    return find(par[node]);
}
int main()
{
    dsu_initialize(4); // 0 1 2 3 
    cout << find(0) << endl;
    cout << find(1) << endl;
    cout << find(2) << endl;
    cout << find(3) << endl;


    return 0;
}