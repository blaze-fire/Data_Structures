// Complete BST from scratch with all functions 

#include <iostream>
#include <queue>

using namespace std;

struct BstNode{
    int data;
    BstNode *left, *right;
};

BstNode *Getnewnode(BstNode *root, int data){
    BstNode *newnode = new BstNode();
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}

BstNode *Insert(BstNode *root, int data){
    if(root == NULL){
        root = Getnewnode(root, data);
    }

    else if(data < root->data){
        root->left = Insert(root->left, data);
    }

    else{
        root->right = Insert(root->right, data);
    }

    return root;
}

bool Search(BstNode *root, int data){
    if(root == NULL){
        return false;
    }

    else if(root->data == data){
        return true;
    }

    else if(data < root->data){
        return Search(root->left, data);
    }

    else{
        return Search(root->right, data);
    }
}

int maxElement(BstNode *root){
    BstNode *current = root;
    while(current->right != NULL){
        current = current->right;
    }
    return current->data;
}


int minElement(BstNode *root){
    BstNode *current = root;
    while(current->left != NULL){
        current = current->left;
    }
    return current->data;
}

void level_order(BstNode *root){
    if(root == NULL)    return;

    queue<BstNode*> q;
    q.push(root);

    while(!q.empty()){
        BstNode *current = q.front();
        cout<<current->data<<"  ";
        if(current->left != NULL)   q.push(current->left);
        
        if(current->right != NULL)   q.push(current->right);

        q.pop();
    }
}

void preorder(BstNode *root){
    if(root == NULL)    return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);    
}

void inorder(BstNode *root){
    if(root == NULL)    return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}


void postorder(BstNode *root){
    if(root == NULL)    return;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int height(BstNode *root){
    if(root == NULL)    return 0;

    BstNode *current = root;
    int left_sub_height = 0, right_sub_height = 0;
    while(current != NULL){
        current = current->left;
        left_sub_height++;
    }

    current = root;
    while(current != NULL){
        current = current->right;
        right_sub_height++;
    }

    return std::max(left_sub_height, right_sub_height);
}

BstNode *FindMin(BstNode *root){
    BstNode *current = root;

    while(current->left != NULL){
        current = current->left;
    }

    return current;
}

BstNode *Delete(BstNode *root, int data){
    if(root == NULL)    return root;

    else if(data < root->data)  root->left = Delete(root->left, data);

    else if(data > root->data)  root->right = Delete(root->right, data);

    else{
        if(root->left == NULL && root->right==NULL){
            delete root;
            root=NULL;
        }

        else if(root->left == NULL){
            BstNode *temp = root;
            root = root->right;
            delete temp;
        }
        
        else if(root->right == NULL){
            BstNode *temp = root;
            root = root->left;
            delete temp;
        }

        else{
            BstNode *temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }

    return root;
}

int main(){
    BstNode *root = NULL;

    root = Insert(root,15);	
	root = Insert(root,10);	
	root = Insert(root,20);
	root = Insert(root,25);
	root = Insert(root,8);
	root = Insert(root,12);

    postorder(root);
    cout<<endl;
    level_order(root);
    cout<<endl<<"Max Element : "<<maxElement(root)<<" , and Min Element : "<<minElement(root)<<" , and height of tree is : "<<height(root);
    root = Delete(root,8);
    cout<<endl;
    level_order(root);
    return 0;
}
