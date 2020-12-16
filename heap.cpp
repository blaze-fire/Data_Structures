#include <iostream>

using namespace std;

class heap{
    int heapsize=0;
    public:

    bool IsEmpty();
    void insert(int index);

}
bool heap::IsEmpty(){
    // Heap empty only if heapsize ==0 

    return heapsize==0;
}

void heap::shiftup