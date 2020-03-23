#include<iostream>
#include <vector>
using namespace std;
const int maxv=101'001;

int sz[maxv],dep[maxv],par[maxv],top[maxv],in[maxv],out[maxv];
vector<int> arr[maxv];
/*
sz = root i's subtree size
top[i] = chain that include i 's top node
in[i], out[i] = dfs ordering
arr[i] = i's children
*/
int tree[4*maxv];
int sum(int l, int r, int n, int s, int e){
    if(l<=s&&r>=e) return tree[n];
    if(l>e||r<s) return 1e9;
    return  min(sum(l,r,n*2,s,(s+e)/2),sum(l,r,n*2+1,(s+e)/2+1,e));
}

void update(int n, int s, int e, int t){
    if(s>t||e<t) return;
    if(s==e){
        tree[n]=tree[n]==1e9?t:1e9;
        return;
    }
    update(n*2,s,(s+e)/2,t);
    update(n*2+1,(s+e)/2+1,e,t);
    tree[n]=min(tree[n*2+1],tree[n*2]);
}

void dfs1(int v = 1){
    sz[v] = 1;
    for(auto &i : arr[v]){
        if(par[v]==i) continue;
        dep[i] = dep[v] + 1; par[i] = v;
        dfs1(i); sz[v] += sz[i];
        if(sz[i] > sz[arr[v][0]]||par[v]==arr[v][0]) swap(i, arr[v][0]);
    }
}

int pv;
void dfs2(int v = 1){
    in[v] = ++pv;
    out[pv] = v;
    for(auto i : arr[v]){
        if(in[i]) continue;
        top[i] = i == arr[v][0] ? top[v] : i;
        dfs2(i);
    }
}

void upd(int a){
    update(1,1,pv,in[a]);
}
int query(int a){
    int b=1;
    int ret = 1e9;
    while(top[a] != top[b]){
        if(dep[top[a]] < dep[top[b]]) swap(a, b);
        int st = top[a];
        ret = min(ret,sum(in[st], in[a],1,1,pv));
        a = par[st];
    }
    if(dep[a] > dep[b]) swap(a, b);
    ret = min(ret,sum(in[a], in[b],1,1,pv));
    return ret==1e9?-1:out[ret];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;
    cin>>n;
    int a,b;
    for(int i=1;i<n;i++){
        cin>>a>>b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    top[1]=1;
    dfs1();dfs2();
    for(int i=0;i<4*maxv;i++)
        tree[i]=1e9;
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        if(a==1){
            upd(b);
        }else{
            cout<<query(b)<<'\n';
        }
    }
}
