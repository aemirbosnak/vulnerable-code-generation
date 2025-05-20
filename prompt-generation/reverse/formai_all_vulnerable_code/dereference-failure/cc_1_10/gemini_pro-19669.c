//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Enumerated data type for phone book entries
enum Person {
    NAME,
    NUMBER
};

// Structure for a single phone book entry
struct Entry {
    char *name;
    char *number;
};

// Linked list node for the phone book
struct Node {
    struct Entry entry;
    struct Node *next;
};

// Head of the phone book linked list
struct Node *head = NULL;

// Insert a new entry into the phone book
void insert(char *name, char *number) {
    // Create a new node
    struct Node *new_node = malloc(sizeof(struct Node));

    // Set the name and number of the new node
    new_node->entry.name = strdup(name);
    new_node->entry.number = strdup(number);

    // Insert the new node at the beginning of the linked list
    new_node->next = head;
    head = new_node;
}

// Search for a phone number by name
char *find(char *name) {
    // Traverse the linked list
    struct Node *current = head;
    while (current != NULL) {
        // Check if the name matches the current node
        if (strcmp(current->entry.name, name) == 0) {
            // Return the number
            return current->entry.number;
        }

        // Move to the next node
        current = current->next;
    }

    // Name not found
    return NULL;
}

// Print the phone book
void print() {
    // Traverse the linked list
    struct Node *current = head;
    while (current != NULL) {
        // Print the name and number
        printf("%s: %s\n", current->entry.name, current->entry.number);

        // Move to the next node
        current = current->next;
    }
}

// Free the memory allocated for the phone book
void free_phone_book() {
    // Traverse the linked list
    struct Node *current = head;
    while (current != NULL) {
        // Free the memory for the name and number
        free(current->entry.name);
        free(current->entry.number);

        // Free the memory for the node
        free(current);

        // Move to the next node
        current = current->next;
    }

    // Set the head to NULL
    head = NULL;
}

// Main function
int main() {
    // Insert some entries into the phone book
    insert("John Doe", "555-1212");
    insert("Jane Smith", "555-1213");
    insert("Bill Jones", "555-1214");

    // Search for a phone number by name
    char *number = find("John Doe");

    // Print the phone number
    printf("John Doe's phone number is: %s\n", number);

    // Print the phone book
    print();

    // Free the memory allocated for the phone book
    free_phone_book();

    return 0;
}