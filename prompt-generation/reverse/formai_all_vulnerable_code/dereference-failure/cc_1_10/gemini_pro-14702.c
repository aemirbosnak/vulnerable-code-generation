//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Define a custom data structure
typedef struct {
    int data;
    struct Node *next;
} Node;

// Create a linked list of nodes
Node *create_list() {
    Node *head = NULL;
    Node *current = NULL;

    for (int i = 0; i < 10; i++) {
        Node *new_node = (Node *)malloc(sizeof(Node));
        if (new_node == NULL) {
            fprintf(stderr, "Error allocating memory for node\n");
            exit(1);
        }

        new_node->data = i;
        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
            current = new_node;
        } else {
            current->next = new_node;
            current = new_node;
        }
    }

    return head;
}

// Print the linked list
void print_list(Node *head) {
    Node *current = head;

    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }

    printf("NULL\n");
}

// Free the linked list
void free_list(Node *head) {
    Node *current = head;
    Node *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    // Create a linked list
    Node *head = create_list();

    // Print the linked list
    print_list(head);

    // Free the linked list
    free_list(head);

    return 0;
}