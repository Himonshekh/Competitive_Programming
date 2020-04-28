#include<bits/stdc++.h>
using namespace std;
int t,n,k,d,d1,d2,d3,c1,c,lim,id,res[100],rem,carr,quet;
queue<int>Q1,Q2;
vector<int>V[55],V1;
void magic_divide(){
    while(!Q2.empty()){
        d2=Q2.front();
        Q2.pop();
        if(Q1.empty())break;
        while(!Q1.empty()){
            d1=Q1.front();
            Q1.pop();
            d3=__gcd(d1,d2);
            if(d3>1){
                d2=d2/d3;
                d1=d1/d3;break;
            }
            Q1.push(d1);
        }
        if(d1>1)Q1.push(d1);
        if(d2>1)Q2.push(d2);
    }
}

void nCr(){
    lim=(c1-c);
    for(int i=c1;i>lim;i--){
        Q1.push(i);
    }
    for(int i=c;i>1;i--){
        Q2.push(i);
    }
    magic_divide();
}
void init(){
    d1=Q1.front();Q1.pop();
    while(d1){
        V1.push_back(d1%10);
        d1=d1/10;
    }
}
void single_product(){
    for(int i=0;i<id;i++)V[id].push_back(0);
    lim=V1.size();
    rem=carr=quet=0;
    for(int i=0;i<lim;i++){
        d3=V1[i];
        quet=(d3*d2)+carr;
        rem=quet%10;
        carr=quet/10;
        V[id].push_back(rem);
    }
    if(carr)V[id].push_back(carr);
}
void add_all(){
    memset(res,0,sizeof(res));
    int sz;
    for(int i=0;i<id;i++){
        if(i==0){
            lim=V[i].size();
            for(int j=0;j<lim;j++)res[j]=V[i][j];
            sz=lim;
        }else{
            lim=V[i].size();
            rem=carr=quet=0;
            for(int j=0;j<lim;j++){
                quet=(V[i][j]+res[j])+carr;
                rem=quet%10;
                carr=quet/10;
                res[j]=rem;
            }
            sz=lim;
            if(carr){
                while(carr){
                    quet=res[lim]+carr;
                    rem=quet%10;
                    carr=quet/10;
                    res[lim]=rem;
                    lim++;
                    sz=lim;
                }
            }
        }
        V[i].clear();
    }
    V1.clear();
    for(int i=0;i<sz;i++)V1.push_back(res[i]);
}
void product(){
    id=0;
    while(d1){
        d2=(d1%10);
        single_product();
        d1=d1/10;
        //printf("okkk\n");
        id++;
    }
    add_all();
}
void raw_product(){
    if(Q1.size()==0)return;
    V1.clear();
    init();
    if(Q1.empty()){
        lim=V1.size();
        for(int i=0;i<lim;i++){
            res[i]=V1[i];
        }
    }
    while(!Q1.empty()){
        d1=Q1.front();//cout<<d1<<endl;
        Q1.pop();
        product();
        // printf("okkk\n");
    }
}
void solve(){
    c1=(k+(n-c));
    if(k){
        c+=(k-1);
        c=n-c;
    }
    if(c<0){
        printf("0\n");
        return;
    }else if(c==0){
        printf("1\n");
        return;
    }
    c1=(c1-(k-1));
    d1=(c1-c);
    c=min(d1,c);
    // cout<<c1<<" "<<c<<endl; 
    while(!Q1.empty())Q1.pop();
    while(!Q2.empty())Q2.pop();
    V1.clear();
    memset(res,0,sizeof(res));
    nCr();

    raw_product();
    //printf("=okk\n");
    V1.clear();d1=0;
    for(int i=55;i>=0;i--){
        if(d1){
            V1.push_back(res[i]);
            continue;
        }
        if(res[i]){
            d1=1;
            V1.push_back(res[i]);
        }
    }
    lim=V1.size();
    for(int i=0;i<lim;i++)printf("%d",V1[i]);printf("\n");
}
int main()
{
    scanf("%d",&t);
    while(t--){
        c=0;
        scanf("%d%d",&n,&k);
        for(int i=0;i<k;i++){
            scanf("%d",&d);
            c+=d;
        }
        solve();
    }    
    return 0;
}
