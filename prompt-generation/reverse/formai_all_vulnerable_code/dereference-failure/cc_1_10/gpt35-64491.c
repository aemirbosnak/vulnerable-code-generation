//FormAI DATASET v1.0 Category: Linked list operations ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
} node_t;

void print_list(node_t *head) {
    node_t *current = head;

    while (current != NULL) {
        printf("%d->", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

void push(node_t *head, int value) {
    node_t *current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = (node_t *) malloc(sizeof(node_t));
    current->next->value = value;
    current->next->next = NULL;
}

int pop(node_t **head) {
    int value = -1;
    node_t *next_node = NULL;

    if (*head == NULL) {
        return -1;
    }

    next_node = (*head)->next;
    value = (*head)->value;
    free(*head);
    *head = next_node;

    return value;
}

int main() {
    node_t *head = NULL;
    head = (node_t *) malloc(sizeof(node_t));

    if (head == NULL) {
        return 1;
    }

    head->value = 1;
    head->next = (node_t *) malloc(sizeof(node_t));
    head->next->value = 2;
    head->next->next = NULL;

    print_list(head);

    push(head, 5);
    print_list(head);

    int value = pop(&head);
    printf("Popped value: %d\n", value);
    print_list(head);

    return 0;
}