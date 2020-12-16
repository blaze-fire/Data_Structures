#include <iostream>
#include<queue>

using namespace std;

struct Bstnode{
  int data;
  Bstnode *left;
  Bstnode *right;
};

Bstnode *Getnewnode(int data){
  Bstnode *temp=new Bstnode;
  temp->data=data;
  temp->left=nullptr;
  temp->right=nullptr;
  return temp;
}

Bstnode *insert(Bstnode *root,int data){
  if(root==nullptr){
    root=Getnewnode(data);
  }
  else if(data <= root->data){
    root->left=insert(root->left,data);
  }
  else {
    root->right=insert(root->right,data);
  }
  return root;
}

bool search(Bstnode *root,int data){
  if(root==nullptr){
    return false;
  }

  if(root->data == data){
    return true;
  }

  if(data < root->data){
    return search(root->left,data);
  }

  else{
    return search(root->right,data);
  }
  
}

void level_order(Bstnode *root){
  if(root==nullptr) return;

  queue <Bstnode *> q;
  q.push(root);

  while(!q.empty()){
    Bstnode *current=q.front();
    cout<<current->data<<" ";
    
    if(current->left != nullptr) q.push(current->left);
    if(current->right != nullptr) q.push(current->right);

    q.pop();
  }

}

void pre_order(Bstnode *root){
  if(root==nullptr){
    return;
  }
  cout<<root->data<<" ";
  pre_order(root->left);
  pre_order(root->right);
}

void inorder(Bstnode *root){
  if(root==nullptr) return;

  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}

void postorder(Bstnode *root){
  if(root==nullptr) return;

  postorder(root->left);
  postorder(root->right);
  cout<<root->data<<" ";

}

int main() {
  Bstnode *root=nullptr;
	root = insert(root,15);	
	root = insert(root,10);	
	root = insert(root,20);
	root = insert(root,25);
	root = insert(root,8);
	root = insert(root,12);

  /*int n;
  cin>>n;
  cout<<"Number Present: "<<search(root,n)<<endl;
  return 0;*/
  //pre_order(root);
  cout<<endl;
  level_order(root);
  cout<<endl;
  //inorder(root);
  cout<<endl;
  //postorder(root);

}