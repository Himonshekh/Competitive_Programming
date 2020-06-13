#include<stdio.h>
#include<string.h>

char item[61];
long long DP[61][61];

long long palindrom(int i,int j){
    if(DP[i][j]!=-1)return DP[i][j];
    if(i>j)return 0LL;
    else if(i==j)return 1LL;
    if(item[i]==item[j]){
        return DP[i][j]=1LL+palindrom(i+1,j)+palindrom(i,j-1);
    }else return DP[i][j]=palindrom(i+1,j)+palindrom(i,j-1)-palindrom(i+1,j-1);
}

int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--){
        memset(DP,-1,sizeof(DP));
        scanf("%s",item);
        printf("Case %d: %lld\n",cas++,palindrom(0,strlen(item)-1));
    }
    return 0;
}
