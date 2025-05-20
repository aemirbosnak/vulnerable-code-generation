//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A node in the mailing list
typedef struct node {
    char *email;
    struct node *next;
} node;

// The head of the mailing list
node *head = NULL;

// Add a new email to the mailing list
void add_email(char *email) {
    // Create a new node
    node *new_node = malloc(sizeof(node));
    new_node->email = strdup(email);
    new_node->next = NULL;

    // Add the new node to the end of the list
    if (head == NULL) {
        head = new_node;
    } else {
        node *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Remove an email from the mailing list
void remove_email(char *email) {
    // Find the node with the given email
    node *current = head;
    node *previous = NULL;
    while (current != NULL && strcmp(current->email, email) != 0) {
        previous = current;
        current = current->next;
    }

    // If the node was found, remove it from the list
    if (current != NULL) {
        if (previous == NULL) {
            head = current->next;
        } else {
            previous->next = current->next;
        }
        free(current->email);
        free(current);
    }
}

// Print the mailing list
void print_mailing_list() {
    node *current = head;
    while (current != NULL) {
        printf("%s\n", current->email);
        current = current->next;
    }
}

// Get the number of emails in the mailing list
int get_num_emails() {
    int count = 0;
    node *current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Free the mailing list
void free_mailing_list() {
    node *current = head;
    while (current != NULL) {
        node *next = current->next;
        free(current->email);
        free(current);
        current = next;
    }
    head = NULL;
}

// Main function
int main() {
    // Add some emails to the mailing list
    add_email("john@example.com");
    add_email("mary@example.com");
    add_email("bob@example.com");

    // Print the mailing list
    printf("Mailing list:\n");
    print_mailing_list();

    // Get the number of emails in the mailing list
    int num_emails = get_num_emails();
    printf("Number of emails: %d\n", num_emails);

    // Remove an email from the mailing list
    remove_email("bob@example.com");

    // Print the mailing list again
    printf("\nMailing list after removing bob@example.com:\n");
    print_mailing_list();

    // Free the mailing list
    free_mailing_list();

    return 0;
}