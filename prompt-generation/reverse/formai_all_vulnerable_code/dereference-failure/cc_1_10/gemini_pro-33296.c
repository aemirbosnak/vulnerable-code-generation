//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node {
    int data;
    struct node *next;
} node_t;

// Create a new node with the given data
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

// Insert a new node at the beginning of the list
void insert_at_beginning(node_t **head, int data) {
    node_t *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Insert a new node at the end of the list
void insert_at_end(node_t **head, int data) {
    node_t *new_node = create_node(data);

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    node_t *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_node;
}

// Insert a new node after a given node
void insert_after(node_t *prev_node, int data) {
    if (prev_node == NULL) {
        printf("Error: prev_node cannot be NULL\n");
        exit(1);
    }

    node_t *new_node = create_node(data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Delete a node from the beginning of the list
void delete_from_beginning(node_t **head) {
    if (*head == NULL) {
        printf("Error: list is empty\n");
        exit(1);
    }

    node_t *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Delete a node from the end of the list
void delete_from_end(node_t **head) {
    if (*head == NULL) {
        printf("Error: list is empty\n");
        exit(1);
    }

    node_t *current = *head;
    node_t *prev = NULL;

    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    if (prev == NULL) {
        *head = NULL;
    } else {
        prev->next = NULL;
    }

    free(current);
}

// Delete a node from the list
void delete_node(node_t **head, node_t *node) {
    if (*head == NULL || node == NULL) {
        printf("Error: list or node is empty\n");
        exit(1);
    }

    if (node == *head) {
        delete_from_beginning(head);
        return;
    }

    node_t *current = *head;
    node_t *prev = NULL;

    while (current != node) {
        prev = current;
        current = current->next;
    }

    if (prev == NULL) {
        printf("Error: node not found\n");
        exit(1);
    }

    prev->next = node->next;
    free(node);
}

// Print the linked list
void print_list(node_t *head) {
    node_t *current = head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

// Free the linked list
void free_list(node_t *head) {
    node_t *current = head;

    while (current != NULL) {
        node_t *next = current->next;
        free(current);
        current = next;
    }
}

// Main function
int main() {
    // Create a linked list
    node_t *head = NULL;

    // Insert some data into the list
    insert_at_beginning(&head, 10);
    insert_at_end(&head, 20);
    insert_after(head, 15);

    // Print the list
    printf("Linked list: ");
    print_list(head);

    // Delete a node from the beginning of the list
    delete_from_beginning(&head);

    // Print the list
    printf("Linked list after deleting from the beginning: ");
    print_list(head);

    // Delete a node from the end of the list
    delete_from_end(&head);

    // Print the list
    printf("Linked list after deleting from the end: ");
    print_list(head);

    // Delete a node from the middle of the list
    delete_node(&head, head->next);

    // Print the list
    printf("Linked list after deleting from the middle: ");
    print_list(head);

    // Free the list
    free_list(head);

    return 0;
}