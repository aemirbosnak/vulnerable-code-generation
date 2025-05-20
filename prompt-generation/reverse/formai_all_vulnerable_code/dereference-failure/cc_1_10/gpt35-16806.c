//FormAI DATASET v1.0 Category: Memory management ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

void print_list(node_t *head) {
    node_t *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
}

void push(node_t **head, int data) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void delete_node(node_t **head, int key) {
    node_t *current = *head;
    node_t *previous = NULL;

    if (current != NULL && current->data == key) {
        *head = current->next;
        free(current);
        return;
    }

    while (current != NULL && current->data != key) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        return;
    }

    previous->next = current->next;

    free(current);
}

int main() {
    node_t *head = NULL;

    push(&head, 3);
    push(&head, 5);
    push(&head, 2);
    push(&head, 7);

    printf("List before deletion: ");
    print_list(head);

    delete_node(&head, 2);

    printf("\nList after deletion: ");
    print_list(head);

    return 0;
}