#include <cstdio>
#include <cstring>
using namespace std;
typedef long long  L;

char num[17];
L DP[1<<16][20];
int n,base,k;
int getDigit(char x){
    if(x>='A'){
        return (x-'A'+10);
    }
    return (x-'0');
}
L solve(L mask,L mod){
    if(mask+1==(1LL<<n))return (mod==0);
    if(DP[mask][mod]!=-1)return DP[mask][mod];
    DP[mask][mod]=0;
    for(int i=0;i<n;i++){
        if(mask&(1<<i))continue;
        DP[mask][mod]+=solve(mask|(1<<i),((mod*base) + getDigit(num[i]))%k);
    }
    return DP[mask][mod];
}

int main() {
    int t,cas=1;
    scanf("%d",&t);
    while(t--){
        memset(DP,-1,sizeof(DP));
        scanf("%d%d%s",&base,&k,num);
        n=strlen(num);
        printf("Case %d: %lld\n",cas++,solve(0,0));
    }
    return 0;
}
