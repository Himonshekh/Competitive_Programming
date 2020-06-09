
#include<bits/stdc++.h>
using namespace std;
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef pair<int, int> pii;
map<string ,int>Mp_c_id;
map<pii,int>Mp_cost;
map<int,int>Mp_a;
int id,u,v,w,t,cas=1,n,ans;
string city1,city2;
struct info{
    int U,V,W;
    info(int U_,int V_,int W_){
        U=U_;
        V=V_;
        W=W_;
    }
};
vector<info>Graph;
int get_City_Id(string city){
    if(Mp_c_id[city]){
        return Mp_c_id[city];
    }
    Mp_c_id[city]=++id;
    return id;
}


void valid(){
    int cost=Mp_cost[make_pair(u,v)];
    if(cost){
        if(cost>w){
            Mp_cost[make_pair(u,v)]=w;
        }
    }else{
        Mp_cost[make_pair(u,v)]=w;
    }
}
void make_Graph(){
    map<pii, int>::iterator itr; 
    for (itr = Mp_cost.begin(); itr != Mp_cost.end(); ++itr) {
        u=itr->first.first;
        v=itr->first.second;
        w=itr->second;
        Graph.push_back(info(u,v,w));
    }
}
bool cmp(info lf,info rt){
    if(lf.W<rt.W)return true;
    return false;
}
int par[55];
int Find(int x){
    if(par[x]==x){
        return x;
    }else{
        par[x]=Find(par[x]);
        return par[x];
    }
}
void make_par(){
    for(int i=0;i<=55;i++)par[i]=i;
}
void kruskal(){
    make_par();
    int lim=Graph.size();
    for(int i=0;i<lim;i++){
        u=Graph[i].U;
        v=Graph[i].V;
        w=Graph[i].W;
        u=Find(u);
        v=Find(v);
        if(u!=v){
            // cout<<u<<" "<<v<<endl;
            par[u]=v;
            ans+=(w-1);
        }
    }
}
bool possible(){
    int c=0;
    for(int i=1;i<=id;i++){
        u=Find(i);
        if(Mp_a[u]==0){
            c++;
            Mp_a[u]=1;
        }
    }
    if(c>1)return false;
    return true;
}
void solve(){
    ans=0;
    make_Graph();
    sort(Graph.begin(), Graph.end(),cmp);
    kruskal();
    if(possible()){
        cout<<"Case "<<cas++<<": "<<ans<<endl;
    }else{
        cout<<"Case "<<cas++<<": Impossible"<<endl;
    }
}
void reset(){
    Mp_c_id.clear();
    Mp_cost.clear();
    Mp_a.clear();
    Graph.clear();
    ans=0;
    id=0;
}
int main()
{
    ___
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>city1>>city2>>w;

            w++;
            u=get_City_Id(city1);
            v=get_City_Id(city2);
            if(u>v)swap(u,v);
            valid();
        }
        solve();
        if(t)reset();
    }
}
