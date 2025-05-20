//FormAI DATASET v1.0 Category: Memory management ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// Struct for the node of the linked list
struct node {
    int data;           // Data stored in the node
    struct node* next;  // Pointer to the next node
};

// Function to print the linked list
void printList(struct node* head) {
    struct node* current = head;
    while(current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Allocate memory for the first node of the linked list
    struct node* head = (struct node*) malloc(sizeof(struct node));
    if(head == NULL) {
        printf("Memory allocation failed. Exiting...");
        exit(1);
    }

    // Initialize the first node and set its data to 0
    head->data = 0;
    head->next = NULL;

    // Add two more nodes to the linked list
    struct node* second = (struct node*) malloc(sizeof(struct node));
    if(second == NULL) {
        printf("Memory allocation failed. Exiting...");
        exit(1);
    }
    second->data = 1;
    second->next = NULL;
    head->next = second;

    struct node* third = (struct node*) malloc(sizeof(struct node));
    if(third == NULL) {
        printf("Memory allocation failed. Exiting...");
        exit(1);
    }
    third->data = 2;
    third->next = NULL;
    second->next = third;

    // Print the linked list
    printf("Linked list before deletion: ");
    printList(head);

    // Delete the second node of the linked list
    struct node* temp = second;
    head->next = third;
    free(temp);

    // Print the linked list after deletion
    printf("Linked list after deletion: ");
    printList(head);

    // Deallocate all memory allocated for the linked list
    free(head);
    free(third);

    return 0;
}