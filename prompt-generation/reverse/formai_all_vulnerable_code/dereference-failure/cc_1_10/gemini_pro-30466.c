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
        printf("Error allocating memory for new node.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Insert a node at the beginning of the list
void insert_at_beginning(node_t **head, int data) {
    node_t *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Insert a node at the end of the list
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

// Insert a node after a given node
void insert_after(node_t **head, int data, int after_data) {
    node_t *new_node = create_node(data);
    node_t *current = *head;
    while (current != NULL && current->data != after_data) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Node with data %d not found.\n", after_data);
        return;
    }
    new_node->next = current->next;
    current->next = new_node;
}

// Delete a node from the beginning of the list
void delete_at_beginning(node_t **head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    node_t *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Delete a node from the end of the list
void delete_at_end(node_t **head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
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

// Delete a node with a given value
void delete_with_value(node_t **head, int data) {
    node_t *current = *head;
    node_t *prev = NULL;
    while (current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Node with data %d not found.\n", data);
        return;
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
    node_t *head = NULL;
    insert_at_beginning(&head, 1);
    insert_at_end(&head, 2);
    insert_after(&head, 3, 1);
    print_list(head); // Output: 1 3 2
    delete_at_beginning(&head);
    print_list(head); // Output: 3 2
    delete_at_end(&head);
    print_list(head); // Output: 3
    delete_with_value(&head, 3);
    print_list(head); // Output: Empty list
    free_list(head);
    return 0;
}