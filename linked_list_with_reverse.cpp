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
  if(root == nullptr) {
    root = temp1;
    return;
  }
  node *trav = root;
  while(trav->next !=  nullptr){
    trav = trav->next;
  }
  trav->next = temp1;
  temp1->next = nullptr;
  
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
  node *previous_node = predecessor(root, n);                //Address of predecessor node  

  if(previous_node){
    node *current_node= previous_node->next;                // Address of the node to be deleted
    if(current_node){
      previous_node->next = current_node->next;            //Connect predecessor to succesor
      delete current_node;
      return;
    }   
  }
}

void print(){
  node *temp = root;
  while(temp != nullptr){
    cout<<temp->data<<"  "<<endl;
    temp=temp->next;
  }
}


// function to print the linked list in reverse order

void reverse(){
  node *current = root, *next=nullptr, *prev=nullptr;
  while(current !=  nullptr){
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  root = prev;
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
  Search(root, 4);
  cout<<endl<<"Delete element : ";
  cin>>n;

  Delete(root, n);
  print();
  cout<<endl<<"Reversed list "<<endl;
  reverse();
  print();

}