//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Define a structure to hold the data
struct Node {
    int data;
    struct Node* next;
};

// Function to add a new node at the beginning of the linked list
void addNode(struct Node** head_ref, int new_data) {
    // Allocate memory for the new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    
    // Initialize the new node
    new_node->data = new_data;
    new_node->next = *head_ref;
    
    // Move the head of the linked list to the new node
    *head_ref = new_node;
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* current = head;
    
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    
    printf("\n");
}

// Function to free the memory allocated for the linked list
void freeList(struct Node* head) {
    struct Node* current = head;
    
    while (current!= NULL) {
        struct Node* temp = current->next;
        free(current);
        current = temp;
    }
}

int main() {
    // Create a new linked list
    struct Node* head = NULL;
    
    // Add some nodes to the linked list
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 4);
    addNode(&head, 5);
    
    // Display the linked list
    displayList(head);
    
    // Free the memory allocated for the linked list
    freeList(head);
    
    return 0;
}