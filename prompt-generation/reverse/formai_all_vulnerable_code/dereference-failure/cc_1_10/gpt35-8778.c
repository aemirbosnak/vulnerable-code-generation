//FormAI DATASET v1.0 Category: Data structures visualization ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Define a node structure
struct Node {
    int data;
    struct Node* next;
};

// Define a function to insert a new node at the beginning of the linked list
void insertAtBeginning(struct Node** head_ref, int new_data) {
    // Allocate memory for the new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    
    // Set the data value of the new node
    new_node->data = new_data;
    
    // Set the next pointer of the new node to the current head of the linked list
    new_node->next = *head_ref;
    
    // Set the head of the linked list to the new node
    *head_ref = new_node;
}

// Define a function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    // Create an empty linked list
    struct Node* head = NULL;
    
    // Insert some nodes at the beginning of the linked list
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 4);
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);
    
    // Print the linked list
    printf("Linked List: ");
    printList(head);
    
    return 0;
}