//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node
{
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(Node** head_ref, int data)
{
    Node* newNode = createNode(data);
    newNode->next = (*head_ref);
    *head_ref = newNode;
}

// Function to insert a new node at the end of the linked list
void insertAtEnd(Node** head_ref, int data)
{
    Node* newNode = createNode(data);
    Node* current = *head_ref;
    while (current->next!= NULL)
        current = current->next;
    current->next = newNode;
}

// Function to delete a node from the linked list
void deleteNode(Node** head_ref, int data)
{
    Node* current = *head_ref;
    Node* prev = NULL;
    while (current!= NULL && current->data!= data)
    {
        prev = current;
        current = current->next;
    }

    if (current == NULL)
        return;

    if (prev == NULL)
        *head_ref = current->next;
    else
        prev->next = current->next;
    free(current);
}

// Function to reverse the linked list
void reverse(Node** head_ref)
{
    Node* current = *head_ref;
    Node* prev = NULL;
    Node* next = NULL;

    while (current!= NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head_ref = prev;
}

// Function to print the linked list
void printList(Node* head)
{
    Node* current = head;
    while (current!= NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main function
int main()
{
    Node* head = NULL;
    insertAtBeginning(&head, 5);
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 15);
    insertAtEnd(&head, 20);

    printList(head);

    printf("Deleting node with data 10\n");
    deleteNode(&head, 10);
    printList(head);

    printf("Reversing the linked list\n");
    reverse(&head);
    printList(head);

    printf("Deleting node with data 5\n");
    deleteNode(&head, 5);
    printList(head);

    return 0;
}