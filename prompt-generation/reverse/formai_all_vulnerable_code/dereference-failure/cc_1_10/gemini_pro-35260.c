//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

node_t *create_node(int data) {
    node_t *new_node = malloc(sizeof(node_t));
    if (new_node == NULL) {
        return NULL;
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

node_t *insert_node(node_t *head, int data) {
    node_t *new_node = create_node(data);
    if (new_node == NULL) {
        return NULL;
    }
    if (head == NULL) {
        return new_node;
    }
    node_t *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    return head;
}

node_t *delete_node(node_t *head, int data) {
    if (head == NULL) {
        return NULL;
    }
    if (head->data == data) {
        node_t *new_head = head->next;
        free(head);
        return new_head;
    }
    node_t *current = head;
    while (current->next != NULL && current->next->data != data) {
        current = current->next;
    }
    if (current->next == NULL) {
        return head;
    }
    node_t *next_node = current->next->next;
    free(current->next);
    current->next = next_node;
    return head;
}

void print_list(node_t *head) {
    if (head == NULL) {
        printf("Empty list\n");
        return;
    }
    node_t *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    node_t *head = NULL;
    head = insert_node(head, 1);
    head = insert_node(head, 2);
    head = insert_node(head, 3);
    head = insert_node(head, 4);
    head = insert_node(head, 5);
    print_list(head);
    head = delete_node(head, 3);
    print_list(head);
    return 0;
}