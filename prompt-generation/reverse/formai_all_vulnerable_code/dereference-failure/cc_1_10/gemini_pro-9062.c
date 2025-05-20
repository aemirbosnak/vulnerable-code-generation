//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: safe
#include <stdlib.h>
#include <stdio.h>

// Define the node structure.
typedef struct node {
    int data;
    struct node *next;
} node_t;

// Create a new node.
node_t *create_node(int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (new_node == NULL) {
        printf("Error: malloc failed.\n");
        return NULL;
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Insert a new node at the beginning of the list.
void insert_at_beginning(node_t **head, int data) {
    node_t *new_node = create_node(data);
    if (new_node == NULL) {
        return;
    }
    new_node->next = *head;
    *head = new_node;
}

// Insert a new node at the end of the list.
void insert_at_end(node_t **head, int data) {
    node_t *new_node = create_node(data);
    if (new_node == NULL) {
        return;
    }
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

// Insert a new node after a given node.
void insert_after(node_t *prev_node, int data) {
    if (prev_node == NULL) {
        printf("Error: prev_node is NULL.\n");
        return;
    }
    node_t *new_node = create_node(data);
    if (new_node == NULL) {
        return;
    }
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Delete a node from the beginning of the list.
void delete_at_beginning(node_t **head) {
    if (*head == NULL) {
        printf("Error: head is NULL.\n");
        return;
    }
    node_t *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Delete a node from the end of the list.
void delete_at_end(node_t **head) {
    if (*head == NULL) {
        printf("Error: head is NULL.\n");
        return;
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

// Delete a node from the middle of the list.
void delete_node(node_t **head, node_t *node_to_delete) {
    if (*head == NULL || node_to_delete == NULL) {
        printf("Error: head or node_to_delete is NULL.\n");
        return;
    }
    if (node_to_delete == *head) {
        delete_at_beginning(head);
        return;
    }
    node_t *current = *head;
    while (current->next != node_to_delete) {
        current = current->next;
    }
    if (current->next == NULL) {
        printf("Error: node_to_delete is not in the list.\n");
        return;
    }
    current->next = node_to_delete->next;
    free(node_to_delete);
}

// Print the list.
void print_list(node_t *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    node_t *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Free the list.
void free_list(node_t *head) {
    node_t *current = head;
    while (current != NULL) {
        node_t *next = current->next;
        free(current);
        current = next;
    }
}

// Main function.
int main() {
    // Create a linked list.
    node_t *head = NULL;

    // Insert some nodes into the list.
    insert_at_beginning(&head, 1);
    insert_at_end(&head, 2);
    insert_at_end(&head, 3);
    insert_after(head, 4);

    // Print the list.
    printf("List: ");
    print_list(head);

    // Delete a node from the beginning of the list.
    delete_at_beginning(&head);

    // Delete a node from the end of the list.
    delete_at_end(&head);

    // Delete a node from the middle of the list.
    delete_node(&head, head->next);

    // Print the list.
    printf("List: ");
    print_list(head);

    // Free the list.
    free_list(head);

    return 0;
}