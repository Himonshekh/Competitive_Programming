#include<bits/stdc++.h>
using namespace std;
typedef long long  L;
L n,c,x;
int t,p;
void solve(){
    c=1;
    x=n+1;
    while(n){
        c=(c*(n%p +1));
        n/=p;
    }
    x=x-c;
    printf("%lld\n",x);
}
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%lld%d",&n,&p);
        solve();
    }
    return 0;
}
/// empty() lld I64d push_back() top() pop() insert() upper_bound() lower_bound() memset() max() min() scanf continue
 
