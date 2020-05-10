#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
//#include <functional> // for less
//using namespace __gnu_pbds;
using namespace std;
typedef long long  L;

#define max_(x, y) (((x) > (y)) ? (x) : (y))
#define min_(x, y) (((x) < (y)) ? (x) : (y))
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define Mx 100001
#define inf 1e15
const L MOD = 1e9+7;
const double pi = 2 * acos (0.0);

/*------------------------------Graph Moves----------------------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*---------------------------------------------------------------------*/


//typedef tree<L,null_type,less<L>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;


vector<L>Tree[4*Mx];
L A[Mx],n,m,ans,a,b,c,d1;

void build(L node,L left,L right){
    if(left==right){
        Tree[node].push_back(A[left]);
        return;
    }
    L mid=(left+right)/2;
    build(node*2,left,mid);
    build((node*2) + 1,mid+1,right);
    merge(Tree[node*2].begin(),Tree[node*2].end(),Tree[(node*2) + 1].begin(),Tree[(node*2)+1].end(),back_inserter(Tree[node]));
}
L query(L node,L left,L right,L idi,L idj,L v){
    if(left>idj||right<idi)return 0;
    if(left>=idi&&right<=idj){
        L pos=upper_bound(Tree[node].begin(),Tree[node].end(),v)-Tree[node].begin();
        return pos;
    }
    L mid=(left+right)/2;
    return query(node*2,left,mid,idi,idj,v)+query((node*2)+1,mid+1,right,idi,idj,v);
}
void solve(){
    L low=-1e9,high=1e9,mid;
    while(low<=high){
        mid=(low+high)/2;
        d1=query(1,1,n,a,b,mid);
        if(d1>=c){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    printf("%lld\n",ans);
}
int main()
{
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&A[i]);
    }
    build(1,1,n);

    for(int i=0;i<m;i++){
        scanf("%lld%lld%lld",&a,&b,&c);
        solve();
    }
    return 0;
}
/// empty() lld I64d push_back() top() pop() insert() upper_bound() lower_bound() memset() max() min() scanf continue
