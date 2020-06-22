#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int par[51],c;
struct info{
    int u,v,w;
    info(int u_,int v_,int w_){
        u=u_;
        v=v_;
        w=w_;
    }
};
vector<info>Graph;
void make_par(){
    for(int i=0;i<=50;i++)par[i]=i;
}
bool cmp(info lf,info rt){
    return lf.w<rt.w?true:false;
}
int Find(int x){
    return par[x]==x?x:par[x]=Find(par[x]);
}
void solve(int n){
    make_par();
    sort(Graph.begin(), Graph.end(),cmp);
    int lim=Graph.size();
    for(int i=0;i<lim;i++){
        int u=Graph[i].u,v=Graph[i].v,w=Graph[i].w;
        // cout<<w<<" = "<<u<<" "<<v<<endl;
        u=Find(u);
        v=Find(v);
        // cout<<u<<" ? "<<v<<endl;
        if(u!=v){
            par[u]=v;
        }else{
            c+=w;
        }
    }
}
bool valid(int n){
    int cnt=0,u;
    set<int>S;
    for(int i=1;i<=n;i++){
        u=Find(i);
        S.insert(u);
    }
    if(S.size()==1)return true;
    else return false;
}
void reset(){
    Graph.clear();
}
int main()
{
    int t,cas=1,n,d;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        c=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                scanf("%d",&d);
                if(i==j){
                    c+=d;
                }else if(d){
                    Graph.push_back(info(i,j,d));
                }
            }
        }
        solve(n);
        if(valid(n))printf("Case %d: %d\n",cas++,c);
        else printf("Case %d: -1\n",cas++);
        if(t)reset();
    }
    return 0;
}
