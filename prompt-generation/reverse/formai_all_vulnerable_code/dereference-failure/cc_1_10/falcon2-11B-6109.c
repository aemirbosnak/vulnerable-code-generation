//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

// Node Structure
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

// Function to insert a new node at the beginning of the list
Node* insertAtBeginning(Node** head, int data)
{
    Node* newNode = createNode(data);
    newNode->next = (*head);
    *head = newNode;
    return (*head);
}

// Function to insert a new node at the end of the list
Node* insertAtEnd(Node** head, int data)
{
    Node* newNode = createNode(data);
    Node* current = *head;
    while (current->next!= NULL)
        current = current->next;
    current->next = newNode;
    return (*head);
}

// Function to delete a node from the list
void deleteNode(Node** head, int data)
{
    Node* temp = *head;
    if (temp->data == data)
    {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp->next!= NULL && temp->next->data!= data)
        temp = temp->next;
    if (temp->next == NULL)
        return;
    Node* temp2 = temp->next;
    temp->next = temp2->next;
    free(temp2);
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

int main()
{
    Node* head = NULL;
    head = insertAtBeginning(&head, 5);
    head = insertAtBeginning(&head, 10);
    head = insertAtBeginning(&head, 15);
    head = insertAtEnd(&head, 20);
    head = insertAtEnd(&head, 25);
    printList(head);
    deleteNode(&head, 10);
    printList(head);
    return 0;
}