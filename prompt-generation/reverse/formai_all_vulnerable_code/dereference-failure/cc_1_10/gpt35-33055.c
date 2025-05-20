//FormAI DATASET v1.0 Category: Linked list operations ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
 
// Create a node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to add a node at the beginning of the list
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
 
// Function to add a node after a given node in the list
void insertAfter(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("The given previous node cannot be NULL");
        return;
    }
 
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}
 
// Function to add a node at the end of the list
void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
 
    while (last->next != NULL) {
        last = last->next;
    }
 
    last->next = new_node;
    return;
}
 
// Function to delete a node with the given key value
void deleteNode(struct Node** head_ref, int key) {
    struct Node *temp = *head_ref, *prev;

    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Function to print the linked list
void printList(struct Node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}
 
// Main function
int main() {
    struct Node* head = NULL;

    // Add nodes to the beginning of the list
    push(&head, 5);
    push(&head, 2);
    push(&head, 9);
    push(&head, 1);

    // Insert node after a given node in the list
    insertAfter(head->next, 7);

    // Add nodes to the end of the list
    append(&head, 8);
    append(&head, 4);

    // Delete a node from the list
    deleteNode(&head, 9);

    // Print the linked list
    printList(head);

    return 0;
}