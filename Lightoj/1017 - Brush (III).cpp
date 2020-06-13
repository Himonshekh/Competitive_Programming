#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int A[100],DP[100][100],n,w;
int knapsack(int pos,int rem){
    if(pos>=n||rem==0)return 0;
    if(DP[pos][rem]!=-1)return DP[pos][rem];
    int lim=A[pos]+w,r1=0,r2,i;
    for(i=pos;i<n&&A[i]<=lim;i++){
        r1++;
    }
    r1+=knapsack(i,rem-1);
    r2=knapsack(pos+1,rem);
    return DP[pos][rem]=max(r1,r2);
}
int main()
{
    int t,cas=1,k,i;
    scanf("%d",&t);
    while(t--){
        memset(DP,-1,sizeof(DP));
        scanf("%d%d%d",&n,&w,&k);
        for(i=0;i<n;i++){
            scanf("%d%d",&A[i],&A[i]);
        }
        sort(A,A+n);
        printf("Case %d: %d\n",cas++,knapsack(0,k));
    }
    return 0;
}
