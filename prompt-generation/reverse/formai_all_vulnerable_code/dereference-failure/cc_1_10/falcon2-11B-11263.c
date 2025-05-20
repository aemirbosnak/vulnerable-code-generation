//Falcon2-11B DATASET v1.0 Category: Binary Converter ; Style: Claude Shannon
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

node *head = NULL;

void addNode(int data)
{
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;

    if(head == NULL)
    {
        head = newnode;
    }
    else
    {
        node *temp = head;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void display(node *head)
{
    node *temp = head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int data;

    printf("Enter the data to be added: ");
    scanf("%d",&data);
    addNode(data);

    display(head);

    return 0;
}