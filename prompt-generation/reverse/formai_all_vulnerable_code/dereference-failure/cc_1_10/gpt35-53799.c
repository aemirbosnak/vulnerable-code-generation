//FormAI DATASET v1.0 Category: Linked list operations ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

// Define the structure for the Linked List Node
struct Node {
    int data;
    struct Node* next;
};

// Create a function to insert elements at the beginning of the list
void insert_beg(struct Node** head_ref, int new_data) {
    // Allocate memory for new node
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    // Assign the value to the new node 
    new_node->data = new_data;
    // Point the new node to the current head node
    new_node->next = (*head_ref);
    // Change the head to point to the new node as the new first element
    (*head_ref) = new_node;
}

// Create a function to insert elements at the end of the list
void insert_end(struct Node** head_ref, int new_data) {
    // Allocate memory for new node
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node* last = *head_ref;  // Create a temporary node pointer to move through the linked list
    // Assign the value to the new node 
    new_node->data = new_data;
    // Set the next of new node to NULL since it will be the last node
    new_node->next = NULL;
    // Check if the list is empty, if so make the new node as head node
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    // Traverse to the last node of the list
    while (last->next != NULL) {
        last = last->next;
    }
    // Point the last node to the new node
    last->next = new_node;
}

// Create a function to delete a given node from the linked list
void delete_node(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref;         // Create a temporary node pointer
    struct Node* prev;                     // Create a previous node pointer
    // If the head node contains the key to be deleted
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;            // Change the head to the next node
        free(temp);                        // Free the memory allocated for the deleted node
        return;
    }
    // Traverse the list until the node to be deleted is found
    while (temp != NULL && temp->data != key) {
        prev = temp;                      // Store the current node as the previous node
        temp = temp->next;                // Move to the next node
    }
    // If the node wasn't found in the list
    if (temp == NULL) {
        return;
    }
    // Remove the node from the linked list
    prev->next = temp->next;
    free(temp);                           // Free the memory allocated for the deleted node
}

// Create a function to print the linked list
void printList(struct Node* node) { 
    while (node != NULL) { 
        printf("%d ", node->data); 
        node = node->next; 
    } 
}

int main() {
    struct Node* head = NULL; // Start with an empty list

    // Add some elements to the linked list
    insert_end(&head, 6);
    insert_beg(&head, 7);
    insert_beg(&head, 1);
    insert_end(&head, 4);

    printf("Linked List : ");
    printList(head);           // Output: 1 7 6 4

    delete_node(&head, 6);     // Delete node with value 6

    printf("\nLinked List after deletion : ");
    printList(head);           // Output: 1 7 4

    return 0;
}