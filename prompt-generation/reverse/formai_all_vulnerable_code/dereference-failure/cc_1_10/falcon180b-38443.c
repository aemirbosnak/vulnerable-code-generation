//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: modular
#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct node
{
    int data;
    struct node *next;
}node;

node *front=NULL,*rear=NULL;

void enqueue(int data)
{
    node *temp=rear;
    rear=(node*)malloc(sizeof(node));
    rear->data=data;
    rear->next=NULL;
    if(front==NULL)
        front=rear;
    else
        temp->next=rear;
}

void dequeue()
{
    node *temp=front;
    if(front==NULL)
        printf("\nQueue is empty");
    else if(front==rear)
        front=rear=NULL;
    else
        front=front->next;
    free(temp);
}

void display()
{
    node *temp=front;
    if(front==NULL)
        printf("\nQueue is empty");
    else
    {
        printf("\nElements in the queue are: ");
        while(temp!=rear)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("%d",temp->data);
    }
}

int main()
{
    int ch;
    while(1)
    {
        printf("\nEnter 1 to enqueue an element");
        printf("\nEnter 2 to dequeue an element");
        printf("\nEnter 3 to display the elements in the queue");
        printf("\nEnter 0 to exit");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                int data;
                printf("\nEnter the element to be enqueued: ");
                scanf("%d",&data);
                enqueue(data);
                break;
            }
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 0:
                exit(0);
            default:
                printf("\nInvalid choice");
        }
    }
    return 0;
}