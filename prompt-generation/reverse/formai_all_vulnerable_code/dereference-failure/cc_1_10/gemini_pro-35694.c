//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

node_t *head = NULL;

void insert_at_head(int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

void insert_at_tail(int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        return;
    }

    node_t *last_node = head;
    while (last_node->next != NULL) {
        last_node = last_node->next;
    }

    last_node->next = new_node;
}

void insert_at_index(int index, int data) {
    if (index == 0) {
        insert_at_head(data);
        return;
    }

    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;

    int i = 0;
    node_t *current_node = head;
    while (i < index - 1) {
        current_node = current_node->next;
        i++;
    }

    new_node->next = current_node->next;
    current_node->next = new_node;
}

void delete_at_head() {
    if (head == NULL) {
        return;
    }

    node_t *next_node = head->next;
    free(head);
    head = next_node;
}

void delete_at_tail() {
    if (head == NULL) {
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    node_t *current_node = head;
    while (current_node->next->next != NULL) {
        current_node = current_node->next;
    }

    free(current_node->next);
    current_node->next = NULL;
}

void delete_at_index(int index) {
    if (index == 0) {
        delete_at_head();
        return;
    }

    int i = 0;
    node_t *current_node = head;
    while (i < index - 1) {
        current_node = current_node->next;
        i++;
    }

    node_t *next_node = current_node->next->next;
    free(current_node->next);
    current_node->next = next_node;
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
    insert_at_head(1);
    insert_at_tail(2);
    insert_at_index(1, 3);
    print_list(); // 1 3 2

    delete_at_head();
    delete_at_tail();
    delete_at_index(0);
    print_list(); // Empty list

    return 0;
}