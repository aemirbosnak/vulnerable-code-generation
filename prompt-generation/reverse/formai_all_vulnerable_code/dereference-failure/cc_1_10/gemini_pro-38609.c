//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: future-proof
#include <stdlib.h>
#include <stdio.h>

// Node structure
typedef struct node {
    int data;
    struct node *next;
} node_t;

// Linked list operations
node_t *create_node(int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (new_node == NULL) {
        perror("Error: malloc failed");
        exit(EXIT_FAILURE);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_node(node_t **head, node_t *new_node) {
    if (*head == NULL) {
        *head = new_node;
    } else {
        node_t *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void delete_node(node_t **head, int data) {
    if (*head == NULL) {
        return;
    }
    if ((*head)->data == data) {
        node_t *new_head = (*head)->next;
        free(*head);
        *head = new_head;
    } else {
        node_t *current = *head;
        while (current->next != NULL) {
            if (current->next->data == data) {
                node_t *next_node = current->next->next;
                free(current->next);
                current->next = next_node;
                break;
            }
            current = current->next;
        }
    }
}

void print_list(node_t *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Main function
int main() {
    // Create a linked list
    node_t *head = NULL;
    insert_node(&head, create_node(1));
    insert_node(&head, create_node(2));
    insert_node(&head, create_node(3));
    insert_node(&head, create_node(4));
    insert_node(&head, create_node(5));

    // Print the linked list
    print_list(head);

    // Delete a node from the linked list
    delete_node(&head, 3);

    // Print the linked list
    print_list(head);

    // Free the linked list
    while (head != NULL) {
        node_t *next_node = head->next;
        free(head);
        head = next_node;
    }

    return 0;
}