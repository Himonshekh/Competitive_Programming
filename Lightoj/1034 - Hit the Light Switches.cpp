// #include <bits/stdc++.h>
#include <cstring>
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;
vector<int>Graph[10001],R_Graph[10001];
stack<int>St;
int vis[10001],degree[10001],c;
void dfs(int u){
    int sz=Graph[u].size();
    vis[u]=1;
    for(int i=0;i<sz;i++){
        if(!vis[Graph[u][i]]){
            dfs(Graph[u][i]);
        }
    }
    St.push(u);
}
void dfs2(int u,int root,int id){
    int sz=R_Graph[u].size();
    vis[u]=id;

    for(int i=0;i<sz;i++){
        if(!vis[R_Graph[u][i]]){
            dfs2(R_Graph[u][i],root,id);
        }else if(vis[ R_Graph[u][i] ]!=id){
            degree[ id ]++;
            // New_Graph[ vis[ R_Graph[u][i] ] ].push_back(id);
        }
    }
}
void solve(int n){
    c=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    memset(vis,0,sizeof(vis));
    int id=0,x;
    while(!St.empty()){
        x=St.top();St.pop();
        if(vis[x])continue;
        id++;
        dfs2(x,x,id);
    }
    for(int i=1;i<=id;i++)if(degree[i]==0)c++;
}
void reset(int n){
    for(int i=0;i<=n;i++){
        R_Graph[i].clear();
        Graph[i].clear();
        degree[i]=0;
    }
    memset(vis,0,sizeof(vis));
}
int main()
{
    int t,cas=1,n,m,u,v;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++){
            scanf("%d%d",&u,&v);
            Graph[u].push_back(v);
            R_Graph[v].push_back(u);
        }
        solve(n);
        printf("Case %d: %d\n",cas++,c);
        if(t)reset(n);
    }
    return 0;
}
