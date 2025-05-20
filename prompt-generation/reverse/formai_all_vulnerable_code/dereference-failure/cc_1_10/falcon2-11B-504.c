//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct node *temp = head;
        while(temp->next!= NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void traverseList()
{
    struct node *temp = head;
    while(temp!= NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int search(int data)
{
    struct node *temp = head;
    while(temp!= NULL)
    {
        if(temp->data == data)
        {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int main()
{
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    traverseList();
    printf("Search for 20? %d\n", search(20));
    return 0;
}