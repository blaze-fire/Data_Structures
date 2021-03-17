#include <iostream>
using namespace std;

struct queue{
    int data;
    queue *next;
};

queue *front = NULL, *rear = NULL;

void push(int data){
    queue *temp = new queue;
    if(rear == NULL){
        temp->data = data;
        temp->next = NULL;
        front = rear = temp;
        return;
    }

    temp->data = data;
    rear->next = temp;
    temp->next = NULL;
    rear = temp;
}

void print(){
    queue *head = front;
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}

void pop(){
    cout<<endl<<"Item popped : "<<front->data<<endl;
    front = front->next;
    return;
}

int main() {
    push(4);
    push(3);
    push(6);
    push(90);
    push(10);
    print();
    pop();
    print();
    return 0;
}
