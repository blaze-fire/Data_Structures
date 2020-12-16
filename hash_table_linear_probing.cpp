#include <stdio.h>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
int main() {
    int T;
    long int A,B;
    cin>>T;
    while(T>0){
        cin>>A>>B;
        
        int ans = std::min(A,B); 
        for(int i=1;i<=A;i++){
            for(int j=1;j<=B;j++){
                if(i != j){
                    if(((i+j) % 2) == 0){
                        ans++;
                    }
                }
            }
        }
        cout<<ans<<endl;
        T--;
    }

    
}