#include<iostream>
#include<map>
#include<vector>

using namespace std;

int main(){
    std::map <string,vector<int>> Map;
    Map["amit"].push_back(60);
    Map["amit"].push_back(50);
    Map["Rohan"].push_back(898);
    for(auto & el1 : Map){
        cout<<el1.first<<" : ";
        for(auto & el2 : Map ,el1.second){
            cout<<el2<<" ";
        }
        cout<<endl;
    }
    return 0;
}