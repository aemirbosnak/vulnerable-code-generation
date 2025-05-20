//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

void print_list(node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void push_front(node **head, int data) {
    node *new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void push_back(node **head, int data) {
    node *new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        node *last_node = *head;
        while (last_node->next != NULL) {
            last_node = last_node->next;
        }
        last_node->next = new_node;
    }
}

void insert_after(node *prev_node, int data) {
    if (prev_node == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }

    node *new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void delete_node(node **head, node *node_to_delete) {
    if (*head == node_to_delete) {
        *head = node_to_delete->next;
    } else {
        node *prev_node = *head;
        while (prev_node->next != node_to_delete) {
            prev_node = prev_node->next;
        }
        prev_node->next = node_to_delete->next;
    }
    free(node_to_delete);
}

int main() {
    node *head = NULL;

    push_front(&head, 1);
    push_back(&head, 2);
    push_back(&head, 3);
    insert_after(head, 4);

    print_list(head);  // Output: 4 1 2 3

    delete_node(&head, head->next);

    print_list(head);  // Output: 4 1 3

    return 0;
}