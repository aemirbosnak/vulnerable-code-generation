//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

// Define a custom data structure to represent a node in a linked list
typedef struct node {
    int data;
    struct node *next;
} node;

// Create a new node with the given data
node *create_node(int data) {
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Error: Could not allocate memory for new node.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Insert a new node at the beginning of the linked list
void insert_at_beginning(node **head, int data) {
    node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Insert a new node at the end of the linked list
void insert_at_end(node **head, int data) {
    node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
    } else {
        node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Delete the node at the beginning of the linked list
void delete_at_beginning(node **head) {
    if (*head == NULL) {
        printf("Error: Cannot delete from an empty list.\n");
        return;
    }
    node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Delete the node at the end of the linked list
void delete_at_end(node **head) {
    if (*head == NULL) {
        printf("Error: Cannot delete from an empty list.\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    node *current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
}

// Print the linked list
void print_list(node *head) {
    node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Free the entire linked list
void free_list(node *head) {
    node *current = head;
    while (current != NULL) {
        node *next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    // Create an empty linked list
    node *head = NULL;

    // Insert some data into the linked list
    insert_at_beginning(&head, 10);
    insert_at_end(&head, 20);
    insert_at_beginning(&head, 5);
    insert_at_end(&head, 30);

    // Print the linked list
    print_list(head);

    // Delete the node at the beginning of the linked list
    delete_at_beginning(&head);

    // Print the linked list
    print_list(head);

    // Delete the node at the end of the linked list
    delete_at_end(&head);

    // Print the linked list
    print_list(head);

    // Free the entire linked list
    free_list(head);

    return 0;
}