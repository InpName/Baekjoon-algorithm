#include <iostream>
using namespace std;
int arr[100][100];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cin>>arr[i][j];
    }
    //path
    for(int i=0;i<n;i++){
        //from
        for(int j=0;j<n;j++){
            //to
            for(int k=0;k<n;k++){
                if(arr[j][k]) continue;
                if(arr[j][i]&&arr[i][k])
                    arr[j][k]=1;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) {
            cout << arr[i][j]<<' ';
        }
        cout<<'\n';
    }
}
