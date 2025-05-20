//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Node structure for a linked list
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Function to create a new node with the given data
Node *create_node(int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a new node at the beginning of the linked list
Node *insert_at_beginning(Node *head, int data) {
    Node *new_node = create_node(data);
    new_node->next = head;
    return new_node;
}

// Function to insert a new node at the end of the linked list
Node *insert_at_end(Node *head, int data) {
    Node *new_node = create_node(data);
    if (head == NULL) {
        return new_node;
    }

    Node *current_node = head;
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }

    current_node->next = new_node;
    return head;
}

// Function to insert a new node after a given node in the linked list
Node *insert_after(Node *head, int data, int after) {
    Node *new_node = create_node(data);
    if (head == NULL) {
        return new_node;
    }

    Node *current_node = head;
    while (current_node != NULL && current_node->data != after) {
        current_node = current_node->next;
    }

    if (current_node == NULL) {
        return head;  // Node not found, do nothing
    }

    new_node->next = current_node->next;
    current_node->next = new_node;
    return head;
}

// Function to delete a node from the linked list
Node *delete_node(Node *head, int data) {
    if (head == NULL) {
        return NULL;  // List is empty, do nothing
    }

    if (head->data == data) {
        Node *new_head = head->next;
        free(head);
        return new_head;
    }

    Node *current_node = head;
    while (current_node->next != NULL && current_node->next->data != data) {
        current_node = current_node->next;
    }

    if (current_node->next == NULL) {
        return head;  // Node not found, do nothing
    }

    Node *node_to_delete = current_node->next;
    current_node->next = node_to_delete->next;
    free(node_to_delete);
    return head;
}

// Function to print the linked list
void print_linked_list(Node *head) {
    printf("Linked list: ");
    Node *current_node = head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

// Main function
int main() {
    // Create a linked list
    Node *head = NULL;
    head = insert_at_beginning(head, 10);
    head = insert_at_end(head, 20);
    head = insert_at_end(head, 30);
    head = insert_after(head, 40, 20);

    // Print the linked list
    print_linked_list(head);

    // Delete a node from the linked list
    head = delete_node(head, 20);

    // Print the linked list
    print_linked_list(head);

    return 0;
}