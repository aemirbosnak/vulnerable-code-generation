//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

int main() {
    // Create the head of the linked list
    node_t *head = NULL;

    // Create a few nodes and add them to the linked list
    node_t *node1 = malloc(sizeof(node_t));
    node1->data = 1;
    node1->next = NULL;
    head = node1;

    node_t *node2 = malloc(sizeof(node_t));
    node2->data = 2;
    node2->next = NULL;
    node1->next = node2;

    node_t *node3 = malloc(sizeof(node_t));
    node3->data = 3;
    node3->next = NULL;
    node2->next = node3;

    // Print the linked list
    node_t *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    // Reverse the linked list
    node_t *prev = NULL;
    node_t *next;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;

    // Print the reversed linked list
    current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    // Free the linked list
    current = head;
    while (current != NULL) {
        node_t *next = current->next;
        free(current);
        current = next;
    }

    return 0;
}