#include<iostream>


int partition(int a[],int low,int high)
{
    int pivot=a[high];
    int i=low-1;

    for(int j=low;j<high;j++)
        if(a[j]<pivot)
        {
            ++i;
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    int temp=a[i+1];
    a[i+1]=a[high];
    a[high]=temp;

    return i+1;
}

int quicksort(int a[],int low,int high)
{
    if(low<high)
    {
        int temp=partition(a,low,high);
        quicksort(a,low,temp-1);
        quicksort(a,temp+1,high);
    }

}

int main()
{
    int a[5]={23,34,5,6,56};
    quicksort(a,0,4);
    for(int i=0;i<5;i++)
        std::cout<<a[i]<<" , ";
}
