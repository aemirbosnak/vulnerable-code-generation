//GEMINI-pro DATASET v1.0 Category: Password management ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A simple linked list to store passwords
typedef struct node {
    char *password;
    struct node *next;
} node;

// The head of the linked list
node *head = NULL;

// Add a password to the linked list
void add_password(char *password) {
    // Create a new node
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(1);
    }

    // Copy the password into the new node
    new_node->password = strdup(password);
    if (new_node->password == NULL) {
        fprintf(stderr, "Error: strdup failed\n");
        exit(1);
    }

    // Add the new node to the linked list
    new_node->next = head;
    head = new_node;
}

// Print the passwords in the linked list
void print_passwords() {
    // Iterate over the linked list
    node *current = head;
    while (current != NULL) {
        // Print the password
        printf("%s\n", current->password);

        // Move to the next node
        current = current->next;
    }
}

// Free the memory allocated for the linked list
void free_passwords() {
    // Iterate over the linked list
    node *current = head;
    while (current != NULL) {
        // Free the password
        free(current->password);

        // Free the node
        node *next = current->next;
        free(current);

        // Move to the next node
        current = next;
    }

    // Set the head to NULL
    head = NULL;
}

// Get a password from the user
char *get_password() {
    // Prompt the user for a password
    printf("Enter a password: ");

    // Read the password from the user
    char *password = malloc(1024);
    if (password == NULL) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(1);
    }
    fgets(password, 1024, stdin);

    // Remove the newline from the password
    password[strcspn(password, "\n")] = '\0';

    // Return the password
    return password;
}

// The main function
int main() {
    // Add some passwords to the linked list
    add_password("password1");
    add_password("password2");
    add_password("password3");

    // Print the passwords in the linked list
    print_passwords();

    // Get a password from the user
    char *password = get_password();

    // Check if the password is in the linked list
    node *current = head;
    while (current != NULL) {
        if (strcmp(current->password, password) == 0) {
            // The password is in the linked list
            printf("The password is in the list\n");
            break;
        }

        // Move to the next node
        current = current->next;
    }

    // Free the memory allocated for the linked list
    free_passwords();

    // Free the memory allocated for the password
    free(password);

    return 0;
}