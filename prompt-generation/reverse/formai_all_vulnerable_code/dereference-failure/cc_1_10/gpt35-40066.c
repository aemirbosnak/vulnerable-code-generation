//FormAI DATASET v1.0 Category: Linked list operations ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Create a Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to add a node at the end of the linked list
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

// Function to add a node at the beginning of the linked list
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    new_node->data = new_data;
    new_node->next = (*head_ref);

    (*head_ref) = new_node;
}

// Function to insert a node after a specific node
void insert_after(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    new_node->data = new_data;
    new_node->next = prev_node->next;

    prev_node->next = new_node;
}

// Function to delete a node from the linked list
void delete_node(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref;
    struct Node* prev = NULL;

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
        printf("Node with the given key does not exist\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Function to print the linked list
void print_list(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

// Main function to test the linked list operations
int main() {
    struct Node* head = NULL;

    // Add nodes to the linked list
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    push(&head, 0);
    insert_after(head->next, 1);

    // Delete a node from the linked list
    delete_node(&head, 2);

    // Print the linked list
    print_list(head);

    return 0;
}