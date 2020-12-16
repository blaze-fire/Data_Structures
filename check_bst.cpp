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

void print(Bstnode *root){

    if(root==nullptr) return;

    print(root->left);
    cout<<root->data<<" ";
    print(root->right);
}

int inorder(Bstnode *root){
  
  if(root==nullptr){
    return 0;
  }

  inorder(root->left);
  return(root->data);
  inorder(root->right);
  
}


bool check(Bstnode *root){
    
    if( ( root->data > inorder(root->left) ) && ( root->data < inorder(root->right) ) ) return true;

    else return false;
  
}

bool check_children(Bstnode *root){
    if(root==nullptr)  return true;

    if(root->left != nullptr && root->right != nullptr) return true;

    if(root->left == nullptr && root->right == nullptr) return true;

    else return false;
}

bool check_complete_bst (Bstnode *root){

    if( ( root->data > inorder(root->left) ) && ( root->data < inorder(root->right) ) 
    && check_children(root->left) && check_children(root->right) ){
        return true;
    } 
    
    else return false;

}

int main() {
    Bstnode *root=nullptr;
	root = insert(root,7);	
	root = insert(root,4);	
	root = insert(root,9);
	root = insert(root,1);
	root = insert(root,6);
	//root = insert(root,10);
    //root = insert(root,12);

    print(root);
    cout<<endl;

  if(check(root)==true){
      cout<<"YES!"<<endl;
  }

  if(check_complete_bst(root)==true){
      cout<<"Also a complete BST"<<endl;
  }
  
}