//FormAI DATASET v1.0 Category: Memory management ; Style: complex
#include <stdio.h>
#include <stdlib.h>

// Define a struct for our custom linked list node
struct Node {
    int data;
    struct Node* next;
};

// Define a function to create a new node
struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if (node == NULL) {
        printf("Error: memory allocation failed for new node.\n");
        exit(1);
    }
    node->data = data;
    node->next = NULL;
    return node;
}

// Define a function to insert a new node at the beginning of the list
void insertNode(struct Node** head, int data) {
    struct Node* node = createNode(data);
    node->next = *head;
    *head = node;
}

// Define a function to delete a node from the list
void deleteNode(struct Node** head, int data) {
    struct Node* current = *head;
    struct Node* previous = NULL;
    while (current != NULL && current->data != data) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Error: item not found in list.\n");
        return;
    }
    if (previous == NULL) {
        *head = current->next;
    } else {
        previous->next = current->next;
    }
    free(current);
}

// Define a function to print the list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Initialize the head of our list to NULL
    struct Node* head = NULL;
    
    // Insert some nodes into the list
    insertNode(&head, 5);
    insertNode(&head, 10);
    insertNode(&head, 15);
    insertNode(&head, 20);
    
    // Print the list
    printf("Original list: ");
    printList(head);
    
    // Delete a node from the list
    deleteNode(&head, 15);
    
    // Print the list again
    printf("List after deleting 15: ");
    printList(head);
    
    // Free all memory allocated for the list
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    
    return 0;
}