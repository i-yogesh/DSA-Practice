#include <stdio.h>
#define MAX 20
int queue[MAX];
int front = -1, rear = -1;
int st[MAX];
int top = -1;

void enqueue(int x)
{
    if (front == MAX - 1)
    {
        printf("Queue is Full\n");
        return;
    }
    if (front == -1)
    {
        front = rear = 0;
        queue[rear] = x;
        return;
    }
    rear++;
    queue[rear] = x;
}

int dequeue()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
        return -1;
    }

    int val = queue[front];
    front++;
    return val;
}

void display_q()
{
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
}

void push(int x)
{
    enqueue(x);
    for (int i = front; i < rear - 1; i++)
    {
        int val = dequeue();
        enqueue(val);
    }
}

int pop()
{
    if (front != -1)
    {
        int val = dequeue();
        return val;
    }
    return -1;
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