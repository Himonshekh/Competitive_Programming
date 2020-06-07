#include<stdio.h>
int main()
{
    int t,m,l,cas=1;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&m,&l);
        if(m==0){
            printf("Case %d: 0\n", cas++);
            continue;
        }
        if(m>l){
            printf("Case %d: %d\n", cas++,((m + (m-l))*4)+19);
        }else{
            printf("Case %d: %d\n", cas++,(l*4)+19);
        }
    }
    return 0;
}
