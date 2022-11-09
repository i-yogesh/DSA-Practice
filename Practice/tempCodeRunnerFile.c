#include<stdio.h>
#define MAX 20
int queue[MAX];
int front = -1, rear = -1;


void enqueue(int x)
{
    if(front == MAX-1){
        printf("Queue is Full\n");
        return;
    }
    if(front == -1){
        front=rear=0;
        queue[rear] = x;
        return;
    }
    rear++;
    queue[rear] = x;
}

int dequeue()
{
    if(front == -1){
        printf("Queue is empty\n");
        return -1;
    }

    int val = queue[front];
    front++;
    return val;   
}

void display_q()
{
    for(int i=front; i<=rear; i++)
        printf("%d ", queue[i]);
}
int main()
{
    enqueue(5);
    enqueue(10);
    enqueue(15);
    display_q();
    printf("\n%d is deleted\n", dequeue());
    display_q();
    return 0;
}