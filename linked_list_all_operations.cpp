#include <iostream>

using namespace std;

struct node{
  int data;
  node *next;
}*root;

void push_back(int data){
  node *temp = new node;
  temp->data = data;
  temp->next = nullptr;
  if(root == nullptr){
    root = temp;
    return;
  }
  node *trav = root;
  while(trav->next != nullptr){
    trav = trav->next;
  }
  trav->next = temp;
}

void addFront(int data){
  node *temp = new node;
  temp->data  = data;
  temp->next = nullptr;
  if(root != nullptr) temp->next = root;
  root = temp;
}

node *predecessor(node *head ,int data){
  if(head == nullptr) return nullptr;

  if((head->next)->data == data){
    return head;
  }
  return predecessor(head->next, data);
}

void Delete(int data){
  node *prev = predecessor(root, data);
  if(prev != nullptr){
    node *curr = prev->next;
    node *next = curr->next;
    prev->next = next;
    curr->next = nullptr;
    delete curr;
  }
}

void Insert(int data, int k){
  node *temp = new node;
  temp->data = data;
  node *head = root;
  k--;
  while(k>1){
    head = head->next;
    k--;
  }
  node *curr = head->next;
  head->next = temp;
  temp->next = curr;
}


void print(){
  node *head = root;
  while(head != nullptr){
    cout<<head->data<<"     ";
    head = head->next;
  }
}

void reverse(){
  node *prev = nullptr, *curr = root, *next = nullptr;
  while(curr != nullptr){
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  root = prev;
}


int main(){
  root = nullptr;
  push_back(5);
  push_back(10);
  push_back(15);
  addFront(1);
  addFront(2);
  addFront(3);  
  Insert(4,3);
  print();
  //reverse();
  Delete(5);
  cout<<endl;
  print();
  return 0;
}