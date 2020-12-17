#include <iostream>

using namespace std;

class MaxHeap{  
    int arr[6];                                                     // array of size = (#elements + 1) as we set a[0] = -1 
    int size = 0;
    int parent(int i)   {return i/2;}                               // To get Adress of parent
    int left_child(int i)   {return i*2;}                           // To get Adress of left_child
    int right_child(int i)  {return 2*i + 1;}                       // To get Adress of right_child

    public:

    bool IsEmpty() {return size == 0;}
    int getmax() {return arr[1];}                                   // Max element is at the a[1]   as we set a[0] = -1 
    void insert(int value);
    void shiftup(int i);
    void shiftdown(int i);
    int extractMax();
};

void MaxHeap::shiftup(int i){                                       // To satisfy heap invariant after adding a new element
    if(i == 1)  return;

    if(arr[i] > arr[parent(i)]){
        std::swap( arr[parent(i)], arr[i]);
        shiftup(parent(i));
    }
}

void MaxHeap::insert(int value){
    if(size == 0){
        arr[size] = -1;                                             // set a[0] = -1 
        arr[++size] = value;
        return;
    }
   
    arr[++size] = value;
    shiftup(size);
    return;
}

void MaxHeap::shiftdown(int i){                                      //To satisfy heap invariant after removing the max element
    if(i >= size)   return;

    int swapId = i;

    if(left_child(i) <= size && arr[i] < arr[left_child(i)]){
        swapId = left_child(i);
    }
    if(right_child(i) <= size && arr[swapId] < arr[right_child(i)]){
        swapId = right_child(i);
    }

    if(swapId != i){
        std::swap(arr[i], arr[swapId]);
        shiftdown(swapId);
    }
}

int MaxHeap::extractMax(){                                              // to extract max element which is at a[1]
    int Max = arr[1];
    std::swap(arr[1],arr[size]);
    size--;
    shiftdown(1);
    return Max;
}

int main(){
    MaxHeap *Priority_Queue = new MaxHeap;
    if((*Priority_Queue).IsEmpty()){
        cout<<"code is working fine"<<endl;
    }
    else{
        cout<<"There is some problem"<<endl;
    }
    (*Priority_Queue).insert(10);
    (*Priority_Queue).insert(50);
    (*Priority_Queue).insert(100);
    (*Priority_Queue).insert(30);
    (*Priority_Queue).insert(40);
    cout<<"Max Element : "<<(*Priority_Queue).getmax()<<endl;
    cout<<(*Priority_Queue).extractMax()<<endl;
    cout<<"Max Element : "<<(*Priority_Queue).getmax()<<endl;
    return 0;
}