//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

node_t *head = NULL;

void add_node(int data) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

void print_list() {
    node_t *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void free_list() {
    node_t *current = head;
    while (current != NULL) {
        node_t *next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
}

int main() {
    // Linus Torvalds style comments

    /* This is a linked list example program. It's not the most efficient,
       but it's easy to understand. */

    /* First, we define a node structure. This structure will hold the data
       for each node in the list, as well as a pointer to the next node. */

    /* Next, we define a head pointer. This pointer will point to the first
       node in the list. If the list is empty, the head pointer will be NULL. */

    /* Now, we can start adding nodes to the list. We do this by calling the
       add_node() function. This function takes a data value as an argument and
       creates a new node with that data value. The new node is then added to
       the beginning of the list. */

    add_node(1);
    add_node(2);
    add_node(3);

    /* Now that we have added some nodes to the list, we can print the list
       to the console. We do this by calling the print_list() function. */

    print_list();

    /* Finally, we can free the memory that was allocated for the list. We do
       this by calling the free_list() function. */

    free_list();

    return 0;
}