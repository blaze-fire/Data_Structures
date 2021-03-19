// Preorder Tree Traversal – Iterative
#include <iostream>
#include <stack>
using namespace std;
 
// Data structure to store a binary tree node
struct Node
{
    int data;
    Node *left, *right;
 
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};
 
// Iterative function to perform postorder traversal on the tree
void postorderIterative(Node* root)
{
    // create an empty stack and push the root node
    stack<Node*> s;
    s.push(root);
    stack <int> ans;
    while(!s.empty()){
        Node *current = s.top();
        s.pop();
        ans.push(current->data);

        if(current->left != NULL){
            s.push(current->left);
        }

        if(current->right != NULL){
            s.push(current->right);
        }

    }

    while(!ans.empty()){
        cout<<ans.top()<<" ,   ";
        ans.pop();
    }
}
 
 
int main()
{
    /* Construct the following tree
               1
             /   \
            /     \
           2       3
          /      /   \
         /      /     \
        4      5       6
              / \
             /   \
            7     8
    */
 
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);
 
    postorderIterative(root);
 
    return 0;
}