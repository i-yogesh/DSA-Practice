#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    int priority;
    struct Node *next;
} Node;

Node *head = NULL;

Node *create(int val, int pr)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    newNode->priority = pr;
}

int peek()
{
    return head->data;
}

void push(int d, int p)
{
    Node* temp = head;
    Node* newNode = create(d, p);
    if(head->priority < p){
        newNode->next = head;
        head = newNode;
    }
    else
    {
        while(temp->next!=NULL && temp->next->priority > p)
        temp=temp->next;

        newNode->next = temp->next;
        temp->next = newNode;
    }
}

int isEmpty(){
    return head == NULL;
}
void pop(){
    Node* temp = head;
    head= head->next;
    free(temp);
}

int main()
{
    head=create(5, 2);
    push(6,3);
    push(7,0);

    while(!isEmpty()){
        printf("%d ",peek());
        pop();        
    }
    return 0;
}