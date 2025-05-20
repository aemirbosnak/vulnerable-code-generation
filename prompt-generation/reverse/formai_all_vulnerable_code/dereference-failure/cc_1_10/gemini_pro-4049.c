//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: Donald Knuth
#include <stdlib.h>
#include <stdio.h>

// A node in a linked list.
struct node {
    int data;
    struct node *next;
};

// The head of the linked list.
struct node *head = NULL;

// The tail of the linked list.
struct node *tail = NULL;

// The size of the linked list.
int size = 0;

// Adds a node to the end of the linked list.
void add_node(int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }

    size++;
}

// Removes a node from the linked list by value.
void remove_node(int data) {
    struct node *current_node = head;
    struct node *previous_node = NULL;

    while (current_node != NULL) {
        if (current_node->data == data) {
            if (previous_node == NULL) {
                head = current_node->next;
            } else {
                previous_node->next = current_node->next;
            }

            if (current_node == tail) {
                tail = previous_node;
            }

            free(current_node);
            size--;
            return;
        }

        previous_node = current_node;
        current_node = current_node->next;
    }
}

// Prints the linked list.
void print_list() {
    struct node *current_node = head;

    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }

    printf("\n");
}

// The main function.
int main() {
    // Add some nodes to the linked list.
    add_node(1);
    add_node(2);
    add_node(3);
    add_node(4);
    add_node(5);

    // Print the linked list.
    print_list();

    // Remove a node from the linked list.
    remove_node(3);

    // Print the linked list again.
    print_list();

    return 0;
}