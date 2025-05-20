//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

// A node in a linked list
typedef struct node {
    int data;
    struct node *next;
} node_t;

// Create a new node with the given data
node_t *create_node(int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (new_node == NULL) {
        printf("Error: malloc failed.\n");
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
        printf("Error: prev_node is NULL.\n");
        exit(1);
    }
    node_t *new_node = create_node(data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Delete a node from the beginning of the list
void delete_at_beginning(node_t **head) {
    if (*head == NULL) {
        printf("Error: head is NULL.\n");
        exit(1);
    }
    node_t *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Delete a node from the end of the list
void delete_at_end(node_t **head) {
    if (*head == NULL) {
        printf("Error: head is NULL.\n");
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
void delete_node(node_t **head, node_t *node) {
    if (*head == NULL) {
        printf("Error: head is NULL.\n");
        exit(1);
    }
    if (node == *head) {
        delete_at_beginning(head);
        return;
    }
    node_t *current = *head;
    while (current->next != node) {
        if (current->next == NULL) {
            printf("Error: node not found.\n");
            exit(1);
        }
        current = current->next;
    }
    current->next = node->next;
    free(node);
}

// Reverse the linked list
void reverse_list(node_t **head) {
    node_t *prev = NULL;
    node_t *current = *head;
    while (current != NULL) {
        node_t *next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

// Print the linked list
void print_list(node_t *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    node_t *head = NULL;

    // Insert some nodes into the list
    insert_at_beginning(&head, 1);
    insert_at_end(&head, 2);
    insert_at_end(&head, 3);
    insert_after(head, 4);

    // Print the list
    printf("Original list: ");
    print_list(head);

    // Delete a node from the beginning of the list
    delete_at_beginning(&head);

    // Print the list
    printf("List after deleting a node from the beginning: ");
    print_list(head);

    // Delete a node from the end of the list
    delete_at_end(&head);

    // Print the list
    printf("List after deleting a node from the end: ");
    print_list(head);

    // Delete a node from the middle of the list
    delete_node(&head, head->next);

    // Print the list
    printf("List after deleting a node from the middle: ");
    print_list(head);

    // Reverse the list
    reverse_list(&head);

    // Print the list
    printf("Reversed list: ");
    print_list(head);

    return 0;
}