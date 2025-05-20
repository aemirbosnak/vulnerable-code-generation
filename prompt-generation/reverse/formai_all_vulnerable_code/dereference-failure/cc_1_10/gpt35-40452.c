//FormAI DATASET v1.0 Category: Linked list operations ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// define the structure for the node
struct node
{
    int data;
    struct node* next;
};

// function to create a new node
struct node* createNode(int data)
{
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// function to insert a node at the beginning of the linked list
void insertAtBeginning(struct node** headRef, int data)
{
    struct node* newNode = createNode(data);
    newNode->next = *headRef;
    *headRef = newNode;
}

// function to insert a node at the end of the linked list
void insertAtEnd(struct node** headRef, int data)
{
    struct node* newNode = createNode(data);
    struct node* current = *headRef;
    if(current == NULL)
    {
        *headRef = newNode;
    }
    else
    {
        while(current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

// function to delete a node from the linked list
void deleteNode(struct node** headRef, int data)
{
    struct node* current = *headRef;
    struct node* previous = NULL;
    while(current != NULL && current->data != data)
    {
        previous = current;
        current = current->next;
    }
    if(current == NULL)
    {
        printf("Node not found in the linked list\n");
    }
    else if(previous == NULL)
    {
        *headRef = current->next;
        free(current);
    }
    else
    {
        previous->next = current->next;
        free(current);
    }
}

// function to print the linked list
void printLinkedList(struct node* head)
{
    printf("Linked List: ");
    while(head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    struct node* head = NULL;
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    printLinkedList(head);
    deleteNode(&head, 20);
    printLinkedList(head);
    deleteNode(&head, 50);
    return 0;
}