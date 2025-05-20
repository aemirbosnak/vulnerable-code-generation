//FormAI DATASET v1.0 Category: Linked list operations ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the beginning of a linked list
void insertBegin(struct Node** head_ref, int new_data) {
    // Allocate memory for the new node
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    // Set the data for the new node
    new_node->data = new_data;
    // Set the next node in the list as the current head node
    new_node->next = (*head_ref);
    // Set the new node as the head node
    (*head_ref) = new_node;
}

// Function to insert a new node at the end of a linked list
void insertEnd(struct Node** head_ref, int new_data) {
    // Allocate memory for the new node
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node *last = *head_ref;  /* used in step 5 */
    // Set the data for the new node
    new_node->data = new_data;
    // Set the next node in the list as NULL as this is the new tail node
    new_node->next = NULL;
    // If the list is empty, the new node becomes the head node
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    // Traverse to the end of the linked list
    while (last->next != NULL)
        last = last->next;
    // Set the new node as the next node after the tail node
    last->next = new_node;
}

// Function to delete the first occurrence of a node with a given key
void deleteNode(struct Node **head_ref, int key) {
    // Store head node
    struct Node* temp = *head_ref, *prev;

    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;   // Changed head
        free(temp);               // free old head
        return;
    }

    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL)
        return;

    // Unlink the node from linked list
    prev->next = temp->next;

    free(temp);  // Free memory
}

// Function to print all nodes in a linked list
void printList(struct Node *node) {
    printf("Linked List: ");
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    // Initialize an empty linked list
    struct Node* head = NULL;
    // Insert nodes at the beginning
    insertBegin(&head, 10);
    insertBegin(&head, 20);
    insertBegin(&head, 30);
    // Print the linked list
    printList(head);
    // Insert nodes at the end
    insertEnd(&head, 40);
    insertEnd(&head, 50);
    insertEnd(&head, 60);
    // Print the linked list
    printList(head);
    // Delete a node from the linked list
    deleteNode(&head, 30);
    // Print the linked list
    printList(head);

    return 0;
}