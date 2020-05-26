#include <stdio.h>
int t,c,cas=1;
long long n;
void Set(int id){
    n=n|(1<<id);
}
void Reset(int id){
    n=(n&~(1<<id));
}
void update(int id){
    for(int i=0;i<=id;i++){
        Reset(i);
        if(c){
            Set(i);
            c--;
        }
    }
}
void solve(){
    c=0;
    for(int i=0;i<33;i++){
        if( ( n&(1<<i) ) && ( ( n&(1<<(i+1) ) )==0 ) ){
            Set(i+1);
            update(i);
            break;
        }
        if(n&(1<<i))c++;
    }
    printf("Case %d: %lld\n",cas++,n);
}
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%lld",&n);
        solve();
    }
    return 0;
}
