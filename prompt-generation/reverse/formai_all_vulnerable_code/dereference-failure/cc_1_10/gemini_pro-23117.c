//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char *data;
    struct node *next;
} node_t;

node_t *head = NULL;  // Head of the linked list
node_t *tail = NULL;  // Tail of the linked list

// Insert a new node at the end of the linked list
void insert_node(char *data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
}

// Delete a node from the linked list
void delete_node(char *data) {
    node_t *current_node = head;
    node_t *previous_node = NULL;

    while (current_node != NULL) {
        if (strcmp(current_node->data, data) == 0) {
            if (current_node == head) {
                head = current_node->next;
            } else {
                previous_node->next = current_node->next;
            }
            free(current_node);
            break;
        }

        previous_node = current_node;
        current_node = current_node->next;
    }
}

// Print the linked list
void print_list() {
    node_t *current_node = head;

    while (current_node != NULL) {
        printf("%s ", current_node->data);
        current_node = current_node->next;
    }

    printf("\n");
}

// Free the linked list
void free_list() {
    node_t *current_node = head;

    while (current_node != NULL) {
        node_t *next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }

    head = NULL;
    tail = NULL;
}

int main() {
    // Insert some data into the linked list
    insert_node("Hello");
    insert_node("World");
    insert_node("!");

    // Print the linked list
    print_list();

    // Delete a node from the linked list
    delete_node("World");

    // Print the linked list
    print_list();

    // Free the linked list
    free_list();

    return 0;
}