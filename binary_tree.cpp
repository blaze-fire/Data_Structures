#include <iostream>

using namespace std;

struct Binary {
  int data;
  Binary *left, *right;
}*bt;

Binary *GetNewNode(int value){
  Binary *NewNode = new Binary();
  NewNode->data = value;
  NewNode->left = nullptr;
  NewNode->right = nullptr;
  return NewNode; 
}

void Insert(Binary *bt, int value){
  if(bt == nullptr) bt = GetNewNode(value);

  else if(value > bt->data){
    Insert(bt->left, value);
  }

  else{
    Insert(bt->right, value);
  }
}

void print_dfs(Binary *bt){
  if(bt == nullptr){
    return;
  } 

  cout<<bt->data<<" ";
  print_dfs(bt->left);
  cout<<endl;
  print_dfs(bt->right);

}


int main() {

  Insert(bt,1);
  Insert(bt,2);
  Insert(bt,3);
  Insert(bt,4);
  Insert(bt,5);
  Insert(bt,6);
  Insert(bt,7);

  print_dfs(bt);
  return 0;

}