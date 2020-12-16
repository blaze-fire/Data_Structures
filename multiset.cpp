#include<iostream>
#include<set>
#include<string>
using namespace std;

class Person{
    public :
        float age;
        string name;
    bool operator > (const Person &rhs) const {return age>rhs.age;}
    bool operator < (const Person &rhs) const {return age<rhs.age;}
};
int main(){

    std::multiset <Person,std::less<Person>> Multiset={{25,"Hitesh"},{30,"ramesh"},{25,"Jitesh"}};
    for (const auto & i: Multiset){
        cout<<i.age<<" "<<i.name<<endl;
    }
    return 0;
}