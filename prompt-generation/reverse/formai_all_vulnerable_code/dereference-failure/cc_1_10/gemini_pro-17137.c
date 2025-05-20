//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

node_t *create_node(int data) {
    node_t *node = malloc(sizeof(node_t));
    node->data = data;
    node->next = NULL;
    return node;
}

void insert_node(node_t **head, node_t *node) {
    if (*head == NULL) {
        *head = node;
    } else {
        node->next = *head;
        *head = node;
    }
}

void print_list(node_t *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void sort_list(node_t **head) {
    node_t *current_node = *head;
    node_t *next_node;

    while (current_node != NULL) {
        next_node = current_node->next;

        while (next_node != NULL) {
            if (current_node->data > next_node->data) {
                int temp = current_node->data;
                current_node->data = next_node->data;
                next_node->data = temp;
            }
            next_node = next_node->next;
        }
        current_node = current_node->next;
    }
}

int main() {
    node_t *head = NULL;

    insert_node(&head, create_node(10));
    insert_node(&head, create_node(5));
    insert_node(&head, create_node(15));
    insert_node(&head, create_node(2));
    insert_node(&head, create_node(7));

    print_list(head);

    sort_list(&head);

    print_list(head);

    return 0;
}