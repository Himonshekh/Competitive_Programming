#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
#define min_(x, y) (((x) < (y)) ? (x) : (y))

vector<int>Graph[101],Cost[101];
int cas=1;
int dfs(int u,int par,int root){
    if(root==u)return 0;
    if(Graph[u][0]==par){
        return dfs(Graph[u][1],u,root)+Cost[u][1];
    }else{
        return dfs(Graph[u][0],u,root)+Cost[u][0];
    }
}

void solve(int n){
    int c=999999;
    for(int i=1;i<=n;i++){
        c=min_(c,min_(dfs(Graph[i][0],i,i)+Cost[i][0],dfs(Graph[i][1],i,i)+Cost[i][1]));
    }
    printf("Case %d: %d\n",cas++,c);
}
void reset(int n){
    for(int i=1;i<=n;i++)Graph[i].clear(),Cost[i].clear();
}
int main()
{
    int t,u,v,w,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d%d%d",&u,&v,&w);
            Graph[u].push_back(v);
            Graph[v].push_back(u);
            Cost[u].push_back(0);
            Cost[v].push_back(w);
        }
        solve(n);
        if(t)reset(n);
    }
    return 0;
}
