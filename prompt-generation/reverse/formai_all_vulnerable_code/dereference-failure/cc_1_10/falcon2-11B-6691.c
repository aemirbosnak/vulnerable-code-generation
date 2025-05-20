//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}node;

node* createNode(int data)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNode(node** head_ref, int data)
{
    node* newNode = createNode(data);
    newNode->next = (*head_ref);
    (*head_ref) = newNode;
}

void deleteNode(node** head_ref)
{
    if (*head_ref == NULL)
        return;
    node* temp = *head_ref;
    *head_ref = (*head_ref)->next;
    free(temp);
}

void display(node* head)
{
    while (head!= NULL)
    {
        printf("%d ",head->data);
        head = head->next;
    }
}

int main()
{
    node* head = NULL;
    insertNode(&head, 10);
    insertNode(&head, 20);
    insertNode(&head, 30);
    display(head);
    printf("\n");
    deleteNode(&head);
    display(head);
    printf("\n");
    return 0;
}