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
#define Mx 200001
#define inf 1e15
const L MOD = 1e9+7;
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

L a1,a2,a3,b1,b2,b3,c,c1,c2,c3,d,d1,d2,d3,d4,d5,e1,e2,e3,f,h,k,l,m,n,m1,m2,n1,n2,o,p,p1,p2,p3,p4,q,q1,q2,q3,q4,r,s,t,
u,v,x,y,z,sum,mx=-inf,mn=inf,flg,flg1,flg2,id1,id2,id3,id4,lim;
queue<L>Q1,Q2;
void magic_divide(){
    while(!Q1.empty()){
        d1=Q1.front();
        Q1.pop();
        while(!Q2.empty()){
            d2=Q2.front();
            Q2.pop();
            m1=__gcd(d1,d2);
            if(m1>1){
                d1=d1/m1;
                d2=d2/m1;
                break;
            }
            Q2.push(d2);
        }
        if(d1>1)Q1.push(d1);
        if(d2>1)Q2.push(d2);
    }
}
void nCr(){
    while(!Q1.empty())Q1.pop();
    while(!Q2.empty())Q2.pop();
    lim=n-r;
    for(L i=n;i>lim;i--){
        Q2.push(i);
    }
    for(L i=r;i>1;i--){
        Q1.push(i);
    }
    magic_divide();
    while(!Q2.empty()){
        c=(c*Q2.front());
        Q2.pop();
    }
}
void solve(){
    n=n-1;
    r=k-1;
    r=min(r,n-r);
    if(r==0){
        printf("1\n");return;
    }
    c=1;
    nCr();
    printf("%lld\n",c);
}
int main()
{
    scanf("%lld",&t);
    
    while(t--){
        scanf("%lld%lld",&n,&k);
        solve();
    }
    return 0;
}
/// empty() lld I64d push_back() top() pop() insert() upper_bound() lower_bound() memset() max() min() scanf continue
