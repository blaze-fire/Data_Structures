/*Code for Doubly linked list with all operations
*/
#include <iostream>

using namespace std;

struct node{
  int data;
  node *next,*prev;
}*head, *tail;

// insert at the front of the list
void insert_front(int data){
  node *temp = new node;
  temp->data = data;
  if(head == nullptr){
    temp->next = nullptr;           // initially when list is empty them head and tail are pointing to same location
    temp->prev = nullptr;
    head = tail = temp;
    return ;
  }

// insert new node in fron move head backwards to the new node and make all necessory connections for next and prev 
  temp->next = head;              // if list already contain elements than onlu move head to the newly inserted node as inserting at the front so we will not change tail 
  head->prev = temp;
  head = temp;
}

// insert at the end of list
void insert_end(int data){
  node *temp = new node;                  //create a new node
  temp->data = data;
  if(tail == nullptr){
    temp->next = nullptr;                 // initially when list is empty them head and tail are pointing to same location 
    temp->prev = nullptr;
    head = tail = temp;
    return;  
  }
  
  // insert new node in end move tail forward to the new node and make all necessory connections for next and prev
    temp->next = nullptr;               // if list already contain elements then jus move the tail to the newly inserted node after making all the new connections 
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

// Delete on the basis of index, not value
void Delete(int k){
  node *trav = head;
  k--;
  while(k--){
    trav = trav->next;
  }  
  
  if(trav == head){                     // when deleteing the head node move head forward and make housekeeping changes and delete the node
    head = trav->next;
    trav->next->prev = nullptr;
    trav->next = nullptr;
    delete trav;
    return;
  }

// when deleteing the tail node move tail backwards and make housekeeping changes and delete the node

  if(trav == tail){     
    tail = trav->prev; 
    trav->prev->next = nullptr;
    trav->prev = nullptr;
    delete trav;
    return;
  }

  //if deleting in middle of the node link previous node the next node and vice versa to make two way connection  
  
  trav->prev->next = trav->next;
  trav->next->prev = trav->prev;
  trav->next = nullptr;
  trav->prev = nullptr;
  delete trav;
}

void print(){
  node *temp = head;
  while(temp != nullptr){
    cout<<temp->data<<"   ";
    temp = temp->next;
  }
}

int main(){
  head = nullptr, tail = nullptr;
  insert_front(2);
  insert_front(3);  
  insert_end(4);
  insert_end(5);
  print();
  cout<<endl;
  Delete(3);
  print();
  return 0;
}