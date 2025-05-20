//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: genius
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct node {
    int data;
    struct node *next;
} node_t;

// Function to create a new node
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

// Function to insert a node at the beginning of the list
void insert_at_beginning(node_t **head, int data) {
    node_t *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Function to insert a node at the end of the list
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

// Function to insert a node after a given node
void insert_after(node_t **head, int data, int after_data) {
    node_t *new_node = create_node(data);
    node_t *current = *head;
    while (current != NULL) {
        if (current->data == after_data) {
            new_node->next = current->next;
            current->next = new_node;
            return;
        }
        current = current->next;
    }
    printf("Error: Node not found\n");
}

// Function to delete a node from the beginning of the list
void delete_from_beginning(node_t **head) {
    if (*head == NULL) {
        printf("Error: List is empty\n");
        return;
    }
    node_t *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Function to delete a node from the end of the list
void delete_from_end(node_t **head) {
    if (*head == NULL) {
        printf("Error: List is empty\n");
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

// Function to delete a node after a given node
void delete_after(node_t **head, int after_data) {
    node_t *current = *head;
    while (current != NULL) {
        if (current->data == after_data) {
            if (current->next == NULL) {
                printf("Error: Node not found\n");
                return;
            }
            node_t *temp = current->next;
            current->next = current->next->next;
            free(temp);
            return;
        }
        current = current->next;
    }
    printf("Error: Node not found\n");
}

// Function to print the list
void print_list(node_t *head) {
    node_t *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main function
int main() {
    // Create an empty list
    node_t *head = NULL;

    // Insert some nodes
    insert_at_beginning(&head, 1);
    insert_at_end(&head, 2);
    insert_after(&head, 3, 1);
    insert_after(&head, 4, 3);

    // Print the list
    print_list(head);

    // Delete some nodes
    delete_from_beginning(&head);
    delete_from_end(&head);
    delete_after(&head, 2);

    // Print the list again
    print_list(head);

    // Free the remaining nodes
    node_t *current = head;
    while (current != NULL) {
        node_t *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}