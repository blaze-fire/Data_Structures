#include <iostream>
using namespace std;

struct stack{
    int data;
    stack *next;
};

stack *push(stack *top, int data){
    stack *temp = new stack;
    temp->data = data;
    temp->next = top;
    top = temp;
    return top;
}

void print(stack *top){
    stack *head = top;
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}

stack *pop(stack *top){
    cout<<endl<<"Item popped : "<<top->data;
    top = top->next;
    return top;
}

int main() {
    stack *top = NULL;
    top = push(top, 4);
    top = push(top, 3);
    top = push(top, 6);
    top = push(top, 90);
    top = push(top, 10);
    print(top);
    top = pop(top);
    cout<<endl;
    print(top);
    return 0;
}
