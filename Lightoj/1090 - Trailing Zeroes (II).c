#include<stdio.h>
#define min_(x, y) (((x) < (y)) ? (x) : (y))

int find(int n,int id){
    int c=0,lv=id;
    while(n>=id){
        c+=(n/id);
        id=id*lv;
    }
    return c;
}
int find1(int n,int id,int q){
    int c=0;
    while(n%id==0){
        c++;
        n=n/id;
    }
    return (c*q);
}
int main()
{
    int c1,c2,n,r,p,q,t,cas=1;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d",&n,&r,&p,&q);
        c1=find(n,2);
        c1-=find(r,2);
        c1-=find((n-r),2);
        c1+=(find1(p,2,q));

        c2=find(n,5);
        c2-=find(r,5);
        c2-=find((n-r),5);
        c2+=(find1(p,5,q));
        printf("Case %d: %d\n",cas++,min_(c1,c2));
    }
    return 0;
}
