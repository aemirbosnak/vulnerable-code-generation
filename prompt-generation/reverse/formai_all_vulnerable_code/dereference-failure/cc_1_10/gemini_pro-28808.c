//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

void print_list(node_t *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

void reverse_list(node_t **head) {
    node_t *prev = NULL;
    node_t *current = *head;
    node_t *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

int main() {
    node_t *head = NULL;

    // Create a linked list with the following values: 1, 2, 3, 4, 5
    for (int i = 1; i <= 5; i++) {
        node_t *new_node = malloc(sizeof(node_t));
        new_node->data = i;
        new_node->next = head;
        head = new_node;
    }

    // Print the original linked list
    printf("Original linked list: ");
    print_list(head);
    printf("\n");

    // Reverse the linked list
    reverse_list(&head);

    // Print the reversed linked list
    printf("Reversed linked list: ");
    print_list(head);
    printf("\n");

    return 0;
}