// #include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
using namespace std;
#define min_(x, y) (((x) < (y)) ? (x) : (y))
char grid[11][11];
const int fx[]={+1,-1,+0,+0};
const int fy[]={+0,+0,+1,-1};
int mn,x,y,tot,n,flg,vis[11][11];
bool valid(int ii,int jj){
    if(ii<0||ii>=n||jj<0||jj>=n)return false;
    if(grid[ii][jj]=='#')return false;
    return true;
}
void dfs(int ii,int jj,char id,int dist=0){
    vis[ii][jj]=dist;
    if(grid[ii][jj]==id){
        mn=min_(mn,dist);
        x=ii;y=jj;
        return;
    }
    if( ( (grid[ii][jj]-'A'+1 != id-'A') &&grid[ii][jj]!='.') || dist+1>=mn)return;

    for(int i=0;i<4;i++){
        if(valid(ii+fx[i],jj+fy[i])){
            if(vis[ ii+fx[i] ][ jj+fy[i] ]>dist+1){
                dfs(ii+fx[i],jj+fy[i],id,dist+1);
            }
        }
    }
}
void fill(){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            vis[i][j]=99999999;
        }
    }
}
void solve(){
    int c=0,a,b;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='A'){
                x=i;y=j;
            }
            if(grid[i][j]!='.'&&grid[i][j]!='#'){
                c++;
            }
        }
    }
    char ch='A';
    tot=0;flg=0;
    // cout<<c<<endl;
    for(int i=0;i<c-1;i++){
        mn=99999999;
        fill();
        a=x,b=y;
        // cout<<x<<" "<<y<<" need "<<ch<<endl;
        dfs(x,y,++ch,0);
        if(mn==99999999){
            // cout<<x<<" "<<y<<" = "<<ch<<endl;
            flg=1;return;
        }else{
            tot+=mn;
        }
        grid[a][b]='.';
    }
}
int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%s",grid[i]);
        }
        solve();
        if(flg==0)printf("Case %d: %d\n",cas++,tot);
        else printf("Case %d: Impossible\n",cas++ );
    }
    return 0;
}

/*
some important case
3
10
W....H....
...Z.....R
..A..C..D.
F..Y..N...
B.E..G....
...J..K.L.
M...O.P.Q.
...T.U.V..
X........S
.........I
Case 1: 150

6
.....B
.###..
..C...
......
..A.#D
#.....
Case 2: 17

3
ABC
DEF
...
Case 3: 7



*/
