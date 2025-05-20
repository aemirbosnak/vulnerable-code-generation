//FormAI DATASET v1.0 Category: Linked list operations ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Define a function to create a new Node
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Define a function to insert a new Node at the beginning of the list
void insertAtBeginning(Node **head, int data)
{
    Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Define a function to insert a new Node at the end of the list
void insertAtEnd(Node **head, int data)
{
    Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    Node *current = *head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
}

// Define a function to insert a new Node at a particular position in the list
void insertAtPosition(Node **head, int data, int position)
{
    if (position < 1)
    {
        printf("Invalid position\n");
        return;
    }
    if (position == 1)
    {
        insertAtBeginning(head, data);
        return;
    }
    Node *newNode = createNode(data);
    Node *previous = *head;
    int count = 1;
    while (count < position - 1 && previous != NULL)
    {
        previous = previous->next;
        count++;
    }
    if (previous == NULL)
    {
        printf("Invalid position\n");
        return;
    }
    newNode->next = previous->next;
    previous->next = newNode;
}

// Define a function to delete a Node from the list based on its value
void deleteByValue(Node **head, int data)
{
    if (*head == NULL) // Empty list
        return;
    Node *current = *head;
    Node *previous = NULL;
    while (current != NULL && current->data != data)
    {
        previous = current;
        current = current->next;
    }
    if (current == NULL) // Data not found
        return;
    if (previous == NULL) // Data found at the beginning
        *head = current->next;
    else
        previous->next = current->next;
    free(current);
}

// Define a function to delete a Node from the list based on its position
void deleteByPosition(Node **head, int position)
{
    if (*head == NULL) // Empty list
        return;
    if (position == 1) // Delete the first Node
    {
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    Node *current = *head;
    Node *previous = NULL;
    int count = 1;
    while (count < position && current != NULL)
    {
        previous = current;
        current = current->next;
        count++;
    }
    if (current == NULL) // Invalid position
        return;
    previous->next = current->next;
    free(current);
}

// Define a function to display the contents of the list
void printList(Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    Node *head = NULL;
    insertAtEnd(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtEnd(&head, 30);
    insertAtPosition(&head, 15, 2);
    insertAtPosition(&head, 25, 4);
    insertAtPosition(&head, 35, 6);
    printf("Original list: ");
    printList(head);
    deleteByValue(&head, 25);
    deleteByPosition(&head, 4);
    printf("Modified list: ");
    printList(head);
    return 0;
}