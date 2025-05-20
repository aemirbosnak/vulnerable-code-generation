//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

// Create a new node
node *create_node(int data) {
    node *new_node = (node *)malloc(sizeof(node));
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

// Insert a new node after a given node
void insert_after(node *prev_node, int data) {
    if (prev_node == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }
    node *new_node = create_node(data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Delete a node from the beginning of the linked list
void delete_at_beginning(node **head) {
    if (*head == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Delete a node from the end of the linked list
void delete_at_end(node **head) {
    if (*head == NULL) {
        printf("Linked list is empty\n");
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

// Delete a node from the linked list
void delete_node(node **head, node *node_to_delete) {
    if (*head == NULL || node_to_delete == NULL) {
        printf("Linked list or node to delete is NULL\n");
        return;
    }
    if (*head == node_to_delete) {
        *head = (*head)->next;
        free(node_to_delete);
        return;
    }
    node *current = *head;
    while (current->next != node_to_delete) {
        current = current->next;
    }
    if (current->next == NULL) {
        printf("Node to delete is not in the linked list\n");
        return;
    }
    current->next = node_to_delete->next;
    free(node_to_delete);
}

// Print the linked list
void print_linked_list(node *head) {
    node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main function
int main() {
    // Create a linked list
    node *head = NULL;
    insert_at_beginning(&head, 1);
    insert_at_end(&head, 2);
    insert_at_end(&head, 3);
    insert_at_end(&head, 4);
    insert_at_end(&head, 5);

    // Print the linked list
    printf("Linked list: ");
    print_linked_list(head);

    // Insert a new node after the second node
    insert_after(head->next, 6);

    // Print the linked list
    printf("Linked list after inserting a new node after the second node: ");
    print_linked_list(head);

    // Delete a node from the beginning of the linked list
    delete_at_beginning(&head);

    // Print the linked list
    printf("Linked list after deleting a node from the beginning: ");
    print_linked_list(head);

    // Delete a node from the end of the linked list
    delete_at_end(&head);

    // Print the linked list
    printf("Linked list after deleting a node from the end: ");
    print_linked_list(head);

    // Delete a node from the linked list
    delete_node(&head, head->next->next);

    // Print the linked list
    printf("Linked list after deleting a node: ");
    print_linked_list(head);

    return 0;
}