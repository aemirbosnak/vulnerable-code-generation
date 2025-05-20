//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

// A node in the phone book
struct node {
    char name[20];
    char number[11];
    struct node *next;
};

// The head of the phone book
struct node *head = NULL;

// Add a new node to the phone book
void add(char *name, char *number) {
    // Create a new node
    struct node *new_node = malloc(sizeof(struct node));

    // Copy the name and number into the new node
    strcpy(new_node->name, name);
    strcpy(new_node->number, number);

    // Add the new node to the phone book
    new_node->next = head;
    head = new_node;
}

// Find a node in the phone book
struct node *find(char *name) {
    // Start at the head of the phone book
    struct node *current = head;

    // While the current node is not NULL
    while (current != NULL) {
        // If the current node's name matches the given name
        if (strcmp(current->name, name) == 0) {
            // Return the current node
            return current;
        }

        // Move to the next node
        current = current->next;
    }

    // If the node was not found, return NULL
    return NULL;
}

// Delete a node from the phone book
void delete(char *name) {
    // Find the node to delete
    struct node *node_to_delete = find(name);

    // If the node was found
    if (node_to_delete != NULL) {
        // If the node is the head of the phone book
        if (node_to_delete == head) {
            // Set the head of the phone book to the next node
            head = head->next;
        } else {
            // Find the node before the node to delete
            struct node *prev = head;
            while (prev->next != node_to_delete) {
                prev = prev->next;
            }

            // Set the next pointer of the previous node to the next node of the node to delete
            prev->next = node_to_delete->next;
        }

        // Free the node to delete
        free(node_to_delete);
    }
}

// Print the phone book
void print() {
    // Start at the head of the phone book
    struct node *current = head;

    // While the current node is not NULL
    while (current != NULL) {
        // Print the current node's name and number
        printf("%s: %s\n", current->name, current->number);

        // Move to the next node
        current = current->next;
    }
}

// Main function
int main() {
    // Add some names and numbers to the phone book
    add("Romeo", "555-1234");
    add("Juliet", "555-5678");
    add("Tybalt", "555-9876");

    // Print the phone book
    print();

    // Find a name in the phone book
    struct node *node = find("Romeo");

    // If the name was found
    if (node != NULL) {
        // Print the name and number
        printf("Found: %s: %s\n", node->name, node->number);
    } else {
        // Print an error message
        printf("Not found: Romeo\n");
    }

    // Delete a name from the phone book
    delete("Tybalt");

    // Print the phone book
    print();

    return 0;
}