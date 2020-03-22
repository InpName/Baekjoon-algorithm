#include <iostream>
#include <vector>
using namespace std;
const int maxINF=100'001;
vector<int> vec[maxINF];
int par[maxINF][20];
int dep[maxINF];
void makeParents(int node,int parent){
    dep[node]=dep[parent]+1;
    par[node][0]=parent;
    for(int i=1;i<17;i++){
        par[node][i]=par[par[node][i-1]][i-1];
    }
    for(int i=0;i<vec[node].size();i++){
        if(vec[node][i]!=parent)
            makeParents(vec[node][i],node);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin>>n;
    int a,b;
    for(int i=1;i<n;i++){
        cin>>a>>b;
        vec[b].push_back(a);
        vec[a].push_back(b);
    }
    int t;
    cin>>t;
    dep[0]=-1;
    makeParents(1,0);
    while(t--){
        cin>>a>>b;
        if(dep[a]>dep[b]) swap(a,b);
        for(int i=16;i>=0;i--){
            if(dep[a]<=dep[par[b][i]])
                b=par[b][i];
        }
        int lca=a;
        if(a!=b){
            for(int i=16;i>=0;i--){
                if(par[a][i]!=par[b][i]){
                    a=par[a][i];
                    b=par[b][i];
                }
            }
            lca=par[a][0];
        }
        cout<<lca<<'\n';
    }
}
