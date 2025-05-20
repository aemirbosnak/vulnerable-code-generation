//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A node in the phone book
typedef struct node {
    char *name;
    char *number;
    struct node *next;
} node_t;

// The head of the phone book
node_t *head = NULL;

// Inserts a new node into the phone book
void insert_node(char *name, char *number) {
    // Create a new node
    node_t *new_node = malloc(sizeof(node_t));
    new_node->name = malloc(strlen(name) + 1);
    new_node->number = malloc(strlen(number) + 1);
    strcpy(new_node->name, name);
    strcpy(new_node->number, number);
    new_node->next = NULL;

    // Insert the new node at the head of the phone book
    new_node->next = head;
    head = new_node;
}

// Searches for a name in the phone book
char *search_phone_book(char *name) {
    // Iterate over the phone book
    node_t *current_node = head;
    while (current_node != NULL) {
        // If the name matches, return the number
        if (strcmp(current_node->name, name) == 0) {
            return current_node->number;
        }

        // Move to the next node
        current_node = current_node->next;
    }

    // The name was not found
    return NULL;
}

// Prints the phone book
void print_phone_book() {
    // Iterate over the phone book
    node_t *current_node = head;
    while (current_node != NULL) {
        // Print the name and number
        printf("%s: %s\n", current_node->name, current_node->number);

        // Move to the next node
        current_node = current_node->next;
    }
}

// Frees the memory allocated for the phone book
void free_phone_book() {
    // Iterate over the phone book
    node_t *current_node = head;
    while (current_node != NULL) {
        // Free the memory allocated for the name and number
        free(current_node->name);
        free(current_node->number);

        // Move to the next node
        node_t *next_node = current_node->next;

        // Free the memory allocated for the node
        free(current_node);

        // Update the current node
        current_node = next_node;
    }

    // Set the head of the phone book to NULL
    head = NULL;
}

// The main function
int main() {
    // Insert some names and numbers into the phone book
    insert_node("Alice", "123-456-7890");
    insert_node("Bob", "234-567-8901");
    insert_node("Charlie", "345-678-9012");

    // Search for a name in the phone book
    char *number = search_phone_book("Alice");
    if (number != NULL) {
        printf("The number for Alice is %s\n", number);
    } else {
        printf("The name Alice was not found in the phone book\n");
    }

    // Print the phone book
    print_phone_book();

    // Free the memory allocated for the phone book
    free_phone_book();

    return 0;
}