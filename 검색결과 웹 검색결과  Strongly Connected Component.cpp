#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
const int inf=10'001;
int id,d[inf];
stack<int> scc;
vector<int> con[inf];
vector<vector<int>> SCC;
bool finished[inf];
int dfs(int n){
    d[n]=++id;
    scc.push(n);
    int res=d[n];
    for(int i=0;i<con[n].size();i++){
        int gn=con[n][i];
        if(!d[gn]){
            res=min(res, dfs(gn));
        }else if(!finished[gn])
            res=min(res,d[gn]);
    }
    if(res==d[n]){
        vector<int> r;
        while(true){
            int gn=scc.top();
            scc.pop();
            r.push_back(gn);
            finished[gn]=true;
            if(gn==n)
                break;
        }
        sort(r.begin(),r.end());
        SCC.push_back(r);
    }
    return res;
}
int main(){
    int v,e;
    cin>>v>>e;
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        con[a].push_back(b);
    }
    for(int i=1;i<=v;i++){
        if(!d[i])dfs(i);
    }
    cout<<SCC.size()<<'\n';
    sort(SCC.begin(),SCC.end());
    for(int i=0;i<SCC.size();i++){
        for(int j=0;j<SCC[i].size();j++){
            cout<<SCC[i][j]<<' ';
        }
        cout<<"-1\n";
    }

}
