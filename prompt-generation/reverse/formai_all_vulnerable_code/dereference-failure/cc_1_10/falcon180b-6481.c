//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#define MAX 100

struct node
{
    int num;
    struct node *next;
};

struct node *head=NULL;

void push(int x)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->num=x;
    newnode->next=NULL;
    if(head==NULL)
        head=newnode;
    else
    {
        struct node *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}

void pop()
{
    struct node *temp=head;
    if(head==NULL)
        printf("\nStack is empty");
    else if(head->next==NULL)
    {
        printf("\n%d is popped from the stack",head->num);
        free(head);
        head=NULL;
    }
    else
    {
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        printf("\n%d is popped from the stack",temp->next->num);
        free(temp->next);
        temp->next=NULL;
    }
}

void display()
{
    struct node *temp=head;
    if(head==NULL)
        printf("\nStack is empty");
    else
    {
        printf("\nThe elements in the stack are:");
        while(temp!=NULL)
        {
            printf("\n%d",temp->num);
            temp=temp->next;
        }
    }
}

int main()
{
    int choice,x;
    do
    {
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter the element to be pushed:");
                scanf("%d",&x);
                push(x);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice");
        }
    }while(choice!=4);
    return 0;
}