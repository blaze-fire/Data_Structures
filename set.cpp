#include <iostream>
#include <set>

using namespace std;

int main(){
    set <int> s;
    s.insert(40);
    s.insert(30);
    s.insert(60);
    s.insert(20);
    s.insert(50);    
    s.insert(50);
    set <int> s2(s.begin(),s.end());
    set <int>::iterator itr = s2.begin();
    for(; itr != s2.end(); itr++){
        cout<<*itr<<"   ";
    }
    return 0;
}