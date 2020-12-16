#include <stdio.h>
#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
int main() {
    int T;
    cin>>T;
    while(T>0)
        {   long int N,D,ans=0;
            cin>>N>>D;

            vector <int> urgent,non_urgent;
            urgent.reserve(10001);
            non_urgent.reserve(10001);
            for(int i=0;i<N;i++){
                int temp;
                cin>>temp;
                if(temp>=80 || temp<=9) urgent.push_back(temp);
                else
                {
                    non_urgent.push_back(temp);
                }
                
            }

            if(urgent.size()/2 != 0){
                ans = ans+urgent.size()/2 +1;
            }

            if(urgent.size()/2 == 0){
                ans = ans+urgent.size()/2 ;
            }

            if(non_urgent.size()/2 != 0){
                ans = ans + non_urgent.size()/2 +1;
            }
            
            if(non_urgent.size()/2 == 0){
                ans = ans + non_urgent.size()/2;
            }

            cout<<ans<<endl;
            T--;
        }
        

}