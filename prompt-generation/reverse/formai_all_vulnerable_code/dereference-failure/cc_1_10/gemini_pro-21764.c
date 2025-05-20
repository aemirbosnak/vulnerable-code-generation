//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

node_t *create_node(int data) {
    node_t *new_node = malloc(sizeof(node_t));
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
    node_t *current_node = *head;
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }
    current_node->next = new_node;
}

void insert_at_index(node_t **head, int data, int index) {
    node_t *new_node = create_node(data);
    node_t *current_node = *head;
    for (int i = 0; i < index; i++) {
        current_node = current_node->next;
    }
    new_node->next = current_node->next;
    current_node->next = new_node;
}

void delete_at_beginning(node_t **head) {
    node_t *current_node = *head;
    *head = current_node->next;
    free(current_node);
}

void delete_at_end(node_t **head) {
    node_t *current_node = *head;
    while (current_node->next->next != NULL) {
        current_node = current_node->next;
    }
    free(current_node->next);
    current_node->next = NULL;
}

void delete_at_index(node_t **head, int index) {
    node_t *current_node = *head;
    for (int i = 0; i < index; i++) {
        current_node = current_node->next;
    }
    node_t *temp_node = current_node->next;
    current_node->next = temp_node->next;
    free(temp_node);
}

void print_list(node_t *head) {
    node_t *current_node = head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

int main() {
    node_t *head = NULL;
    insert_at_beginning(&head, 1);
    insert_at_beginning(&head, 2);
    insert_at_end(&head, 3);
    insert_at_index(&head, 4, 1);
    print_list(head); // Outputs: 2 1 4 3
    delete_at_beginning(&head);
    delete_at_end(&head);
    delete_at_index(&head, 1);
    print_list(head); // Outputs: 4
    return 0;
}