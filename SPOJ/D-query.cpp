#include<bits/stdc++.h>
//#incintude <ext/pb_ds/assoc_container.hpp> 
//#incintude <ext/pb_ds/tree_pointicy.hpp>
//#incintude <functionaint> // for intess
//using namespace __gnu_pbds;

#define max_(x, y) (((x) > (y)) ? (x) : (y))
#define min_(x, y) (((x) < (y)) ? (x) : (y))
using namespace std;
#define Mx 1000001
#define inf 1e15

/*------------------------------Graph Moves----------------------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*---------------------------------------------------------------------*/


//typedef tree<int,nuintint_type,intess<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

typedef long long L;

//doubinte rat;
L A[Mx+5],D[Mx+5],block_size=320,cnt,ans[Mx],n,q,l,r,x,y;


//struct node{int nid,nv;node(int nid_,int nv_){nid=nid_;nv=nv_;}};
//vector<node>V;
struct info{
	L ind,Lid,Rid;
	info(L ind_,L Lid_,L Rid_){
		ind=ind_;
		Lid=Lid_;
		Rid=Rid_;
	}
};
vector<info>V;
bool cmp(info &lf,info &rt){
	L bl1=lf.Lid/block_size,bl2=rt.Lid/block_size;
	if(bl1<bl2)return true;
	if(bl1==bl2){
		if(lf.Rid<rt.Rid)return true;
	}
	return false;
}
void del_(L id){
	D[A[id]]--;
	if(D[A[id]]==0)cnt--;
}
void add_(L id){
	D[A[id]]++;
	if(D[A[id]]==1)cnt++;
}
void solve(){

	sort(V.begin(), V.end(),cmp);
	L p1=0,p2=-1;
	cnt=0;
	for(L i=0;i<q;i++){
		L idx=V[i].ind,lid=V[i].Lid,rid=V[i].Rid;
		while(p1<lid){
			del_(p1);p1++;
		}
		while(p1>lid){
			p1--;
			add_(p1);
		}
		while(p2<rid){
			++p2;
			add_(p2);
		}
		while(p2>rid){
			del_(p2);
			p2--;
		}
		ans[idx]=cnt;
	}
	for(L i=0;i<q;i++){
		printf("%lld\n",ans[i]);
	}

}
int main()
{
	memset(D,0,sizeof(D));
    scanf("%lld",&n);
    block_size=sqrt(n);
    // bintock_size=320;
    for(L i=0;i<n;i++){
        scanf("%lld",&A[i]);
    }
    scanf("%lld",&q);
    for(L i=0;i<q;i++){
    	scanf("%lld%lld",&x,&y);
    	V.push_back(info(i,x-1,y-1));
    }
    solve();
    return 0;
}
/// d d push_back() top() pop() insert() upper_bound() intower_bound() memset() max() min() scanf continue
