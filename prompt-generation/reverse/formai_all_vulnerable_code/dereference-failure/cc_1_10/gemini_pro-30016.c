//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Data structure to store a single node in a linked list
struct node {
    int data;
    struct node *next;
};

// Function to create a new node with the given data
struct node *create_node(int data) {
    struct node *new_node = malloc(sizeof(struct node));
    if (!new_node) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a new node at the head of a linked list
void insert_at_head(struct node **head, int data) {
    struct node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Function to delete a node from a linked list
void delete_node(struct node **head, int data) {
    struct node *current = *head;
    struct node *prev = NULL;
    while (current) {
        if (current->data == data) {
            if (!prev) {
                *head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

// Function to print a linked list
void print_list(struct node *head) {
    struct node *current = head;
    while (current) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct node *head = NULL;

    // Insert some nodes into the linked list
    insert_at_head(&head, 10);
    insert_at_head(&head, 20);
    insert_at_head(&head, 30);

    // Print the linked list
    print_list(head);

    // Delete a node from the linked list
    delete_node(&head, 20);

    // Print the linked list
    print_list(head);

    return 0;
}