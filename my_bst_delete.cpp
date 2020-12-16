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

Bstnode *Min(Bstnode *root){

  while(root->left != nullptr)  root=root->left;

  return root;
}

Bstnode *Delete(Bstnode *root,int value){
 
 if(root==nullptr) return root;

 else if(value < root->data) root->left = Delete(root->left, value);

 else if(value > root->data) root->right = Delete(root->right,value);

 else{


   //Case 1 One child
   if(root->left==nullptr && root->right==nullptr){
     delete root;
     root=nullptr;
   }


  //Case 2      No child
   else if(root->left==nullptr){
     Bstnode *temp=root;
     root=root->right;
     delete temp;
   }

   else if(root->right==nullptr){
     Bstnode *temp=root;
     root=root->left;
     delete temp;
   }

  //Case 3 Two child
  else{
      Bstnode *temp= Min(root->right);
      root->data=temp->data;
      root->right=Delete(root->right, temp->data);
  }

 }
 return root;
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
int main() {
  Bstnode *root=nullptr;
	root = insert(root,12);	
	root = insert(root,5);	
	root = insert(root,15);
	root = insert(root,3);
	root = insert(root,7);
	root = insert(root,13);
  root = insert(root,17);
  root = insert(root,1);
  root = insert(root,9); 
  
  level_order(root);
  cout<<endl;
  Delete(root,15);

  level_order(root);
  cout<<endl;
  
  return 0;
}