//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>

#define MAX 5

typedef struct
{
    int data;
    struct node *next;
}node;

node *front=NULL,*rear=NULL;

void enqueue(int x)
{
    node *newnode=(node*)malloc(sizeof(node));
    newnode->data=x;
    newnode->next=NULL;
    if(front==NULL)
        front=rear=newnode;
    else
        rear->next=newnode;
    rear=newnode;
}

void dequeue()
{
    if(front==NULL)
        printf("\nUnderflow");
    else
    {
        printf("\n%d is deleted",front->data);
        node *temp=front;
        front=front->next;
        free(temp);
    }
}

void display()
{
    if(front==NULL)
        printf("\nEmpty");
    else
    {
        printf("\nQueue elements are:");
        node *temp=front;
        while(temp!=NULL)
        {
            printf("\n%d",temp->data);
            temp=temp->next;
        }
    }
}

void main()
{
    int choice;
    while(1)
    {
        printf("\n\n\t\tMENU");
        printf("\n1.Enqueue");
        printf("\n2.Dequeue");
        printf("\n3.Display");
        printf("\n4.Exit");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter the element to be inserted:");
                int x;
                scanf("%d",&x);
                enqueue(x);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("\nInvalid choice");
        }
    }
}