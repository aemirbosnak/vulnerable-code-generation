//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: post-apocalyptic
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

node_t *create_node(int data) {
    node_t *new_node = malloc(sizeof(node_t));
    if (new_node == NULL) {
        perror("malloc");
        exit(1);
    }

    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

void insert_at_beginning(node_t **head, int data) {
    node_t *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

void insert_at_end(node_t **head, int data) {
    node_t *new_node = create_node(data);

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    node_t *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_node;
}

void insert_after_node(node_t *prev_node, int data) {
    if (prev_node == NULL) {
        printf("Node not found.\n");
        return;
    }

    node_t *new_node = create_node(data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void traverse_list(node_t *head) {
    node_t *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }

    printf("NULL\n");
}

void delete_node(node_t **head, int data) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    node_t *current = *head;
    node_t *prev = NULL;

    while (current != NULL) {
        if (current->data == data) {
            if (prev == NULL) {
                *head = current->next;
            } else {
                prev->next = current->next;
            }

            free(current);
            return;
        }

        prev = current;
        current = current->next;
    }

    printf("Node not found.\n");
}

int main() {
    node_t *head = NULL;

    insert_at_beginning(&head, 10);
    insert_at_end(&head, 20);
    insert_after_node(head, 15);
    insert_after_node(head->next, 25);

    traverse_list(head);

    delete_node(&head, 20);

    traverse_list(head);

    return 0;
}