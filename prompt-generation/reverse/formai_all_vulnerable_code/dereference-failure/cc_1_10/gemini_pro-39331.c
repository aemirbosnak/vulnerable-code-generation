//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

node_t *create_node(int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

node_t *insert_at_head(node_t *head, int data) {
    node_t *new_node = create_node(data);
    new_node->next = head;
    return new_node;
}

node_t *insert_at_tail(node_t *head, int data) {
    if (head == NULL) {
        return create_node(data);
    }
    node_t *curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = create_node(data);
    return head;
}

node_t *insert_at_index(node_t *head, int data, int index) {
    if (index == 0) {
        return insert_at_head(head, data);
    }
    node_t *curr = head;
    int i = 0;
    while (curr != NULL && i < index - 1) {
        curr = curr->next;
        i++;
    }
    if (curr == NULL || i < index - 1) {
        return head;
    }
    node_t *new_node = create_node(data);
    new_node->next = curr->next;
    curr->next = new_node;
    return head;
}

node_t *delete_at_head(node_t *head) {
    if (head == NULL) {
        return NULL;
    }
    node_t *new_head = head->next;
    free(head);
    return new_head;
}

node_t *delete_at_tail(node_t *head) {
    if (head == NULL) {
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    node_t *curr = head;
    while (curr->next->next != NULL) {
        curr = curr->next;
    }
    free(curr->next);
    curr->next = NULL;
    return head;
}

node_t *delete_at_index(node_t *head, int index) {
    if (index == 0) {
        return delete_at_head(head);
    }
    node_t *curr = head;
    int i = 0;
    while (curr != NULL && i < index - 1) {
        curr = curr->next;
        i++;
    }
    if (curr == NULL || i < index - 1) {
        return head;
    }
    node_t *to_be_deleted = curr->next;
    curr->next = to_be_deleted->next;
    free(to_be_deleted);
    return head;
}

void print_list(node_t *head) {
    node_t *curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    node_t *head = NULL;

    head = insert_at_head(head, 10);
    head = insert_at_tail(head, 20);
    head = insert_at_index(head, 30, 1);
    head = insert_at_index(head, 40, 3);

    print_list(head);

    head = delete_at_head(head);
    head = delete_at_tail(head);
    head = delete_at_index(head, 1);

    print_list(head);

    return 0;
}