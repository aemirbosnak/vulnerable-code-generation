//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

node_t *head = NULL;

void insert_front(int data) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

void insert_after(node_t *prev_node, int data) {
    if (prev_node == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void delete_node(node_t *node) {
    if (node == NULL) {
        printf("Node cannot be NULL\n");
        return;
    }
    if (node == head) {
        head = node->next;
    } else {
        node_t *prev_node = head;
        while (prev_node->next != node) {
            prev_node = prev_node->next;
        }
        prev_node->next = node->next;
    }
    free(node);
}

void print_list() {
    node_t *current_node = head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

int main() {
    insert_front(1);
    insert_front(2);
    insert_front(3);
    print_list();  // prints: 3 2 1

    insert_after(head, 4);
    insert_after(head->next, 5);
    print_list();  // prints: 3 4 2 5 1

    delete_node(head);
    delete_node(head->next->next);
    print_list();  // prints: 4 2 1

    return 0;
}