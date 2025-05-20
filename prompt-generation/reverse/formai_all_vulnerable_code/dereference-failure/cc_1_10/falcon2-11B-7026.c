//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* createNode(int data)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct node** head, int data)
{
    struct node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct node** head, int data)
{
    struct node* newNode = createNode(data);
    struct node* current = *head;
    while (current->next!= NULL)
        current = current->next;
    current->next = newNode;
}

void deleteNode(struct node** head, int data)
{
    struct node* temp = *head;
    struct node* prev = NULL;
    if (temp!= NULL && temp->data == data)
    {
        *head = temp->next;
        free(temp);
    }
    else
    {
        while (temp!= NULL && temp->data!= data)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL)
            return;
        prev->next = temp->next;
        free(temp);
    }
}

void printList(struct node* head)
{
    struct node* temp = head;
    while (temp!= NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct node* head = NULL;

    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 4);
    insertAtBeginning(&head, 5);

    printList(head);
    printf("\n");

    deleteNode(&head, 4);
    deleteNode(&head, 3);

    printList(head);
    printf("\n");

    return 0;
}