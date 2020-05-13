#include <bits/stdc++.h>
using namespace std;
#define Mx 100003
int A[Mx],Mp_a[Mx],ans[Mx],n,q,u,v,t,cas=1,cnt,block_size,s,e;
struct info{
    int U,V,idx;
    info(int U_,int V_,int idx_){
    	U=U_;
    	V=V_;
    	idx=idx_;
    }
};
vector<info>V;
bool cmp(info lf,info rt){
	int size_lf=(lf.U/block_size),size_rt=rt.U/block_size;
	if(size_lf<size_rt)return true;
	else if(size_lf==size_rt){
		if(lf.V<rt.V)return true;
	}
	return false;
}

void add(int id){
	Mp_a[A[id-1]]++;
	if(Mp_a[A[id-1]]==1)cnt++;
}
void remove(int id){
	Mp_a[A[id-1]]--;
	if(Mp_a[A[id-1]]==0)cnt--;
}
void solve(){
	sort(V.begin(), V.end(),cmp);//cout<<"ok"<<endl;
	s=e=0;
	for(int i=0;i<q;i++){
		u=V[i].U;v=V[i].V;
		while(e<v)add(++e);
		while(e>v)remove(e--);
		while(s<u)remove(s++);
		while(s>u)add(--s);
		ans[V[i].idx]=cnt;
	}
	for(int i=0;i<q;i++)printf("%d\n", ans[i]);
}
void reset(){
	memset(Mp_a,0,sizeof(Mp_a));
	V.clear();
}
int main()
{
    scanf("%d",&t);
    while(t--){
    	cnt=0;
        scanf("%d%d",&n,&q);
        block_size=sqrt(n+1);
        for(int i=0;i<n;i++){
        	scanf("%d",&A[i]);A[i]++;
        }
        for(int i=0;i<q;i++){
        	scanf("%d%d",&u,&v);
        	V.push_back(info(u,v,i));
        }
        printf("Case %d:\n",cas++);
        solve();
        if(t)reset();
    }
    return 0;
}
/// empty() lld I64d push_back() top() pop() insert() upper_bound() lower_bound() memset() max() min() scanf continue

