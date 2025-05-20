//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Define a custom data structure to represent a node in a linked list
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Function to create a new node with the given data
Node *create_node(int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error: Failed to allocate memory for new node.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to add a new node to the beginning of a linked list
Node *add_to_head(Node *head, int data) {
    Node *new_node = create_node(data);
    if (head == NULL) {
        head = new_node;
    } else {
        new_node->next = head;
        head = new_node;
    }
    return head;
}

// Function to add a new node to the end of a linked list
Node *add_to_tail(Node *head, int data) {
    Node *new_node = create_node(data);
    if (head == NULL) {
        head = new_node;
    } else {
        Node *current_node = head;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
    return head;
}

// Function to insert a new node after a given node
Node *insert_after(Node *head, Node *prev_node, int data) {
    if (prev_node == NULL) {
        printf("Error: Previous node cannot be NULL.\n");
        exit(1);
    }
    Node *new_node = create_node(data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    return head;
}

// Function to delete a node from a linked list
Node *delete_node(Node *head, Node *node) {
    if (node == NULL) {
        printf("Error: Node cannot be NULL.\n");
        exit(1);
    }
    if (node == head) {
        head = node->next;
    } else {
        Node *current_node = head;
        while (current_node->next != node) {
            current_node = current_node->next;
        }
        current_node->next = node->next;
    }
    free(node);
    return head;
}

// Function to print the contents of a linked list
void print_linked_list(Node *head) {
    Node *current_node = head;
    while (current_node != NULL) {
        printf("%d -> ", current_node->data);
        current_node = current_node->next;
    }
    printf("NULL\n");
}

// Main function to test the memory management functions
int main() {
    // Create an empty linked list
    Node *head = NULL;

    // Add some nodes to the linked list
    head = add_to_head(head, 1);
    head = add_to_tail(head, 2);
    head = add_to_tail(head, 3);
    head = insert_after(head, head->next, 4);

    // Print the contents of the linked list
    print_linked_list(head);

    // Delete a node from the linked list
    head = delete_node(head, head->next);

    // Print the contents of the linked list again
    print_linked_list(head);

    // Free the entire linked list
    while (head != NULL) {
        head = delete_node(head, head);
    }

    return 0;
}