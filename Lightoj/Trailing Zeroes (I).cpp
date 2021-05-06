#include<bits/stdc++.h>
using namespace std;
typedef long long  L;
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define Mx 1000003
#define inf 1e15
const L MOD = 1e9+7;
const double pi = 2 * acos (0.0);

L cas=1,a1,a2,a3,b1,b2,b3,c,c1,c2,c3,d,d1,d2,d3,d4,d5,e1,e2,e3,f,h,k,l,m,n,m1,m2,n1,n2,o,p,p1,p2,p3,p4,
q,q1,q2,q3,q4,r,s,t,u,v,x,y,z,sum,mx=-inf,mn=inf,flg,flg1,flg2,id1,id2,id3,id4,lim;

vector<L>prime,prm;
char np[Mx+5];
L nprm[Mx];
void sieve(){
    np[0]=np[1]='1';
    L lim=sqrt(Mx);
    prime.push_back(2);
    for(L i=3;i<=Mx;i+=2){
        if(np[i]!='1'){
            prime.push_back(i);
            if(i<=lim){
                for(L j=i*i;j<=Mx;j+=(i*2)){
                    np[j]='1';
                }
            }
        }
    }
    // lim=prime.size();
    // printf("%lld %lld %lld\n",lim,prime[lim-2],prime[lim-2]*prime[lim-2] );
}
void primeFact(L x){//999999000001 
    sum=0;
    for(L i=0;prime[i]*prime[i] <= x;i++){
        c=0;
        while(x%prime[i]==0){
            c++;x/=prime[i];
            if(x<1)break;
        }
        if(c){
            sum=sum+(sum*c)+c;
        }
    }
    if(x>=2){
        c=1;
        sum=sum+(sum*c)+c;
    }
}
void solve(){
    primeFact(n);
    printf("Case %lld: %lld\n",cas++,sum);
}
int main()
{
    sieve();
    t=1;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);
        solve();
    }
    return 0;
}
/// empty() lld push_back() top() pop() insert() upper_bound() lower_bound() memset() max() min() scanf continue
