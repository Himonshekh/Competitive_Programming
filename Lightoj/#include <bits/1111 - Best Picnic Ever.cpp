
// #include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
vector<int>Graph[1001];
int A[101],vis[1001],people[1001],c,n,m,k;
void dfs(int u){
    vis[u]=1;
    people[u]++;
    int sz=Graph[u].size();
    for(int i=0;i<sz;i++){
        if(!vis[Graph[u][i]]){
            dfs(Graph[u][i]);
        }
    }
}
void solve(){
    for(int i=0;i<k;i++){
        memset(vis,0,sizeof(vis));
        dfs(A[i]);
    }
    c=0;
    for(int i=1;i<=n;i++){
        if(people[i]==k)c++;
    }
}
void reset(){
    for(int i=0;i<=n;i++)Graph[i].clear();
    memset(people,0,sizeof(people));
}
int main()
{
    int t,cas=1,u,v;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&k,&n,&m);
        for(int i=0;i<k;i++)scanf("%d",&A[i]);
        for(int i=0;i<m;i++){
            scanf("%d%d",&u,&v);
            Graph[u].push_back(v);
        }
        solve();
        printf("Case %d: %d\n",cas++,c);
        if(t)reset();
    }
    return 0;
}
