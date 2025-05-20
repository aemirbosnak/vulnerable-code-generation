//Falcon2-11B DATASET v1.0 Category: Interprocess communication ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a node in a doubly-linked list
typedef struct {
    char data[100];
    struct node *next;
    struct node *prev;
} node;

// Function to initialize a node
void init_node(node *node) {
    strcpy(node->data, "INITIALIZED NODE");
    node->next = NULL;
    node->prev = NULL;
}

// Function to print a node
void print_node(node *node) {
    printf("Data: %s\n", node->data);
}

// Function to add a node to the end of the list
void append_node(node **head_ref, const char *data) {
    node *new_node = malloc(sizeof(node));
    init_node(new_node);

    if (*head_ref == NULL) {
        *head_ref = new_node;
    } else {
        node *current = *head_ref;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = new_node;
        new_node->prev = current;
    }

    strcpy(new_node->data, data);
}

// Function to remove the first occurrence of a node with specific data from the list
void remove_node(node **head_ref, const char *data) {
    if (*head_ref == NULL) {
        return;
    }

    node *current = *head_ref;
    node *previous = NULL;

    while (current!= NULL) {
        if (strcmp(current->data, data) == 0) {
            if (previous == NULL) {
                *head_ref = current->next;
            } else {
                previous->next = current->next;
            }

            free(current);
            return;
        }

        previous = current;
        current = current->next;
    }
}

// Function to search for a node with specific data in the list
node *search_node(node *head, const char *data) {
    node *current = head;

    while (current!= NULL) {
        if (strcmp(current->data, data) == 0) {
            return current;
        }

        current = current->next;
    }

    return NULL;
}

// Function to iterate through the list and print all nodes
void iterate_list(node *head) {
    node *current = head;

    while (current!= NULL) {
        printf("Data: %s\n", current->data);
        current = current->next;
    }
}

// Main function
int main() {
    node *head = NULL;
    append_node(&head, "Hello");
    append_node(&head, "World");
    append_node(&head, "How");
    append_node(&head, "Are");
    append_node(&head, "You?");

    printf("Initial list: ");
    iterate_list(head);

    remove_node(&head, "Hello");
    remove_node(&head, "How");

    printf("Modified list: ");
    iterate_list(head);

    node *found = search_node(head, "You?");
    if (found!= NULL) {
        printf("Node found: %s\n", found->data);
    } else {
        printf("Node not found\n");
    }

    return 0;
}