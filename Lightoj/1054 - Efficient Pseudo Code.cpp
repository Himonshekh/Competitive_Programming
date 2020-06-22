// #include <bits/stdc++.h>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
typedef long long  L;
#define MOD 1000000007
#define mx 1000001
vector<L>prim;
L mark[mx+1],m,sum,n;
L inverseMod(L a,L p,L m){
    L ans=1,pow=a%m;
    while(p){
        if(p&1)ans=(pow*ans)%m;
        pow=(pow*pow)%m;
        p >>=1;
    }
    return ans;
}
void preprocess(){
    prim.push_back(2);
    prim.push_back(3);
    L lim=sqrt(mx);

    for(L i=5;i<=mx;i+=2){
        if(!mark[i]){
            prim.push_back(i);
            if(i<=lim){
                for(L j=i*i;j<=mx;j+=(i*2)){
                    mark[j]=1;
                }
            }
        }
    }
}
L bigMod(L prm,L pod){
    if(pod==1)return (prm%MOD);
    L res=bigMod(prm,pod/2);
    if(pod%2){
        return ( ( (res*res)%MOD )*prm)%MOD;
    }else{
        return ( ( (res*res)%MOD ) %MOD);
    }
}
void doSum(L prm,L pow){
    L lob=(pow*m)+1,hor=(prm-1);
    lob=(bigMod(prm,lob)-1)%MOD;
    hor=inverseMod(hor,MOD-2,MOD);
    lob=(lob*hor)%MOD;
    sum=(sum*lob)%MOD;
}
void solve(){
    sum=1LL;
    L c,d=n;
    for(L i=0;prim[i]*prim[i]<=d;i++){
        c=0;
        while(d%prim[i]==0){
            c++;
            d/=prim[i];
        }
        if(c){
            doSum(prim[i],c);
        }
    }
    if(d>=2){
        if(d%MOD==0){
            sum=1LL;
        }else{
            doSum(d,1);
        }
    }
}
int main()
{
    preprocess();
    int t,cas=1;
    scanf("%d",&t);
    while(t--){
        scanf("%lld%lld",&n,&m);
        solve();
        printf("Case %d: %lld\n",cas++,sum);
    }
    return 0;
}
