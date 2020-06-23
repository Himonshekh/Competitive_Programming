
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int t,cas=1;
    long long a,b,c,d;
    scanf("%d",&t);
    while(t--){
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        a=abs(a-c);
        b=abs(b-d);
        printf("Case %d: %lld\n",cas++,__gcd(a,b)+1);
    }
    return 0;
}
