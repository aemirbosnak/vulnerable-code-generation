//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: innovative
#include <stdio.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *head = NULL;

void insert_element(int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;

    if(head == NULL)
    {
        head = temp;
        return;
    }

    Node *ptr = head;
    while(ptr->next!= NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = temp;
}

void delete_element(int data)
{
    Node *temp = head;
    Node *prev = NULL;

    while(temp!= NULL && temp->data!= data)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL)
    {
        return;
    }

    if(prev == NULL)
    {
        head = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }

    free(temp);
}

void traverse_list()
{
    Node *temp = head;
    while(temp!= NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    insert_element(10);
    insert_element(20);
    insert_element(30);
    insert_element(40);
    insert_element(50);

    printf("List before deleting: ");
    traverse_list();

    delete_element(40);

    printf("\nList after deleting 40: ");
    traverse_list();

    return 0;
}