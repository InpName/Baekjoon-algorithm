#include <iostream>
#include <algorithm>
using namespace std;
struct edge{
    int x,y,v;
    bool operator <(edge &a){
        return v<a.v;
    }
};
int par[10'001];
int find(int n){
    return n==par[n]?n:par[n]=find(par[n]);
}
bool sum(int n,int m){
    n=find(n);
    m=find(m);
    if(n==m)
        return false;
    if(n>m) swap(n,m);
    par[m]=n;
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int v,e;
    cin>>v>>e;
    edge es[e];
    for(int i=0;i<v;i++){
        par[i]=i;
    }
    int a,b,c;
    for(int i=0;i<e;i++){
        cin>>a>>b>>c;
        es[i]={a,b,c};
    }
    sort(es,es+e);
    int ans=0;
    for(int i=0;i<e;i++){
        a=es[i].x;
        b=es[i].y;
        if(sum(a,b)){
            ans+=es[i].v;
        }
    }
    cout<<ans;
}
