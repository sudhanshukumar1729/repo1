#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i>=j)
                cout<<j;
            else
                cout<<" ";
        }
        cout<<endl;
    }
    return 0;
    
}