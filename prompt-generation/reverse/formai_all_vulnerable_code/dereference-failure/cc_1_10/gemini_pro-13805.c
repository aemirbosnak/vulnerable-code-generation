//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a node in a linked list.
typedef struct node {
    char *data;
    struct node *next;
} node;

// Create a new node with the given data.
node *create_node(char *data) {
    node *new_node = malloc(sizeof(node));
    new_node->data = strdup(data);
    new_node->next = NULL;
    return new_node;
}

// Insert a new node at the beginning of the linked list.
void insert_at_beginning(node **head, node *new_node) {
    new_node->next = *head;
    *head = new_node;
}

// Insert a new node after the given node.
void insert_after(node *prev_node, node *new_node) {
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Delete the given node from the linked list.
void delete_node(node **head, node *del_node) {
    if (del_node == *head) {
        *head = del_node->next;
    } else {
        node *prev_node = *head;
        while (prev_node->next != del_node) {
            prev_node = prev_node->next;
        }
        prev_node->next = del_node->next;
    }
    free(del_node->data);
    free(del_node);
}

// Print the linked list.
void print_list(node *head) {
    node *current_node = head;
    while (current_node != NULL) {
        printf("%s ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

// Free the linked list.
void free_list(node *head) {
    node *current_node = head;
    while (current_node != NULL) {
        node *next_node = current_node->next;
        free(current_node->data);
        free(current_node);
        current_node = next_node;
    }
}

int main() {
    // Create a linked list of strings.
    node *head = NULL;
    insert_at_beginning(&head, create_node("Hello"));
    insert_at_beginning(&head, create_node("World"));
    insert_at_beginning(&head, create_node("This"));
    insert_at_beginning(&head, create_node("is"));
    insert_at_beginning(&head, create_node("a"));
    insert_at_beginning(&head, create_node("linked"));
    insert_at_beginning(&head, create_node("list"));

    // Print the linked list.
    print_list(head);

    // Insert a new node after the second node.
    node *second_node = head->next;
    insert_after(second_node, create_node("of"));

    // Print the linked list.
    print_list(head);

    // Delete the third node.
    node *third_node = head->next->next;
    delete_node(&head, third_node);

    // Print the linked list.
    print_list(head);

    // Free the linked list.
    free_list(head);

    return 0;
}