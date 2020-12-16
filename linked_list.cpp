#include <iostream>
#include <string>
using namespace std;

struct node{
  int data;
  node* next;
}*root;


void Insert (int data){

  node *temp1=new node;
  temp1->data = data;
  temp1->next = root;
  root = temp1;


}

void Search(node *root, int value){
  if(root == nullptr){
    cout<<"Value not found"<<endl;
    return;
  }
  if(root->data == value){
    cout<<root->data<<endl;
    return;
  }
  Search(root->next,value);
}

node *predecessor(node *root, int value){
  if(root == nullptr) return nullptr;

  if((root->next)->data == value){
    return root;
  }
  
  return predecessor(root->next, value);
}

void Delete(node *root, int n){
  node *temp = predecessor(root, n);                //Address of predecessor node  

  if(temp){
    node *temp1= temp->next;                // Address of the succesor node 
    if(temp1){
      temp->next = temp1->next;            //Connext predecessor to succesor
      root = temp;
      delete temp1;
      return;
    }
  }
  
  Delete(root->next,n);
}

void print(){
  node *temp = root;
  while(temp != nullptr){
    cout<<temp->data<<"  "<<endl;
    temp=temp->next;
  }
}

int main() {
  root=nullptr;
  int data,n;

  Insert(1);
  Insert(2);
  Insert(3);
  Insert(4);
  Insert(5);  
  print();

  cout<<endl<<"Delete element : ";
  cin>>n;

  Delete(root, n);
  print();
}