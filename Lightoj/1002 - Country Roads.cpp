#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define inf 1e8
map<pii,int>Mp;
int t,cas=1,lim,n,m,u,v,w,a,b,s,mx,c;
vector<int>Graph[501];
int MX[501];
struct info{
    int id,cost;
    info(int id_,int cost_){
        id=id_;
        cost=cost_;
    }
};
struct compare{
    bool operator()(const info& lf, const info& rt){
      return lf.cost > rt.cost;
    }
};
void fun(){
    priority_queue<info,vector<info>,compare>PQ;
    PQ.push(info(s,0));
    MX[s]=0;
    while(!PQ.empty()){
        u=PQ.top().id;
        c=PQ.top().cost;
        PQ.pop();
        lim=Graph[u].size();
        mx=MX[u];
        for(int i=0;i<lim;i++){
            v=Graph[u][i];
            if(u<v){
                a=u;b=v;
            }else {
                a=v;b=u;
            }
            w=Mp[make_pair(a,b)];
            w=max(mx,w);
            if(MX[v]>w){
                MX[v]=w;
                PQ.push(info(v,w));
            }
        }
    }
}
void solve(){
    fun();
    printf("Case %d:\n",cas++);
    for(int i=1;i<=n;i++){
        if(MX[i]==inf)printf("Impossible\n");
        else printf("%d\n",MX[i]);
    }
}
void reset(){
    for(int i=0;i<=n;i++)Graph[i].clear(),MX[i]=inf;
    Mp.clear();
}
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        reset();
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&u,&v,&w);u++;v++;
            if(u>v)swap(u,v);
            s=Mp[make_pair(u,v)];
            if(s){
                if(s>w)Mp[make_pair(u,v)]=w;
            }else{
                Mp[make_pair(u,v)]=w;
                Graph[u].push_back(v);
                Graph[v].push_back(u);
            }
        }
        scanf("%d",&s);s++;
        solve();
    }
    return 0;
}
/// make_pair() empty() lld I64d push_back() top() pop() insert() upper_bound() lower_bound() memset() max() min() scanf continue
