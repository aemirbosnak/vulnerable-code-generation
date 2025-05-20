//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

// Cyberpunk-themed linked list node struct
typedef struct node_t {
    int data;
    struct node_t *next;
} node;

// Function to create a new node
node *create_node(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Error allocating memory for new node.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a node at the beginning of the list
node *insert_at_beginning(node *head, int data) {
    node *new_node = create_node(data);
    new_node->next = head;
    return new_node;
}

// Function to insert a node at the end of the list
node *insert_at_end(node *head, int data) {
    if (head == NULL) {
        return create_node(data);
    }
    node *current_node = head;
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }
    current_node->next = create_node(data);
    return head;
}

// Function to insert a node after a given node
node *insert_after_node(node *head, node *prev_node, int data) {
    if (prev_node == NULL) {
        printf("Previous node cannot be NULL.\n");
        exit(1);
    }
    node *new_node = create_node(data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    return head;
}

// Function to delete a node from the list
node *delete_node(node *head, int data) {
    if (head == NULL) {
        return NULL;
    }
    node *current_node = head;
    node *prev_node = NULL;
    while (current_node != NULL) {
        if (current_node->data == data) {
            if (prev_node == NULL) {
                head = current_node->next;
            } else {
                prev_node->next = current_node->next;
            }
            free(current_node);
            return head;
        }
        prev_node = current_node;
        current_node = current_node->next;
    }
    printf("Node with data %d not found.\n", data);
    return head;
}

// Function to print the list
void print_list(node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    node *current_node = head;
    printf("List data: ");
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

// Main function
int main() {
    // Create a new linked list
    node *head = NULL;

    // Insert nodes into the list
    head = insert_at_beginning(head, 1);
    head = insert_at_end(head, 2);
    head = insert_at_end(head, 3);
    head = insert_after_node(head, head->next, 4);

    // Print the list
    printf("Initial list:\n");
    print_list(head);

    // Delete a node from the list
    head = delete_node(head, 2);

    // Print the list again
    printf("List after deleting node 2:\n");
    print_list(head);

    return 0;
}