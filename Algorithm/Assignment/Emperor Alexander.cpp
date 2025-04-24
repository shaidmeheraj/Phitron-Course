/* Bismillahir Rahmanir Raheem */
/* Shaid Meheraj */
#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int sz[N];
int par[N];

void initial_node(int n)
{
    for(int i=0;i<=n;i++)
    {
        sz[i]=1;
        par[i]=-1;
    }
}

int find(int nd)
{
    if(par[nd]==-1) return nd;
    int ld = find(par[nd]);
    par[nd]=ld;
    return ld;
}

void uniyon(int nd1,int nd2)
{
    int ld1=find(nd1);
    int ld2=find(nd2);
    if(sz[ld1] > sz[ld2])
    {
        par[ld2]=ld1;
        sz[ld1] +=sz[ld2];
    }
    else
    {
        par[ld1]=ld2;
        sz[ld2] +=sz[ld1];
    }
}
 
 class ed
 {
    public: 
     int u,v;
     long long w;
      ed(int u,int v,long long  w)
      {
        this->u=u;
        this->v=v;
        this->w=w;
      }
 };

 bool cmp(ed a , ed b)
 {
    return a.w < b.w;
 }

 vector<ed> vec;

int main()
{
    int n,e;
    cin >> n >> e;
    initial_node(n);
    while(e--)
    {
        int a,b;
        long long c;
        cin >> a >> b >> c;
        vec.push_back(ed(a,b,c));
    }

    sort(vec.begin(),vec.end(),cmp);

    int count = 0;
    long long totalcost=0;
    for(ed ch:vec)
    {
       int ld1=find(ch.u);
       int ld2=find(ch.v);

       if(ld1==ld2) 
       {
          count++;
          continue;
       }
       else
       {
          totalcost += ch.w;
          uniyon(ch.u,ch.v);
       }
    }
    int  parCount=0;
   for(int i=1;i<=n;i++)
   {
      if(par[i]== -1) parCount++;
   }

   if(parCount>1) cout << "Not Possible" << endl;
   else{
    cout << count <<" "<< totalcost << endl;
   }
    return 0;
}

//Alhamdulillah...
