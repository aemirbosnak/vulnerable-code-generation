//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node {
    int data;
    struct node *next;
} node_t;

// Create a new node
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
void insert_after(node_t *node, int data) {
    if (node == NULL) {
        printf("Error: node is NULL\n");
        exit(1);
    }
    node_t *new_node = create_node(data);
    new_node->next = node->next;
    node->next = new_node;
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
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    node_t *current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
}

// Delete a node from the middle of the list
void delete_from_middle(node_t **head, int data) {
    if (*head == NULL) {
        printf("Error: list is empty\n");
        exit(1);
    }
    node_t *current = *head;
    node_t *prev = NULL;
    while (current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Error: node not found\n");
        exit(1);
    }
    if (prev == NULL) {
        *head = (*head)->next;
    } else {
        prev->next = current->next;
    }
    free(current);
}

// Print the list
void print_list(node_t *head) {
    node_t *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Free the list
void free_list(node_t *head) {
    node_t *current = head;
    while (current != NULL) {
        node_t *temp = current;
        current = current->next;
        free(temp);
    }
}

// Main function
int main() {
    // Create an empty list
    node_t *head = NULL;

    // Insert some nodes into the list
    insert_at_beginning(&head, 1);
    insert_at_end(&head, 2);
    insert_after(head, 3);
    insert_at_end(&head, 4);
    insert_at_beginning(&head, 5);

    // Print the list
    printf("List before operations:\n");
    print_list(head);

    // Delete a node from the beginning of the list
    delete_from_beginning(&head);

    // Delete a node from the end of the list
    delete_from_end(&head);

    // Delete a node from the middle of the list
    delete_from_middle(&head, 3);

    // Print the list
    printf("List after operations:\n");
    print_list(head);

    // Free the list
    free_list(head);

    return 0;
}