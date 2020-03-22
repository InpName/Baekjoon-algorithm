#include <iostream>
#include <vector>
using namespace std;
int diff=1'000'001;
bool check[1'000'001]={true,true};
void getPrime(){
    for(int i=2;i*i<diff;i++){
        if(!check[i]){
            for(int j=i*i;j<diff;j+=i){
                check[j]=true;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    getPrime();
    int n;
    while(true){
        cin>>n;
        if(!n) return 0;
        for(int i=3;i<=n/2;i++){
            if(!check[i]&&!check[n-i]) {
                cout << n << " = " << i << " + " << n - i << '\n';
                break;
            }
        }
    }
}
