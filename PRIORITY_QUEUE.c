#include <stdio.h>
#include <limits.h>
#define MAX 50
typedef struct item
{
    int value;
    int priority;
} item;

item arr[MAX];
//size = > pointer to last index
int size = -1;
void enqueue(int value_, int priority_)
{
    size++;

    arr[size].value = value_; 
    arr[size].priority = priority_;
}

int peek()
{
    int highest_pr = INT_MIN;
    int ind=-1;

    for(int i=0; i<=size; i++)
    {
        if(highest_pr == arr[i].priority && ind>-1 && arr[ind].value < arr[i].value){
            highest_pr = arr[i].priority;
            ind=i;
        }
        else if(highest_pr < arr[i].priority){
            highest_pr = arr[i].priority;
            ind = i;
        }
    }
    return ind;
}

void dequeue()
{
    int ind = peek();
    for(int i=ind; i<size; i++){
        arr[i]=arr[i+1];
    }
    size--;
}

int main()
{
    enqueue(5,2);
    enqueue(10,3);
    enqueue(15, 4);
    enqueue(20,5);

    //top element;
    int ind = peek();
    printf("%d\n", arr[ind].value);
    //dequeue
    dequeue();
    
    ind = peek();

    printf("%d\n", arr[ind].value);
    ind = peek();
    printf("%d\n", ind);

    return 0;
}