//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

// Structure to represent a node in a linked list
typedef struct node {
    int data;
    struct node *next;
} node_t;

// Function to create a new node
node_t *create_node(int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (new_node == NULL) {
        return NULL;
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a node at the beginning of a linked list
node_t *insert_at_head(node_t *head, int data) {
    node_t *new_node = create_node(data);
    if (new_node == NULL) {
        return NULL;
    }
    new_node->next = head;
    head = new_node;
    return head;
}

// Function to insert a node at the end of a linked list
node_t *insert_at_tail(node_t *head, int data) {
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

// Function to delete a node from a linked list
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
    while (current->next != NULL) {
        if (current->next->data == data) {
            node_t *next_node = current->next->next;
            free(current->next);
            current->next = next_node;
            return head;
        }
        current = current->next;
    }
    return head;
}

// Function to print a linked list
void print_list(node_t *head) {
    printf("[");
    node_t *current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(", ");
        }
        current = current->next;
    }
    printf("]\n");
}

// Function to test the linked list functions
int main() {
    node_t *head = NULL;
    head = insert_at_head(head, 1);
    head = insert_at_tail(head, 2);
    head = insert_at_tail(head, 3);
    head = insert_at_tail(head, 4);
    head = insert_at_tail(head, 5);
    print_list(head);  // Output: [1, 2, 3, 4, 5]
    head = delete_node(head, 2);
    head = delete_node(head, 5);
    print_list(head);  // Output: [1, 3, 4]
    return 0;
}