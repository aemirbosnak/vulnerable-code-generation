//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

// A node in the linked list
struct node {
    int data;
    struct node *next;
};

// The head of the linked list
struct node *head = NULL;

// Create a new node with the given data
struct node *create_node(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Insert a new node at the beginning of the linked list
void insert_at_beginning(int data) {
    struct node *new_node = create_node(data);
    new_node->next = head;
    head = new_node;
}

// Insert a new node at the end of the linked list
void insert_at_end(int data) {
    struct node *new_node = create_node(data);
    if (head == NULL) {
        head = new_node;
    } else {
        struct node *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Insert a new node after a given node
void insert_after(struct node *prev_node, int data) {
    if (prev_node == NULL) {
        printf("Previous node cannot be NULL");
        return;
    }
    struct node *new_node = create_node(data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Delete a node from the linked list
void delete_node(struct node *node) {
    if (node == NULL) {
        printf("Node cannot be NULL");
        return;
    }
    if (node == head) {
        head = head->next;
    } else {
        struct node *current = head;
        while (current->next != node) {
            current = current->next;
        }
        current->next = node->next;
    }
    free(node);
}

// Print the linked list
void print_list() {
    struct node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main function
int main() {
    // Insert some nodes into the linked list
    insert_at_beginning(1);
    insert_at_end(2);
    insert_after(head, 3);

    // Print the linked list
    print_list();

    // Delete a node from the linked list
    delete_node(head->next);

    // Print the linked list again
    print_list();

    return 0;
}