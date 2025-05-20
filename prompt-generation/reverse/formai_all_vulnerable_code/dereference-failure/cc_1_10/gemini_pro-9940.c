//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct node {
    int data;
    struct node *next;
} Node;

// Linked list operations
void insert(Node **head, int data);
void delete(Node **head, int data);
void search(Node *head, int data);
void print(Node *head);
void reverse(Node **head);

// Main function
int main() {
    // Create an empty linked list
    Node *head = NULL;

    // Insert some data
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);

    // Print the linked list
    printf("Original Linked list: ");
    print(head);

    // Delete a node
    delete(&head, 2);

    // Print the linked list
    printf("After deleting 2: ");
    print(head);

    // Search a node
    search(head, 3);

    // Reverse the linked list
    reverse(&head);

    // Print the linked list
    printf("Reversed Linked list: ");
    print(head);

    return 0;
}

// Insert a node at the beginning of the linked list
void insert(Node **head, int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

// Delete a node from the linked list
void delete(Node **head, int data) {
    Node *current = *head;
    Node *prev = NULL;

    // Find the node to be deleted
    while (current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }

    // If the node is not found, do nothing
    if (current == NULL) {
        return;
    }

    // If the node is the first node, update the head
    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }

    // Free the deleted node
    free(current);
}

// Search a node in the linked list
void search(Node *head, int data) {
    Node *current = head;

    // Find the node
    while (current != NULL && current->data != data) {
        current = current->next;
    }

    // If the node is found, print its data
    if (current != NULL) {
        printf("Node found: %d\n", current->data);
    } else {
        printf("Node not found\n");
    }
}

// Print the linked list
void print(Node *head) {
    Node *current = head;

    // Print the data of each node
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

// Reverse the linked list
void reverse(Node **head) {
    Node *current = *head;
    Node *prev = NULL;
    Node *next = NULL;

    // Reverse the linked list
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}