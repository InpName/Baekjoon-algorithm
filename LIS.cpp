#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> v;
    v.push_back(-2e9);
    int ans=0;
    for(int i=0;i<n;i++){
        if(v.back()<arr[i]){
            v.push_back(arr[i]);
            ans++;
        }else{
            auto it = lower_bound(v.begin(),v.end(),arr[i]);
            *it=arr[i];
        }
    }
    cout<<ans;
}
