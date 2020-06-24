
// #include <bits/stdc++.h>
#include <stdio.h>
int A[101],f;
void add(int d,int n){
    for(int i=0;i<n;i++)A[i]+=d;
}
void multiply(int d,int n){
    for(int i=0;i<n;i++)A[i]*=d;
}
void divide(int d,int n){
    for(int i=0;i<n;i++)A[i]/=d;
}
void reverse(int n){
    for(int i=0,j=n-1;i<j;i++,j--){
        f=A[i];A[i]=A[j];A[j]=f;
    }   
}
int main()
{
    int t,cas=1,n,m,d,e;
    char ch;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)scanf("%d",&A[i]);

        for(int i=0;i<m;i++){
            scanf(" %c", &ch);
            if(ch=='S'){
                scanf("%d",&d);
                add(d,n);
            }else if(ch=='M'){
                scanf("%d",&d);
                multiply(d,n);
            }else if(ch=='D'){
                scanf("%d",&d);
                divide(d,n);
            }else if(ch=='R'){
                reverse(n);
            }else{
                scanf("%d%d",&d,&e);
                f=A[d];A[d]=A[e];A[e]=f;
            }
        }
        printf("Case %d:\n",cas++ );
        for(int i=0;i<n;i++){
            i+1==n?printf("%d\n",A[i]):printf("%d ",A[i]);;
        }
    }
    return 0;
}
