#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int t,cas=1,u,v,w,n,lim;

struct info{
    int U,V,W;
    info(int U_,int V_,int W_){
        U=U_;
        V=V_;
        W=W_;
    }
};
vector<info>Graph;
int par[101];
bool cmp_inc(info lf,info rt){
    if(lf.W<rt.W)return true;
    return false;
}

bool cmp_dec(info lf,info rt){
    if(lf.W>rt.W)return true;
    return false;
}
void make_par(){
    for(int i=0;i<=n;i++)par[i]=i;
}
int Find(int x){
    if(par[x]==x){
        return x;
    }else return par[x]=Find(par[x]);
}
int kruskal(){
    make_par();
    int cost=0;
    for(int i=0;i<lim;i++){
        u=Graph[i].U;
        v=Graph[i].V;
        w=Graph[i].W;
        u=Find(u);
        v=Find(v);
        if(u!=v){
            par[u]=v;
            cost+=w;
        }
    }
    return cost;
}
void solve(){
    int c1,c2;
    lim=Graph.size();
    sort(Graph.begin(), Graph.end(),cmp_inc);
    c1=kruskal();
    sort(Graph.begin(), Graph.end(),cmp_dec);
    c2=kruskal();
    c1=c1+c2;
    if(c1%2==0){
        printf("Case %d: %d\n",cas++,c1/2);
    }else printf("Case %d: %d/2\n",cas++,c1);
}
void reset(){
}
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        while(true){
            scanf("%d%d%d",&u,&v,&w);
            if(u==0&&v==0&&w==0)break;
            Graph.push_back(info(u,v,w));
        }
        solve();
        if(t){
            Graph.clear();
        }
    }
    return 0;
}
