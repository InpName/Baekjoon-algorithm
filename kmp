#include <iostream>
#include <vector>
using namespace std;
vector<int> q;
vector<int> getTable(string str){
    vector<int> v(str.length(),0);
    for(int i=1,j=0;i<str.length();i++){
        while(j>0&&str[i]!=str[j]) j=v[j-1];
        if(str[i]==str[j])
            v[i]=++j;
    }
    return v;
}

void kmp(string s1,string s2){
    vector<int> t=getTable(s2);
    for(int i=0,j=0;i<s1.length();i++){
        while(j>0&&s1[i]!=s2[j]) j=t[j-1];
        if(s1[i]==s2[j]){
            if(j==s2.length()-1){
                q.push_back(i-s2.length()+2);
                j=t[j];
            }else j++;
        }
    }
}
int main(){
   
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s1,s2;
    cin.clear();
    getline(cin,s1);
    getline(cin,s2);
    kmp(s1,s2);
    cout<<q.size()<<'\n';
    for(int i=0;i<q.size();i++)
        cout<<q[i]<<'\n';
}
