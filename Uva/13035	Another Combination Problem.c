#include<stdio.h>

typedef long long  L;
int t,cas=1;
L a,MOD=1e9+7;

int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&a);a++;
        if(a%3==0){
            printf("Case %d: %lld\n",cas++,((((a/3)*(a-1))%MOD)*(a+1))%MOD);
        }
        else if((a-1)%3==0){
            printf("Case %d: %lld\n",cas++,(((a*((a-1)/3))%MOD)*(a+1))%MOD);
        }
        else{
            printf("Case %d: %lld\n",cas++,(((a*(a-1))%MOD)*((a+1)/3))%MOD);
        }
    }
    return 0;
}
