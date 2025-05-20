//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    void *data;
    struct node *next;
} node_t;

node_t* create_node(void *data) {
    node_t *node = malloc(sizeof(node_t));
    node->data = data;
    node->next = NULL;
    return node;
}

void delete_node(node_t *node) {
    free(node);
}

void add_node(node_t **head, void *data) {
    node_t *node = create_node(data);
    node->next = *head;
    *head = node;
}

void delete_node_with_data(node_t **head, void *data) {
    node_t *prev = NULL;
    node_t *curr = *head;
    while (curr!= NULL && curr->data!= data) {
        prev = curr;
        curr = curr->next;
    }
    if (curr!= NULL) {
        if (prev == NULL) {
            *head = curr->next;
        } else {
            prev->next = curr->next;
        }
        delete_node(curr);
    }
}

void print_list(node_t *head) {
    node_t *curr = head;
    while (curr!= NULL) {
        printf("%p: %p\n", curr, curr->data);
        curr = curr->next;
    }
}

int main() {
    node_t *head = NULL;
    add_node(&head, (void*)1);
    add_node(&head, (void*)2);
    add_node(&head, (void*)3);
    print_list(head);

    delete_node_with_data(&head, (void*)2);
    print_list(head);

    delete_node(&head);
    return 0;
}