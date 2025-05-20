//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Define a node structure
typedef struct node {
    int data;
    struct node *next;
} node_t;

// Create a new node
node_t *create_node(int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Insert a node at the beginning of a linked list
node_t *insert_at_beginning(node_t **head, int data) {
    node_t *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
    return new_node;
}

// Insert a node at the end of a linked list
node_t *insert_at_end(node_t **head, int data) {
    node_t *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
    } else {
        node_t *current_node = *head;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
    return new_node;
}

// Insert a node after a given node
node_t *insert_after(node_t *node, int data) {
    if (node == NULL) {
        return NULL;
    }
    node_t *new_node = create_node(data);
    new_node->next = node->next;
    node->next = new_node;
    return new_node;
}

// Delete a node from a linked list
void delete_node(node_t **head, node_t *node) {
    if (*head == node) {
        *head = node->next;
    } else {
        node_t *current_node = *head;
        while (current_node->next != node) {
            current_node = current_node->next;
        }
        current_node->next = node->next;
    }
    free(node);
}

// Print a linked list
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
    insert_at_beginning(&head, 10);
    insert_at_end(&head, 20);
    insert_after(head->next, 30);
    insert_after(head->next->next, 40);

    // Print the linked list
    printf("Linked list: ");
    print_list(head);

    // Delete a node from the linked list
    delete_node(&head, head->next->next);

    // Print the linked list
    printf("Linked list after deletion: ");
    print_list(head);

    return 0;
}