//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// Define a node
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Create a new node
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert a node at the beginning of the linked list
void insertAtBeginning(Node **head, int data)
{
    Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Insert a node at the end of the linked list
void insertAtEnd(Node **head, int data)
{
    Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Insert a node after a given node
void insertAfter(Node *prevNode, int data)
{
    if (prevNode == NULL)
    {
        printf("Previous node cannot be NULL");
        return;
    }
    Node *newNode = createNode(data);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

// Delete a node from the beginning of the linked list
void deleteFromBeginning(Node **head)
{
    if (*head == NULL)
    {
        printf("Linked list is empty");
        return;
    }
    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Delete a node from the end of the linked list
void deleteFromEnd(Node **head)
{
    if (*head == NULL)
    {
        printf("Linked list is empty");
        return;
    }
    Node *temp = *head;
    Node *prev = NULL;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    if (prev == NULL)
    {
        *head = NULL;
    }
    else
    {
        prev->next = NULL;
    }
    free(temp);
}

// Delete a node from the middle of the linked list
void deleteNode(Node **head, Node *node)
{
    if (*head == NULL || node == NULL)
    {
        printf("Linked list or node is empty");
        return;
    }
    if (*head == node)
    {
        deleteFromBeginning(head);
        return;
    }
    Node *temp = *head;
    Node *prev = NULL;
    while (temp != node)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Node not found");
        return;
    }
    prev->next = node->next;
    free(node);
}

// Reverse a linked list
void reverseLinkedList(Node **head)
{
    if (*head == NULL)
    {
        printf("Linked list is empty");
        return;
    }
    Node *prev = NULL;
    Node *current = *head;
    Node *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

// Print the linked list
void printLinkedList(Node *head)
{
    printf("Linked list: ");
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Main function
int main()
{
    // Create a linked list
    Node *head = NULL;

    // Insert some nodes into the linked list
    insertAtBeginning(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAfter(head->next, 15);

    // Print the linked list
    printLinkedList(head);

    // Delete a node from the beginning of the linked list
    deleteFromBeginning(&head);

    // Print the linked list
    printLinkedList(head);

    // Delete a node from the end of the linked list
    deleteFromEnd(&head);

    // Print the linked list
    printLinkedList(head);

    // Delete a node from the middle of the linked list
    deleteNode(&head, head->next);

    // Print the linked list
    printLinkedList(head);

    // Reverse the linked list
    reverseLinkedList(&head);

    // Print the linked list
    printLinkedList(head);

    return 0;
}