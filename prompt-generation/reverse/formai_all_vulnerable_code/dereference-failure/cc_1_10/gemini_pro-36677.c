//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Linked list node
typedef struct node {
    char *data;
    struct node *next;
} node_t;

// Linked list head
node_t *head = NULL;

// Insert a node at the beginning of a linked list
void insert_node(char *data) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = strdup(data);
    new_node->next = head;
    head = new_node;
}

// Print a linked list
void print_list() {
    node_t *current = head;
    while (current != NULL) {
        printf("%s\n", current->data);
        current = current->next;
    }
}

// Free a linked list
void free_list() {
    node_t *current = head;
    while (current != NULL) {
        node_t *next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
}

// Main function
int main() {
    // Get input from the user
    char input[1024];
    printf("Enter a list of words separated by spaces: ");
    fgets(input, sizeof(input), stdin);

    // Tokenize the input
    char *token = strtok(input, " ");
    while (token != NULL) {
        // Insert the token into the linked list
        insert_node(token);

        // Get the next token
        token = strtok(NULL, " ");
    }

    // Print the linked list
    print_list();

    // Free the linked list
    free_list();

    return 0;
}