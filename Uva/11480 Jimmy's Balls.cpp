#include<bits/stdc++.h>
using namespace std;
int n,a,b,b1,c,d1,i,cas=1;
long long ans;
void solve(){
    ans=0;
    for(i=1;;i++){
        a=i;b=a+1;c=b+1;
        if(a+b+c>n)break;
        d1=(n-a);
        b1=d1/2;
        if(d1%2==0)b1--;
        ans+=(b1-b+1);
    }
    printf("Case %d: %lld\n",cas++,ans);
}
int main()
{
    while(scanf("%d",&n)&&n)solve();
    return 0;
}
