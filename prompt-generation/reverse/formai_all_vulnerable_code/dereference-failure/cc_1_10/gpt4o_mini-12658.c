//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
struct Node* createNode(int data);
void append(struct Node** head_ref, int new_data);
void displayList(struct Node* node);
void deleteNode(struct Node** head_ref, int key);
void freeList(struct Node** head_ref);

// Main function
int main() {
    struct Node* head = NULL;

    // Append elements to the list
    append(&head, 5);
    append(&head, 10);
    append(&head, 15);
    append(&head, 20);
    append(&head, 25);
    
    // Display the list
    printf("Linked List: ");
    displayList(head);
    
    // Deleting a node
    printf("Deleting node with value 15.\n");
    deleteNode(&head, 15);
    
    // Display the list again
    printf("Linked List after deletion: ");
    displayList(head);

    // Free the list
    freeList(&head);
    return 0;
}

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Append a new node at the end
void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = createNode(new_data);
    struct Node* last = *head_ref;
    
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    
    while (last->next != NULL) {
        last = last->next;
    }
    
    last->next = new_node;
}

// Display the linked list
void displayList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Delete a node by key
void deleteNode(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref;
    struct Node* prev = NULL;

    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next; // Change the head
        free(temp);  // Free old head
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return; // Key not found

    prev->next = temp->next; // Unlink the node from linked list
    free(temp);  // Free memory
}

// Free the linked list
void freeList(struct Node** head_ref) {
    struct Node* current = *head_ref;
    struct Node* next;

    while (current != NULL) {
        next = current->next; // Store next node
        free(current);        // Free current node
        current = next;       // Move to next node
    }

    *head_ref = NULL; // Set head to NULL
}