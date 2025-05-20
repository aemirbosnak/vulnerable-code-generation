//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

// Define a node for the linked list
struct node {
    char *data;
    struct node *next;
};

// Create a new node
struct node *create_node(char *data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Insert a node at the beginning of the linked list
void insert_at_beginning(struct node **head, char *data) {
    struct node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Insert a node at the end of the linked list
void insert_at_end(struct node **head, char *data) {
    struct node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
    } else {
        struct node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Delete a node from the linked list
void delete_node(struct node **head, char *data) {
    struct node *current = *head;
    struct node *previous = NULL;
    while (current != NULL) {
        if (strcmp(current->data, data) == 0) {
            if (previous == NULL) {
                *head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            break;
        }
        previous = current;
        current = current->next;
    }
}

// Print the linked list
void print_list(struct node *head) {
    struct node *current = head;
    while (current != NULL) {
        printf("%s\n", current->data);
        current = current->next;
    }
}

// Free the linked list
void free_list(struct node *head) {
    struct node *current = head;
    while (current != NULL) {
        struct node *next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    // Create an empty linked list
    struct node *head = NULL;

    // Insert some data into the linked list
    insert_at_beginning(&head, "Hello");
    insert_at_end(&head, "World");
    insert_at_beginning(&head, "This");
    insert_at_end(&head, "is");
    insert_at_beginning(&head, "a");
    insert_at_end(&head, "linked");
    insert_at_beginning(&head, "list");

    // Print the linked list
    printf("Original linked list:\n");
    print_list(head);

    // Delete a node from the linked list
    delete_node(&head, "This");

    // Print the linked list after deleting a node
    printf("Linked list after deleting a node:\n");
    print_list(head);

    // Free the linked list
    free_list(head);

    return 0;
}