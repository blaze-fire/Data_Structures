#include<iostream>
#include<list>
#include<string>

using namespace std;

// Hashtable to implement a plhonebook e.g. (234,Amit)

class hashtable{
    private:
        static const int hashgroups=10;
        list <pair<int, string>> table[hashgroups]; // List 1:index0    List2: index1 ....
        
    public:
        bool isempty() const;
        int hashfunction(int key);  // takes a key gives a hash value
        void insert(int key,string value);
        void remove(int key);
        string searchtable(int key);
        void print_table();
};


bool hashtable::isempty() const{
    int sum{};
    for(int i{};i<hashgroups;i++){
        sum += table[i].size();
    }

    if(!sum){
        return true;
    }
    return false;
}

int hashtable::hashfunction(int key){
    return key % hashgroups;            //if key is 905 the function returns 5
}

void hashtable::insert(int key, string value) {    
    bool isKeyFound = false;
    // Get hash key from hash function    
    int hashKey = hashfunction(key);

    // Iterate through chaining node (linked list)   
     // in selected cell    
    auto& cell = table[hashKey];

    for(auto itr = cell.begin() ; itr != cell.end();itr++){
       
        // if the key is found        
        // update the data
        if(itr->first == key){
            isKeyFound = true;
            itr->second = value;
            cout<<"Value Replace"<<endl;
            break;
        }
    }
    // If key is not found,    
    // append at the back  
    if(!isKeyFound){
        cell.emplace_back(key,value);
    }

    return ;
 }

void hashtable::remove(int key){

    int hashvalue = hashfunction(key);
    auto& cell = table[hashvalue];
    auto itr = begin(cell);
    bool keyexits = false;

    // Traverse the chaining node (Linked List)
    for(;itr != end(cell);itr++){

        if(itr->first == key){
            keyexits=true;
            itr = cell.erase(itr);
            cout<<"{INFO} Item Removed !"<<endl;
            break;
        }
        
    }

    if(!keyexits){
        cout<<"{WARNING} Key not Found! , Pair not Removed"<<endl;
    }

    return ;
}


string hashtable::searchtable(int key){
    int hashvalue = hashfunction(key);
    auto& cell = table[hashvalue];
    auto itr = begin(cell);

    for(;itr != end(cell); itr++){
        if(itr->first == key){
            return itr->second;
            break;
        }
    }
    return 0;
}


void hashtable::print_table(){

    for(int i{}; i < hashgroups ; i++){

        if(table[i].size() == 0)    continue;

        auto itr = table[i].begin();

        for(;itr != table[i].end();itr++){
            cout<<"{INFO} Key: "<<itr->first<<" ,Value: "<<itr->second<<endl;
        }
    }

    return ;
}

int main(){
    hashtable ht;

    if(ht.isempty()){
        cout<<"{WORKS FINE}"<<endl;
    }

    else{
        cout<<"Check code"<<endl;
    }    

    ht.insert(905,"AMIT");
    ht.insert(201,"ROHAN");
    ht.insert(332,"SHRAMAN");
    ht.insert(124,"BHAU");
    ht.insert(107,"KUMAR");
    ht.insert(929,"RAHUL");
    ht.insert(107,"KRISH");
    ht.print_table();

    ht.remove(201);
    ht.print_table();
    ht.remove(10);
    cout<<ht.searchtable(124);
    return 0;
}

