//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definition of a Node
typedef struct Node
{
    int data;
    struct Node* next;
} Node;

// Function to create a new Node
Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to print the linked list
void printList(Node* head)
{
    Node* temp = head;
    while (temp!= NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to insert a new element at the beginning of the linked list
Node* insertAtBeginning(Node** head, int data)
{
    Node* newNode = createNode(data);
    newNode->next = (*head);
    (*head) = newNode;
    return (*head);
}

// Function to insert a new element at the end of the linked list
Node* insertAtEnd(Node** head, int data)
{
    Node* newNode = createNode(data);
    Node* temp = *head;
    while (temp->next!= NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return *head;
}

// Function to delete a node from the linked list
Node* deleteNode(Node** head, int data)
{
    Node* temp = *head;
    Node* prev = NULL;
    while (temp!= NULL && temp->data!= data)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        return *head;
    }
    if (prev == NULL)
    {
        *head = temp->next;
        free(temp);
        return *head;
    }
    prev->next = temp->next;
    free(temp);
    return *head;
}

// Function to reverse the linked list
Node* reverseList(Node* head)
{
    Node* temp = head;
    Node* prev = NULL;
    Node* next = NULL;
    while (temp!= NULL)
    {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    head = prev;
    return head;
}

// Main function
int main()
{
    Node* head = NULL;
    head = insertAtBeginning(&head, 5);
    head = insertAtBeginning(&head, 4);
    head = insertAtBeginning(&head, 3);
    head = insertAtBeginning(&head, 2);
    head = insertAtBeginning(&head, 1);
    printf("Linked list before reversal: ");
    printList(head);
    head = reverseList(head);
    printf("Linked list after reversal: ");
    printList(head);
    return 0;
}