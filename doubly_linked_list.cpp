#include <iostream>
#include <string>

using namespace std;

struct Doubley_Node{
    int data;
    Doubley_Node *predecessor,*sucessor;
}*l;

Doubley_Node *GetnewNode(int value){
    Doubley_Node *temp = new Doubley_Node;
    temp->data = value;
    temp->sucessor = nullptr;
    temp->predecessor = nullptr;
    return temp;
}

void insert(int value){
    Doubley_Node *temp = new Doubley_Node;
    if(l == nullptr) l = GetnewNode(value);

    temp->data = value;
    l->sucessor = temp->predecessor;
    temp->predecessor = l->sucessor;
    l = temp;
}

/*void Delete(int value){
    Doubley_Node *temp = new Doubley_Node;

    while(temp->predecessor != nullptr){
        if(temp->data == value)  break;
       // temp = temp-
    }
}*/

void print(){
    Doubley_Node *temp = (*l).predecessor;
    while(temp != nullptr){
        cout<<(*temp).data<<endl;
        temp = (*temp).sucessor;
    }
}

int main(){
    l == nullptr;
    insert(1);
    insert(2);
    insert(3);
    insert(4);    
    insert(5);
    print();
    return 0;
}