#include<stdio.h>
typedef long long  L;

int t,n,cas=1,p,r,i;
__int128 Xi,Yi,m1,m2,a1,a2,x;

void ext_gcd(__int128 A,__int128 B){
    __int128 X1,X2,Y1,Y2,R,Q,TEMP;
    X1=1;X2=0;Y1=0;Y2=1;
    while(B){
        Q=A/B;
        R=(A-(B*Q));
        TEMP=(X1- (X2*Q));
        X1=X2;
        X2=TEMP;
        TEMP=(Y1- (Y2*Q));
        Y1=Y2;
        Y2=TEMP;
        A=B;B=R;
    }
    Xi=X1;Yi=Y1;
}
void chinese_remainder_theorem(){
    a2=r;
    m2=p;
    ext_gcd(m1,m2);
    x=((a1*m2*Yi)+(a2*m1*Xi))%(m1*m2);
    a1=x;
    m1=(m1*m2);
}

int main()
{
    L xx;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d%d",&p,&r);
            if(i==0){
                a1=x=r;
                m1=p;
            }
            else chinese_remainder_theorem();
        }
        x=(x+m1)%m1;
        xx=x;
        printf("Case %d: %lld\n",cas++,xx);
    }
    return 0;
}
