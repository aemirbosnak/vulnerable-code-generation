//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with provided data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to append a node at the end of the list
void appendNode(struct Node** head_ref, int new_data) {
    struct Node* new_node = createNode(new_data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    struct Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

// Function to print the entire list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Function to delete a specific node by value
void deleteNode(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref;
    struct Node* prev = NULL;

    // If the head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next; // Changed head
        free(temp);             // free old head
        return;
    }

    // Search for the key to be deleted
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL) {
        printf("Value %d not found in the list.\n", key);
        return;
    }

    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp); // Free memory
}

// Function to reverse the linked list
void reverseList(struct Node** head_ref) {
    struct Node* prev = NULL;
    struct Node* current = *head_ref;
    struct Node* next = NULL;
    
    while (current != NULL) {
        next = current->next; // Store next node
        current->next = prev; // Reverse current node's pointer
        prev = current;       // Move pointers one position ahead
        current = next;
    }
    *head_ref = prev; // Change head reference to new first node
}

// Helper function to free the list
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Main function to demonstrate list operations
int main() {
    struct Node* head = NULL;

    // Append nodes to the list
    appendNode(&head, 10);
    appendNode(&head, 20);
    appendNode(&head, 30);
    appendNode(&head, 40);
    
    printf("Current Linked List: ");
    printList(head);

    // Delete a node
    printf("Deleting node with value 20...\n");
    deleteNode(&head, 20);
    printf("Updated Linked List: ");
    printList(head);

    // Reverse the linked list
    printf("Reversing the Linked List...\n");
    reverseList(&head);
    printf("Reversed Linked List: ");
    printList(head);

    // Attempt to delete a non-existent node
    printf("Attempting to delete a non-existent value 50...\n");
    deleteNode(&head, 50); // This should show an error message

    // Free the list
    freeList(head);
    head = NULL;

    printf("All nodes freed. Exiting...\n");
    return 0;
}