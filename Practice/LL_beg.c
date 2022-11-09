#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;
Node *head = NULL;

Node *create(int x)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}
void insertion_At_Beg(int x)
{
    Node *newNode = create(x);
    if (newNode == NULL)
    {
        printf("Memory can't be allocated\n");
        return;
    }
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}

void display()
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
int main()
{
    insertion_At_Beg(40);
    insertion_At_Beg(53);
    insertion_At_Beg(90);
    display();
    return 0;
}