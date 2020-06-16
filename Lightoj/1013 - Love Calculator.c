#include <stdio.h>
#include <string.h>
#define max_(x, y) (((x) > (y)) ? (x) : (y))

char str1[31],str2[31];
int len,len1,len2,lcs[31][31];
long long DP[31][31][41];
long long make_Uinque(int x,int y,int z){
    if(z==len){
        if(x==len1&&y==len2)return 1LL;
        return 0;
    }
    if(DP[x][y][z]!=-1)return DP[x][y][z];
    if(x==len1)return DP[x][y][z]=make_Uinque(x,y+1,z+1);
    else if(y==len2)return DP[x][y][z]=make_Uinque(x+1,y,z+1);
    else if(str1[x]==str2[y]){
        return DP[x][y][z]=make_Uinque(x+1,y+1,z+1);
    }else return DP[x][y][z]=make_Uinque(x+1,y,z+1)+make_Uinque(x,y+1,z+1);
}
void make_Lcs(){
    len1=strlen(str1);
    len2=strlen(str2);
    for(int i=1;i<=len1;i++){
        for(int j=1;j<=len2;j++){
            if(str1[i-1]==str2[j-1]){
                lcs[i][j]=lcs[i-1][j-1]+1;
            }else lcs[i][j]=max_(lcs[i-1][j],lcs[i][j-1]);
        }
    }
    len=len1+len2-lcs[len1][len2];
    memset(DP,-1,sizeof(DP));
}
int main(){
    int t,cas=1;
    scanf("%d",&t);
    while(t-- ){
        scanf("%s%s",str1,str2);
        make_Lcs();
        printf("Case %d: %d %lld\n",cas++,len,make_Uinque(0,0,0));
    }
    return 0;
}
