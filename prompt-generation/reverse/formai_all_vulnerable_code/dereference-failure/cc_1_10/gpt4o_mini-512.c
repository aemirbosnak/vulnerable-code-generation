//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

// Define a structure for the Linked List Node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1); // Exit if memory allocation fails
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void append(struct Node** headRef, int value) {
    struct Node* newNode = createNode(value);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    
    struct Node* last = *headRef;
    while (last->next != NULL) last = last->next;
    last->next = newNode;
}

// Function to delete a node by value from the linked list
void deleteNode(struct Node** headRef, int value) {
    struct Node* current = *headRef;
    struct Node* previous = NULL;

    // Handle the case where the node to delete is the head
    if (current != NULL && current->data == value) {
        *headRef = current->next; // Change head
        free(current); // Free old head
        return;
    }

    // Search for the node to delete
    while (current != NULL && current->data != value) {
        previous = current;
        current = current->next;
    }

    // If value was not found in the list
    if (current == NULL) return;

    // Unlink the node from the linked list
    previous->next = current->next;
    free(current); // Free memory
}

// Function to display the linked list
void displayList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Function to free the linked list
void freeList(struct Node* node) {
    struct Node* temp;
    while (node != NULL) {
        temp = node;
        node = node->next;
        free(temp);
    }
}

// Main function to execute the linked list operations
int main() {
    struct Node* head = NULL;
    
    printf("Linked List Operations:\n");
    
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 40);
    
    printf("Current List: ");
    displayList(head);
    
    printf("Deleting 20 from the list...\n");
    deleteNode(&head, 20);
    
    printf("List after deletion: ");
    displayList(head);
    
    printf("Appending 50 and 60...\n");
    append(&head, 50);
    append(&head, 60);
    
    printf("Final List: ");
    displayList(head);
    
    // Clear the list before exiting
    freeList(head);
    
    return 0;
}