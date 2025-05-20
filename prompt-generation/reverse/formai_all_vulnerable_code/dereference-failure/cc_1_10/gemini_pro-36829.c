//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

node_t *create_node(int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (new_node == NULL) {
        printf("Error: malloc failed\n");
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
    node_t *current_node = *head;
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }
    current_node->next = new_node;
}

void insert_after_node(node_t *prev_node, int data) {
    if (prev_node == NULL) {
        printf("Error: previous node cannot be NULL\n");
        exit(1);
    }
    node_t *new_node = create_node(data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void delete_node(node_t **head, node_t *node_to_delete) {
    if (*head == node_to_delete) {
        *head = node_to_delete->next;
        free(node_to_delete);
        return;
    }
    node_t *current_node = *head;
    while (current_node->next != node_to_delete) {
        current_node = current_node->next;
    }
    current_node->next = node_to_delete->next;
    free(node_to_delete);
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

    // Create a linked list of numbers from 1 to 10
    for (int i = 1; i <= 10; i++) {
        insert_at_end(&head, i);
    }

    // Print the linked list
    printf("Original linked list: ");
    print_list(head);

    // Insert a new node with the value 5 after the node with the value 3
    node_t *node_after_which_to_insert = head;
    while (node_after_which_to_insert->data != 3) {
        node_after_which_to_insert = node_after_which_to_insert->next;
    }
    insert_after_node(node_after_which_to_insert, 5);

    // Print the linked list
    printf("Linked list after inserting 5 after 3: ");
    print_list(head);

    // Delete the node with the value 7
    node_t *node_to_delete = head;
    while (node_to_delete->data != 7) {
        node_to_delete = node_to_delete->next;
    }
    delete_node(&head, node_to_delete);

    // Print the linked list
    printf("Linked list after deleting 7: ");
    print_list(head);

    return 0;
}