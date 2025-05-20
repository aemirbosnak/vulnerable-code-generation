//FormAI DATASET v1.0 Category: Linked list operations ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// Define a structure for each node of the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the beginning of the linked list
void insertFirst(struct Node** head_ref, int new_data) {
    // Allocate memory for the new node
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    
    // Set the data and next pointer of the new node
    new_node->data = new_data;
    new_node->next = (*head_ref);
    
    // Set the head pointer to the new node
    (*head_ref) = new_node;
}

// Function to insert a node after a given node in the linked list
void insertAfter(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("Error: previous node cannot be NULL.");
        return;
    }
    
    // Allocate memory for the new node
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    
    // Set the data and next pointer of the new node
    new_node->data = new_data;
    new_node->next = prev_node->next;
    
    // Set the next pointer of the previous node to the new node
    prev_node->next = new_node;
}

// Function to insert a node at the end of the linked list
void insertLast(struct Node** head_ref, int new_data) {
    // Allocate memory for the new node
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node* last = *head_ref; // Create a temporary pointer to traverse the list
    
    // Set the data and next pointer of the new node
    new_node->data = new_data;
    new_node->next = NULL;
    
    // If the list is empty, set the head pointer to the new node
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    
    // Traverse to the last node of the linked list
    while (last->next != NULL) {
        last = last->next;
    }
    
    // Set the next pointer of the last node to the new node
    last->next = new_node;
}

// Function to delete a node with a given key from the linked list
void deleteNode(struct Node** head_ref, int key) {
    // Create temporary pointers to traverse the list
    struct Node* temp = *head_ref;
    struct Node* prev = NULL;
    
    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next; // Changed head
        free(temp); // Free old head
        return;
    }
    
    // Find the node with the key to be deleted
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    
    // If key was not present in linked list
    if (temp == NULL) {
        printf("Error: key not found in linked list.");
        return;
    }
    
    // Unlink the node from the linked list
    prev->next = temp->next;
    free(temp); // Free memory
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct Node* head = NULL;
    
    // Insert nodes at the beginning of the linked list
    insertFirst(&head, 1);
    insertFirst(&head, 2);
    insertFirst(&head, 3);
    
    printf("Linked list after inserting at beginning: ");
    printList(head);
    
    // Insert nodes after a given node in the linked list
    insertAfter(head->next, 4);
    insertAfter(head->next->next, 5);
    
    printf("Linked list after inserting after a given node: ");
    printList(head);
    
    // Insert nodes at the end of the linked list
    insertLast(&head, 6);
    insertLast(&head, 7);
    
    printf("Linked list after inserting at end: ");
    printList(head);
    
    // Delete nodes from the linked list
    deleteNode(&head, 3);
    deleteNode(&head, 6);
    
    printf("Linked list after deleting nodes: ");
    printList(head);
    
    return 0;
}