#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
//#include <functional> // for less
//using namespace __gnu_pbds;
using namespace std;
typedef long long  L;

#define max_(x, y) (((x) > (y)) ? (x) : (y))
#define min_(x, y) (((x) < (y)) ? (x) : (y))
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define Mx 100005
#define inf 1e15
const double pi = 2 * acos (0.0);

/*------------------------------Graph Moves----------------------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*---------------------------------------------------------------------*/


//typedef tree<L,null_type,less<L>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

L a1,a2,a3,b1,b2,b3,c,c1,c2,c3,d,d1,d2,d3,d4,d5,e1,e2,e3,f,h,k,l,n,m1,m2,n1,n2,o,p,p1,p2,p3,p4,q,q1,q2,q3,q4,r,s,t,
u,v,x,y,z,sum,mx=-inf,mn=inf,flg,flg1,flg2,id1,id2,id3,MOD,ans,Xi,Yi;

struct info{
    L a,m;
    info(L a_,L m_){
        a=a_;
        m=m_;
    }
};
vector<info>V;
vector<L>V1,V2,V3;

L fact[55][55],prim[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};

L inverseMod(L a,L pp,L m){
    L ans1=1,pow=a%m;
    while(pp){
        if(pp&1)ans1=(pow*ans1)%m;
        pow=(pow*pow)%m;
        pp >>=1;
    }
    return ans1;
}
void preprocess(){
    for(L i=0;i<16;i++){
        fact[prim[i]][0]=1;
        for(L j=1;j<=prim[i];j++){
            fact[prim[i]][j]=(fact[prim[i]][j-1]*j)%(prim[i]);
        }
    }
}
void primFact(){
    d1=p;
    for(L i=0;i<16&&d1;i++){
        if(d1%prim[i]==0){
            V3.push_back(prim[i]);
            d1=d1/prim[i];
        }
    }
}
void base_convert(){
    V1.clear();V2.clear();
    d2=n;
    while(d2){
        V1.push_back(d2%d1);
        d2=d2/d1;
    }
    d2=r;
    while(d2){
        V2.push_back(d2%d1);
        d2=d2/d1;
    }
}
void fun(L id){
    d1=V3[id];
    base_convert();
    id1=V2.size();
    if(V2.size()>V1.size()){
        V.push_back(info(0,V3[id]));
        return;
    }
    ans=1;
    for(L i=0;i<id1;i++){
        if(V1[i]<=V2[i]){
            if(V1[i]<V2[i]){
                ans=0;break;
            }
            continue;
        }
        d1=V1[i];d2=V2[i];
        ans=(ans* ((fact[V3[id] ][d1] *( (inverseMod(fact[V3[id] ][d1-d2],V3[id]-2,V3[id])%V3[id])*((inverseMod(fact[V3[id] ][d2],V3[id]-2,V3[id])%V3[id]) %V3[id]) )) %V3[id])%V3[id]);
    }
    V.push_back(info(ans,V3[id]));
}
void ext_gcd(L A,L B){
    L X1,X2,Y1,Y2,R,Q,TEMP;
    X1=1;X2=0;Y1=0;Y2=1;
    while(B){
        Q=A/B;
        R=(A-(B*Q));
        TEMP=(X1- (X2*Q));
        X1=X2;
        X2=TEMP;
        TEMP=(Y1- (Y2*Q));
        Y1=Y2;
        Y2=TEMP;
        A=B;
        B=R;
    }
    Xi=X1;Yi=Y1;
}

void chinese_remainder_theorem_CoPrime(){
    if(V.size()==0){
        printf("-111\n");return;
    }
    a1=V[0].a;
    m1=V[0].m;
    x=a1;
    n=V.size();
    for(L i=1;i<n;i++){
        a2=V[i].a;
        m2=V[i].m;
        ext_gcd(m1,m2);
        MOD=m1*m2;
        x=(((a1*m2*Yi)%MOD)+((a2*m1*Xi)%MOD))%MOD;
        a1=x;
        m1=MOD;
    }
    if(x<0)x+=m1;
    printf("%lld\n",x);
}

void solve(){
    if(r==1){
        printf("%lld\n",n%p);
        return;
    }
    if(n==r){
        printf("%lld\n", 1%p);
        return;
    }
    V.clear();
    V3.clear();
    primFact();
    l=V3.size();

    for(L i=0;i<l;i++){
        fun(i);
    }
    chinese_remainder_theorem_CoPrime();
}
int main()
{
    preprocess();
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld%lld",&n,&r,&p);
        solve();
    }
    return 0;
}
/// empty() lld I64d push_back() top() pop() insert() upper_bound() lower_bound() memset() max() min() scanf continue
