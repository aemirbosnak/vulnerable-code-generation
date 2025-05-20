//FormAI DATASET v1.0 Category: Linked list operations ; Style: brave
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct Node
{
    int data;           // Data to be stored in the node
    struct Node* next;  // Pointer to next node in the list
};

// Function to create a new node with given data
struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(struct Node** headRef, int data)
{
    struct Node* newNode = createNode(data);
    newNode->next = *headRef;
    *headRef = newNode;
    printf("Node with data %d inserted at beginning of list.\n", data);
}

// Function to insert a new node at the end of the linked list
void insertAtEnd(struct Node** headRef, int data)
{
    struct Node* newNode = createNode(data);
    if (*headRef == NULL)
    {
        *headRef = newNode;
        printf("Node with data %d inserted at end of list.\n", data);
        return;
    }
    struct Node* current = *headRef;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
    printf("Node with data %d inserted at end of list.\n", data);
}

// Function to delete the first occurrence of a node with given data from the linked list
void deleteNode(struct Node** headRef, int data)
{
    if (*headRef == NULL)
    {
        printf("List is empty. Node with data %d could not be deleted.\n", data);
        return;
    }
    struct Node* current = *headRef;
    struct Node* prev = NULL;
    while (current != NULL && current->data != data)
    {
        prev = current;
        current = current->next;
    }
    if (current == NULL)
    {
        printf("Node with data %d not found in list. Could not be deleted.\n", data);
        return;
    }
    if (prev == NULL)
    {
        *headRef = current->next;
    }
    else
    {
        prev->next = current->next;
    }
    free(current);
    printf("Node with data %d deleted from list.\n", data);
}

// Function to display all nodes in the linked list
void displayList(struct Node* head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct Node* current = head;
    printf("List: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    struct Node* head = NULL;

    insertAtBeginning(&head, 10);
    insertAtEnd(&head, 20);
    insertAtBeginning(&head, 5);
    displayList(head);

    deleteNode(&head, 5);
    displayList(head);

    deleteNode(&head, 15);
    displayList(head);

    insertAtEnd(&head, 30);
    displayList(head);

    return 0;
}