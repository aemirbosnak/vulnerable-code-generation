//GEMINI-pro DATASET v1.0 Category: Password management ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for the password list
typedef struct node {
    char *password;
    struct node *next;
} node_t;

// Function to add a password to the list
void add_password(node_t **head, char *password) {
    // Create a new node
    node_t *new_node = malloc(sizeof(node_t));
    new_node->password = strdup(password);
    new_node->next = NULL;

    // Add the new node to the front of the list
    new_node->next = *head;
    *head = new_node;
}

// Function to remove a password from the list
void remove_password(node_t **head, char *password) {
    // Check if the list is empty
    if (*head == NULL) {
        return;
    }

    // Check if the first node is the one to be removed
    if (strcmp((*head)->password, password) == 0) {
        *head = (*head)->next;
        return;
    }

    // Recursively remove the password from the rest of the list
    remove_password(&(*head)->next, password);
}

// Function to print the list of passwords
void print_passwords(node_t *head) {
    // Check if the list is empty
    if (head == NULL) {
        return;
    }

    // Print the current password
    printf("%s\n", head->password);

    // Recursively print the rest of the list
    print_passwords(head->next);
}

// Function to free the memory allocated for the list
void free_list(node_t *head) {
    // Check if the list is empty
    if (head == NULL) {
        return;
    }

    // Free the current node
    free(head->password);
    free(head);

    // Recursively free the rest of the list
    free_list(head->next);
}

// Main function
int main() {
    // Create a new password list
    node_t *head = NULL;

    // Add some passwords to the list
    add_password(&head, "password1");
    add_password(&head, "password2");
    add_password(&head, "password3");

    // Print the list of passwords
    print_passwords(head);

    // Remove a password from the list
    remove_password(&head, "password2");

    // Print the list of passwords again
    print_passwords(head);

    // Free the memory allocated for the list
    free_list(head);

    return 0;
}