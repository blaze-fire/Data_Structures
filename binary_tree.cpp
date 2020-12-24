#include <iostream>

using namespace std;

struct Binary {
  int data;
  Binary *left, *right;
}*bt;

Binary *GetNewNode(int value){
  Binary *NewNode = new Binary;
  NewNode->data = value;
  NewNode->left = nullptr;
  NewNode->right = nullptr;
  return NewNode; 
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

  bt = GetNewNode(0);
  bt->left = GetNewNode(1);
  bt->right = GetNewNode(0);
  (bt->right)->left = GetNewNode(1);
  (bt->right)->right = GetNewNode(1);
  

  print_dfs(bt);
  return 0;

}