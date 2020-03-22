#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>tree[300001];
vector<int>arr;
void update(int n, int en,int s,int e,int diff){
    if(en<s||en>e) return;
    tree[n].push_back(diff);
    if(s!=e) {
        update(n * 2, en, s, (s + e) / 2, diff);
        update(n * 2 + 1, en, (e + s) / 2 + 1, e, diff);
    }
}
int find(int l,int r,int n,int s,int e,int diff){
    if(l>e || r<s) return 0;
    if(l<=s && e<=r) return tree[n].end() - upper_bound(tree[n].begin(), tree[n].end(), diff);
    int mid = (s+e)/2;
    return find(l, r,n*2, s, mid,  diff) + find( l, r,n*2+1, mid+1, e, diff);
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n;
    cin>>n;
    arr.resize(n+1);
    for(int i=1;i<=n;i++)
        cin>>arr[i],update(1,i,1,n,arr[i]);
    for(int i=0;i<300001;i++)
        sort(tree[i].begin(),tree[i].end());
    int t;
    cin>>t;
    int a,b,c;
    while(t--){
        cin>>a>>b>>c;
        cout<<find(a,b,1,1,n,c)<<'\n';
    }

}
