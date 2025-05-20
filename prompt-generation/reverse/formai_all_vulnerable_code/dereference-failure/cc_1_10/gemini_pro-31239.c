//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A node in the mailing list
typedef struct node {
    char *email;
    struct node *next;
} node_t;

// The head of the mailing list
node_t *head = NULL;

// Add an email address to the mailing list
void add_email(char *email) {
    // Allocate memory for the new node
    node_t *new_node = malloc(sizeof(node_t));

    // Copy the email address into the new node
    new_node->email = strdup(email);

    // Set the next pointer of the new node to the current head of the list
    new_node->next = head;

    // Update the head of the list to point to the new node
    head = new_node;
}

// Remove an email address from the mailing list
void remove_email(char *email) {
    // If the head of the list is the email we want to remove, simply update the head to point to the next node
    if (strcmp(head->email, email) == 0) {
        head = head->next;
        return;
    }

    // Otherwise, iterate through the list until we find the email we want to remove
    node_t *current = head;
    while (current->next != NULL) {
        if (strcmp(current->next->email, email) == 0) {
            // If we found the email, update the next pointer of the current node to point to the next node of the email we want to remove
            current->next = current->next->next;
            return;
        }

        // Otherwise, move on to the next node
        current = current->next;
    }
}

// Print the mailing list
void print_list() {
    // Iterate through the list and print each email address
    node_t *current = head;
    while (current != NULL) {
        printf("%s\n", current->email);
        current = current->next;
    }
}

// Free the memory allocated for the mailing list
void free_list() {
    // Iterate through the list and free each node
    node_t *current = head;
    while (current != NULL) {
        node_t *next = current->next;
        free(current->email);
        free(current);
        current = next;
    }
}

int main() {
    // Add some email addresses to the mailing list
    add_email("john@example.com");
    add_email("jane@example.com");
    add_email("bob@example.com");

    // Print the mailing list
    print_list();

    // Remove an email address from the mailing list
    remove_email("bob@example.com");

    // Print the mailing list again
    print_list();

    // Free the memory allocated for the mailing list
    free_list();

    return 0;
}