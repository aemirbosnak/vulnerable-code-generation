//FormAI DATASET v1.0 Category: Linked list operations ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a node struct
typedef struct node {
    int data;
    struct node *next;
} Node;

// Declare helper functions
void append(Node **head, int data);
bool search(Node *head, int data);
void traverse(Node *head);
void delete(Node **head, int data);

int main() {
    // Create an empty linked list
    Node *head = NULL;
    
    // Append some values to the list
    append(&head, 5);
    append(&head, 10);
    append(&head, 15);
    append(&head, 20);
    
    // Print the list
    printf("The linked list contains:");
    traverse(head);
    
    // Search for a value in the list
    int value = 10;
    if (search(head, value)) {
        printf("%d is in the linked list.\n", value);
    } else {
        printf("%d is not in the linked list.\n", value);
    }
    
    // Delete a value from the list
    value = 15;
    delete(&head, value);
    printf("After deleting %d, the linked list contains:", value);
    traverse(head);
    
    return 0;
}

// Append a node to the end of the list
void append(Node **head, int data) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    
    if (*head == NULL) {
        *head = new_node;
    } else {
        Node *current_node = *head;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
}

// Search for a value in the list
bool search(Node *head, int data) {
    Node *current_node = head;
    while (current_node != NULL) {
        if (current_node->data == data) {
            return true;
        }
        current_node = current_node->next;
    }
    return false;
}

// Traverse the list and print the values
void traverse(Node *head) {
    Node *current_node = head;
    while (current_node != NULL) {
        printf(" %d", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

// Delete a node with the given value from the list
void delete(Node **head, int data) {
    Node *current_node = *head;
    Node *previous_node = NULL;
    while (current_node != NULL) {
        if (current_node->data == data) {
            // Found the node to delete
            if (previous_node == NULL) {
                // Delete the first node
                *head = current_node->next;
            } else {
                previous_node->next = current_node->next;
            }
            free(current_node);
            return;
        }
        previous_node = current_node;
        current_node = current_node->next;
    }
}