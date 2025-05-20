//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a single node in the linked list
typedef struct node {
    int data;
    struct node *next;
} node_t;

// Function to create a new node with the given data
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

// Function to insert a new node at the end of the linked list
void insert_node(node_t **head, int data) {
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
}

// Function to print the linked list
void print_list(node_t *head) {
    node_t *current_node = head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

// Function to reverse the linked list using the iterative approach
node_t *reverse_list_iterative(node_t *head) {
    node_t *prev = NULL;
    node_t *current = head;
    node_t *next;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

// Function to reverse the linked list using the recursive approach
node_t *reverse_list_recursive(node_t *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    node_t *new_head = reverse_list_recursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return new_head;
}

// Main function to test the linked list reversal functions
int main() {
    // Create a linked list
    node_t *head = NULL;
    insert_node(&head, 1);
    insert_node(&head, 2);
    insert_node(&head, 3);
    insert_node(&head, 4);
    insert_node(&head, 5);

    // Print the original linked list
    printf("Original linked list: ");
    print_list(head);

    // Reverse the linked list using the iterative approach
    node_t *reversed_list_iterative = reverse_list_iterative(head);

    // Print the reversed linked list using the iterative approach
    printf("Reversed linked list (iterative approach): ");
    print_list(reversed_list_iterative);

    // Reverse the linked list using the recursive approach
    node_t *reversed_list_recursive = reverse_list_recursive(head);

    // Print the reversed linked list using the recursive approach
    printf("Reversed linked list (recursive approach): ");
    print_list(reversed_list_recursive);

    return 0;
}