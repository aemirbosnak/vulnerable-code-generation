//FormAI DATASET v1.0 Category: Linked list operations ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

// Define the structure of the node
typedef struct node
{
    int data;
    struct node *next;
} Node;

// Initialize the linked list by pointing head to NULL
Node *head = NULL;

// Function to insert a node at the end of the linked list
void insertNode(int data)
{
    // Allocate memory for new node
    Node *newNode = (Node *)malloc(sizeof(Node));

    // Initialize data and next pointer of the new node
    newNode->data = data;
    newNode->next = NULL;

    // Check if linked list is empty
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    // Traverse the linked list to reach the last node
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    // Add the new node after the last node
    temp->next = newNode;
}

// Function to delete a node with given data from the linked list
void deleteNode(int data)
{
    // Check if linked list is empty
    if (head == NULL)
        return;

    // Check if the node to be deleted is the first node
    if (head->data == data)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
        return;
    }

    // Traverse the linked list to reach the node before the node to be deleted
    Node *temp = head;
    while (temp->next != NULL && temp->next->data != data)
    {
        temp = temp->next;
    }

    // Check if node with given data exists
    if (temp->next == NULL)
        return;

    // Remove the node with given data
    Node *deleteNode = temp->next;
    temp->next = temp->next->next;
    free(deleteNode);
}

// Function to display the linked list
void displayList()
{
    // Check if linked list is empty
    if (head == NULL)
    {
        printf("Linked list is empty!\n");
        return;
    }

    // Traverse the linked list to print each node
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    // Insert nodes into the linked list
    insertNode(10);
    insertNode(20);
    insertNode(30);
    insertNode(40);

    // Display the linked list
    printf("Original Linked List: ");
    displayList();

    // Delete nodes from the linked list
    deleteNode(30);

    // Display the updated linked list
    printf("Updated Linked List: ");
    displayList();

    return 0;
}