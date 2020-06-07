#include<iostream>
#include <vector> 
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;

vector<int>Graph[30001],Cost[30001];
int Mx;
int dfs(int u,int par=-1){
    int sz=Graph[u].size(),mx=0,ret;
    for (int i = 0; i < sz; i++){
        int v=Graph[u][i];
        if(v==par)continue;
        ret=dfs(v,u)+Cost[u][i];
        Mx=max(Mx,(mx+ret));
        mx=max(mx,ret);
    }
    return mx;
}
void solve(int u){
    u=dfs(u);
}
void reset(int n){
    Mx=0;
    for(int i=0;i<n;i++)Graph[i].clear(),Cost[i].clear();
}
int main()
{
    int u,v,t,n,w,cas=1;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<n;i++){
            scanf("%d%d%d",&u,&v,&w);
            Graph[u].push_back(v);
            Graph[v].push_back(u);
            Cost[u].push_back(w);
            Cost[v].push_back(w);
        }
        solve(u);
        printf("Case %d: %d\n", cas++,Mx);
        if(t)reset(n);
    }

    return 0;
}
