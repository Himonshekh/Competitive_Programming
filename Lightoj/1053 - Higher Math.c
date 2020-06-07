
#include<stdio.h>
#include<math.h>
int solve(int a,int b,int c){
    int l,r;
    l=(sqrtf((a*a)+(b*b))*100.0);
    r=(c*100.0);
    if(l==r)return 1;
    return 0;
}
int main()
{
    int t,cas=1;
    int a,b,c;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&a,&b,&c);
        if(solve(a,c,b)||solve(b,c,a)||solve(a,b,c))printf("Case %d: yes\n", cas++);
        else printf("Case %d: no\n", cas++);
    }
}
