//FormAI DATASET v1.0 Category: Memory management ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Define struct for linked list
typedef struct node {
    int value;
    struct node* next;
} Node;

// Define function to allocate memory for new node
Node* create_node(int value) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error: unable to allocate memory\n");
        exit(1);
    }
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

int main() {
    // Define variables
    Node* head = NULL;
    Node* current = NULL;
    int i;

    // Allocate memory for first node
    head = create_node(0);
    current = head;

    // Fill linked list with values 1-9
    for (i = 1; i <= 9; i++) {
        current->next = create_node(i);
        current = current->next;
    }

    // Print out values in linked list
    current = head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");

    // Free allocated memory
    current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}