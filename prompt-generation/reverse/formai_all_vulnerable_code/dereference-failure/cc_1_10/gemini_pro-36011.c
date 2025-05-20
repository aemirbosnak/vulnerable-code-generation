//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// Define a node for a linked list
struct node {
    int data;
    struct node *next;
};

// Create a new node with the given data
struct node *create_node(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Insert a new node at the beginning of the linked list
void insert_at_beginning(struct node **head, int data) {
    struct node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Insert a new node at the end of the linked list
void insert_at_end(struct node **head, int data) {
    struct node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    struct node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
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
void delete_node(struct node **head, int data) {
    struct node *current = *head;
    struct node *prev = NULL;
    while (current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Node with data %d not found", data);
        return;
    }
    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }
    free(current);
}

// Print the linked list
void print_linked_list(struct node *head) {
    struct node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    // Create a linked list
    struct node *head = NULL;
    insert_at_beginning(&head, 10);
    insert_at_end(&head, 20);
    insert_after(head, 15);
    print_linked_list(head);  // Output: 10 -> 15 -> 20 -> NULL

    // Delete a node from the linked list
    delete_node(&head, 15);
    print_linked_list(head);  // Output: 10 -> 20 -> NULL

    return 0;
}