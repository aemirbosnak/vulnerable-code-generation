//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: Donald Knuth
// A mailing list manager in the style of Donald E. Knuth.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A node in the mailing list.
typedef struct node {
    char *name;
    char *email;
    struct node *next;
} node;

// The head of the mailing list.
node *head = NULL;

// Add a new name and email to the mailing list.
void add(char *name, char *email) {
    // Create a new node.
    node *new_node = (node *) malloc(sizeof(node));

    // Copy the name and email into the new node.
    new_node->name = strdup(name);
    new_node->email = strdup(email);

    // Insert the new node at the end of the list.
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
    } else {
        node *current_node = head;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
}

// Print the mailing list.
void print() {
    node *current_node = head;
    while (current_node != NULL) {
        printf("%s (%s)\n", current_node->name, current_node->email);
        current_node = current_node->next;
    }
}

// Free the memory used by the mailing list.
void free_list() {
    node *current_node = head;
    while (current_node != NULL) {
        node *next_node = current_node->next;
        free(current_node->name);
        free(current_node->email);
        free(current_node);
        current_node = next_node;
    }
}

// Main function.
int main() {
    // Add some names and emails to the mailing list.
    add("Donald E. Knuth", "knuth@stanford.edu");
    add("Grace Hopper", "hopper@navy.mil");
    add("Ada Lovelace", "lovelace@oxford.edu");
    add("Charles Babbage", "babbage@cambridge.edu");
    add("Alan Turing", "turing@manchester.edu");

    // Print the mailing list.
    print();

    // Free the memory used by the mailing list.
    free_list();

    return 0;
}