#include <iostream>
typedef long long ll;
using namespace std;
int arr[1000001];
ll tree[3000001];

ll init(int n, int s, int e){
    if(s==e) return tree[n]=arr[s];
    int mid=(s+e)/2;
    return tree[n]=init(n*2,s,mid)+init(n*2+1,mid+1,e);
}
ll sum(int l, int r, int n, int s, int e){
    if(l<=s&&r>=e) return tree[n];
    if(l>e||r<s) return 0;
    int mid=(s+e)/2;
    return sum(l,r,n*2,s,(s+e)/2)+sum(l,r,n*2+1,(s+e)/2+1,e);
}


void update(int n, int s, int e, int t, int diff){
    if(s<=t&&e>=t) tree[n]+=diff;
    else return;
    if(s==e) return;
    int mid=(s+e)/2;
    update(n*2,s,(s+e)/2,t,diff);
    update(n*2+1,(s+e)/2+1,e,t,diff);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    init(1, 1, n);
    int c,a,b;
    for(int i=0;i<m+k;i++){
        cin>>c>>a>>b;
        if(c==1){
            int v=b-arr[a];
            arr[a]=b;
            update(1,1,n,a,v);
        }else{
            cout<<sum(a,b, 1, 1, n)<<"\n";
        }
    }
}
