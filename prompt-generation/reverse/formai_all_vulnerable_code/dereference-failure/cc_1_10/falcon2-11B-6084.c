//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

// Define a structure for the linked list node
typedef struct Node
{
    int data;
    struct Node* next;
} Node;

// Function to create a new node with the given data
Node* createNode(int data)
{
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the linked list
Node* insertAtBeginning(Node* head, int data)
{
    Node* newNode = createNode(data);
    if (head == NULL)
    {
        head = newNode;
        return head;
    }
    newNode->next = head;
    head = newNode;
    return head;
}

// Function to insert a node at the end of the linked list
Node* insertAtEnd(Node* head, int data)
{
    Node* newNode = createNode(data);
    if (head == NULL)
    {
        head = newNode;
        return head;
    }
    Node* current = head;
    while (current->next!= NULL)
    {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// Function to delete a node from the linked list
Node* deleteNode(Node* head, int data)
{
    Node* current = head;
    Node* prev = NULL;
    while (current!= NULL && current->data!= data)
    {
        prev = current;
        current = current->next;
    }
    if (current == NULL)
    {
        return head;
    }
    if (prev == NULL)
    {
        head = current->next;
        free(current);
        return head;
    }
    prev->next = current->next;
    free(current);
    return head;
}

// Function to display the elements of the linked list
void display(Node* head)
{
    Node* current = head;
    while (current!= NULL)
    {
        printf(" %d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    Node* head = NULL;

    // Insert elements at the beginning of the linked list
    insertAtBeginning(head, 1);
    insertAtBeginning(head, 2);
    insertAtBeginning(head, 3);

    // Insert elements at the end of the linked list
    insertAtEnd(head, 4);
    insertAtEnd(head, 5);
    insertAtEnd(head, 6);

    // Display the elements of the linked list
    printf("Linked List: ");
    display(head);

    // Delete a node from the linked list
    deleteNode(head, 2);

    // Display the updated elements of the linked list
    printf("Updated Linked List: ");
    display(head);

    return 0;
}