//LLAMA2-13B DATASET v1.0 Category: Syntax parsing ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the custom syntax
#define SYNTAX_STRING "if (x > 5) { y = 10; z = 20; } else { w = 30; v = 40; }"

// Define the syntax elements
#define ELEM_IF 1
#define ELEM_THEN 2
#define ELEM_ELSE 3
#define ELEM_VAR 4

// Define the syntax tree structure
typedef struct {
    int type; // ELEM_IF, ELEM_THEN, ELEM_ELSE, or ELEM_VAR
    int index; // The index of the variable in the syntax tree
    struct node *next; // The next node in the syntax tree
} node_t;

// Define the root node of the syntax tree
node_t *root;

// Parse the custom syntax
void parse(void) {
    // Initialize the root node
    root = NULL;

    // Tokenize the custom syntax
    char *token = strtok(SYNTAX_STRING, " ");
    while (token != NULL) {
        // Create a new node for each token
        node_t *new_node = malloc(sizeof(node_t));
        new_node->type = ELEM_VAR;
        new_node->index = -1;
        new_node->next = NULL;

        // Add the new node to the syntax tree
        if (root == NULL) {
            root = new_node;
        } else {
            root->next = new_node;
        }

        // Advance to the next token
        token = strtok(NULL, " ");
    }
}

// Print the syntax tree
void print(void) {
    // Traverse the syntax tree
    node_t *current = root;
    while (current != NULL) {
        // Print the type and index of the current node
        switch (current->type) {
            case ELEM_IF:
                printf("IF\n");
                break;
            case ELEM_THEN:
                printf("THEN\n");
                break;
            case ELEM_ELSE:
                printf("ELSE\n");
                break;
            case ELEM_VAR:
                printf("VAR %d\n", current->index);
                break;
        }

        // Advance to the next node
        current = current->next;
    }
}

int main(void) {
    // Parse the custom syntax
    parse();

    // Print the syntax tree
    print();

    return 0;
}