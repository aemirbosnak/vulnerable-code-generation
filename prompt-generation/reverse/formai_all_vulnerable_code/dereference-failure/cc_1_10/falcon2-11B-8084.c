//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: enthusiastic
#include<stdio.h>

struct node
{
    int data;
    struct node* next;
};

struct node* head = NULL;

void insert(int data)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    
    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct node* temp = head;
        while(temp->next!= NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList()
{
    struct node* temp = head;
    while(temp!= NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    insert(1);
    insert(2);
    insert(3);
    printList();
    return 0;
}