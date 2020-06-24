
// #include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long L;
L MOD=1000000007;
L tree[400001];
struct info{
    int d,id;
    info(int d_,int id_){
        d=d_;
        id=id_;
    }
};
vector<info>V;
bool cmp(info lf,info rt){
    if(lf.d!=rt.d){
        return lf.d<rt.d;
    }else{
        return lf.id>rt.id;
    }
}

L query(int node,int i,int j,int b ,int e){
    if(i>e||j<b)return 0;
    if(i>=b&&j<=e){
        return tree[node];
    }
    int mid=(i+j)/2;
    return (query(node*2,i,mid,b,e)%MOD+query(node*2+1,mid+1,j,b,e)%MOD)%MOD;
}
void update(L node,L i,L j,L pos,L val){
    if(i>pos|j<pos)return;
    if(i==j&&i==pos){
        tree[node]=val%MOD;
        return;
    }
    int mid=(i+j)/2;
    update(node*2,i,mid,pos,val);
    update(node*2+1,mid+1,j,pos,val);
    tree[node]=(tree[node*2]+tree[node*2+1])%MOD;
}
void solve(L n){
    sort(V.begin(), V.end(),cmp);
    for(int i=0;i<n;i++)
        update(1,1,n,V[i].id,query(1,1,n,1,V[i].id-1)+1);
}
void reset(){
    V.clear();
    memset(tree,0,sizeof(tree));
}
int main()
{
    int t,cas=1,n,d;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&d);
            V.push_back(info(d,i+1));
        }
        solve(n);
        printf("Case %d: %lld\n",cas++,tree[1]);
        if(t)reset();
    }
    return 0;
}
