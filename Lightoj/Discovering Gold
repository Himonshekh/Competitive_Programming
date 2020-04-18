#include<stdio.h>
int A[101],t,n,i,cas=1;
double res[101],id,pos[101];
void solve(){
    id=1.0;
    res[n]=A[n];
    pos[n]=A[n];
    for(i=n-1;i>0;i--){
        if(i==1){
            if(id<7.0)pos[i]=((double)A[i]+(res[i+1]/id));
            else pos[i]=((double)A[i]+res[i+1]/6.0);
        }else{
            if(id<7.0)pos[i]=((double)A[i]+(res[i+1]/id));
            else pos[i]=((double)A[i]+res[i+1]/6.0);
        }
        res[i]=pos[i]+res[i+1];
        id=id+1.0;
        if(id>6.0)res[i]=res[i]-pos[i+6];
    }
    printf("Case %d: %.12f\n",cas++,pos[1]);
}
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",&A[i]);
        }
        solve();
    }
    return 0;
}
