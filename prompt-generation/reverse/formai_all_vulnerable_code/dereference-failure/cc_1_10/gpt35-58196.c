//FormAI DATASET v1.0 Category: Memory management ; Style: modular
#include<stdio.h>
#include<stdlib.h>

typedef struct node {  // Define a structure for the node
    int data;
    struct node* next;
} node;

// Declare the functions
node* createNode(int data);
void insertNode(node** head, int data);
void deleteNode(node** head, int data);
void printList(node* head);

int main() {
    // Initialize an empty linked list
    node* head = NULL;

    // Insert some nodes
    insertNode(&head, 5);
    insertNode(&head, 10);
    insertNode(&head, 15);

    // Print the list before deletion
    printf("List before deletion: ");
    printList(head);

    // Delete a node from the list
    deleteNode(&head, 10);

    // Print the list after deletion
    printf("List after deletion: ");
    printList(head);

    return 0;
}

// Function to create a new node
node* createNode(int data) {
    node* newNode = (node*) malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertNode(node** head, int data) {
    node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to delete a node from the list
void deleteNode(node** head, int data) {
    node* current = *head, *prev;

    // If the head node itself holds the key to be deleted
    if (current != NULL && current->data == data) {
        *head = current->next;
        free(current);
        return;
    }

    // Search for the key to be deleted, keep track of the previous node as we need to change 'prev->next'
    while (current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }

    // If key was not present in linked list
    if (current == NULL)
        return;

    // Unlink the node from linked list
    prev->next = current->next;
    free(current);
}

// Function to print the list
void printList(node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}