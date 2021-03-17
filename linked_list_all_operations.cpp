#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

node *push_back(node *root, int data){
    node *temp = new node();
    temp->data = data;
    temp->next = NULL;
    if(root == NULL){
        root = temp;
        return root;
    }
    node *trav = root;
    while(trav->next != NULL){
        trav = trav->next;
    }
    trav->next = temp;
    return root;
}

node *addFront(node *root, int data){
    node *temp = new node();
    temp->data = data;
    temp->next = root;
    root = temp;
    return root;
}

node *Insert(node *root, int data, int k){
    node *head = root;
    k--;
    node *temp = new node();
    temp->data = data; 
    while(k>1){
        head = head->next;
        k--;
    }
    node *curr = head->next;
    head->next = temp;
    temp->next = curr;
    return root;
}

node *predecessor(node *root, int data){
    node *head = root;
    while((head->next)->data != data){
        head = head->next;
    }
    return head;
}

node *Delete(node *root, int data){
    if(root->data == data){
        node *curr = root;
        root = curr->next;
        delete curr;
        return root;
    }
    
    node *prev = predecessor(root, data);
    node *curr = prev->next;
    node *next = curr->next;
    prev->next = next;
    curr->next = NULL;
    delete curr;
    return root;
    
}

node *reverse(node *root){
    node *prev=NULL, *curr=root, *next = NULL;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    root = prev;
    return root;
}

void print(node *root){
    node *head = root;
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}

int main() {
    node *root = NULL;
    root = push_back(root, 5);
    root = push_back(root, 3);
    root = push_back(root, 2);
    root = push_back(root, 4);
    root = push_back(root, 7);
    root = push_back(root, 8);
    root = addFront(root, 10);
    root = Insert(root, 20, 5);
    cout<<"Linked list : ";
    print(root);
    cout<<endl<<"List after deleting 10 : ";
    root = Delete(root, 10);
    print(root);
    cout<<endl<<"Reversed list : ";
    root = reverse(root);
    print(root);
    return 0;
}
