//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: automated
#include <stdio.h>
#include <stdlib.h>

// Define a custom data structure
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Create a linked list of nodes
Node *create_linked_list(int size) {
    Node *head = NULL;
    Node *current = NULL;

    for (int i = 0; i < size; i++) {
        Node *new_node = malloc(sizeof(Node));
        new_node->data = i;
        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
            current = new_node;
        } else {
            current->next = new_node;
            current = current->next;
        }
    }

    return head;
}

// Print the linked list
void print_linked_list(Node *head) {
    Node *current = head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

// Free the linked list
void free_linked_list(Node *head) {
    Node *current = head;
    Node *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

// Main function
int main() {
    // Create a linked list of 10 nodes
    Node *head = create_linked_list(10);

    // Print the linked list
    print_linked_list(head);

    // Free the linked list
    free_linked_list(head);

    return 0;
}