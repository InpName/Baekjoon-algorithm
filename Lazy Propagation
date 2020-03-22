#include <iostream>
typedef long long ll;
using namespace std;
int arr[1000001];
ll tree[3000001];
ll lazy[3000001];

ll init(int n, int s, int e){
    if(s==e) return tree[n]=arr[s];
    int mid=(s+e)>>1;
    int gn=n<<1;
    return tree[n]=init(gn,s,mid)+init(gn|1,mid+1,e);
}
void update_lazy(int node, int start, int end) {
    if (lazy[node] != 0) {
        tree[node] += (end-start+1)*lazy[node];
        if (start != end) {
            lazy[node<<1] += lazy[node];
            lazy[node<<1|1] += lazy[node];
        }
        lazy[node] = 0;
    }
}
ll sum(int l, int r, int n, int s, int e){
    if(l>e||r<s) return 0;
    update_lazy(n, s, e);
    if(l<=s&&r>=e) return tree[n];
    int mid=(s+e)>>1;
    int gn=n<<1;
    return sum(l,r,gn,s,mid)+sum(l,r,gn|1,mid+1,e);
}

void update(int n, int s, int e, int left, int right, long long diff){
    update_lazy(n, s, e);
    if(left>e||right<s) return;
    int gn=n<<1;
    int mid=(s+e)>>1;
    if(left<=s&&e<=right){
        tree[n]+=(e-s+1)*diff;
        if(s!=e){
            lazy[n*2]+=diff;
            lazy[n*2+1]+=diff;
        }
        return;
    }
    update(gn,s,mid,left,right,diff);
    update(gn|1,mid+1,e,left,right,diff);
    tree[n]=tree[gn]+tree[gn|1];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    init(1, 1, n);
    int c,a,b;
    for(int i=0;i<m+k;i++){
        cin>>c>>a>>b;
        if(c==1){
            long long v;
            cin>>v;
            update(1,1,n,a,b,v);
        }else{
            cout<<sum(a,b, 1, 1, n)<<"\n";
        }
    }
}
