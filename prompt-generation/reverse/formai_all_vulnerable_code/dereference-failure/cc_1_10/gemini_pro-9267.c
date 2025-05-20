//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure
typedef struct node {
    char *data;
    struct node *next;
} node;

// Create a new node
node *create_node(char *data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = strdup(data);
    new_node->next = NULL;
    return new_node;
}

// Insert a node at the beginning of the list
node *insert_at_beginning(node *head, char *data) {
    node *new_node = create_node(data);
    new_node->next = head;
    return new_node;
}

// Insert a node at the end of the list
node *insert_at_end(node *head, char *data) {
    if (head == NULL) {
        return create_node(data);
    }
    node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = create_node(data);
    return head;
}

// Insert a node after a given node
node *insert_after(node *head, node *prev, char *data) {
    if (prev == NULL) {
        return insert_at_beginning(head, data);
    }
    node *new_node = create_node(data);
    new_node->next = prev->next;
    prev->next = new_node;
    return head;
}

// Delete a node from the list
node *delete_node(node *head, char *data) {
    if (head == NULL) {
        return NULL;
    }
    if (strcmp(head->data, data) == 0) {
        return head->next;
    }
    node *current = head;
    while (current->next != NULL) {
        if (strcmp(current->next->data, data) == 0) {
            current->next = current->next->next;
            return head;
        }
        current = current->next;
    }
    return head;
}

// Print the list
void print_list(node *head) {
    node *current = head;
    while (current != NULL) {
        printf("%s ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Free the list
void free_list(node *head) {
    node *current = head;
    while (current != NULL) {
        node *next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
}

int main() {
    // Create a linked list
    node *head = NULL;
    head = insert_at_beginning(head, "Hello");
    head = insert_at_end(head, "World");
    head = insert_after(head, head->next, "!");

    // Print the list
    printf("Original list: ");
    print_list(head);

    // Delete a node from the list
    head = delete_node(head, "World");

    // Print the list
    printf("List after deleting \"World\": ");
    print_list(head);

    // Free the list
    free_list(head);

    return 0;
}