#include <iostream>

using namespace std;

int gcd(int a,int b){
    
    if(b==1){
        return 1;
    }
    
    if(a%b==0){
        return b;
    }
 
   return gcd(a,a%b);
}

int main(){
  cout<<gcd(12345,123);
  return 0;
}