//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: unmistakable
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// A node in the mailing list.
struct node {
    char *email;
    struct node *next;
};

// The head of the mailing list.
struct node *head = NULL;

// Add an email to the mailing list.
void add_email(char *email) {
    // Create a new node.
    struct node *new_node = malloc(sizeof(struct node));
    new_node->email = strdup(email);
    new_node->next = NULL;

    // Add the new node to the end of the list.
    if (head == NULL) {
        head = new_node;
    } else {
        struct node *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Remove an email from the mailing list.
void remove_email(char *email) {
    // Find the node with the given email.
    struct node *current = head;
    struct node *prev = NULL;
    while (current != NULL && strcmp(current->email, email) != 0) {
        prev = current;
        current = current->next;
    }

    // If the node was not found, return.
    if (current == NULL) {
        return;
    }

    // Remove the node from the list.
    if (prev == NULL) {
        head = current->next;
    } else {
        prev->next = current->next;
    }

    // Free the node.
    free(current->email);
    free(current);
}

// Send a message to all emails in the mailing list.
void send_message(char *message) {
    // Iterate over the list and send the message to each email.
    struct node *current = head;
    while (current != NULL) {
        printf("Sending message to %s\n", current->email);
        current = current->next;
    }
}

// Free the mailing list.
void free_mailing_list() {
    // Iterate over the list and free each node.
    struct node *current = head;
    while (current != NULL) {
        struct node *next = current->next;
        free(current->email);
        free(current);
        current = next;
    }

    // Set the head to NULL.
    head = NULL;
}

// Main function.
int main() {
    // Add some emails to the mailing list.
    add_email("john@example.com");
    add_email("mary@example.com");
    add_email("bob@example.com");

    // Send a message to the mailing list.
    send_message("Hello, world!");

    // Remove an email from the mailing list.
    remove_email("bob@example.com");

    // Free the mailing list.
    free_mailing_list();

    return 0;
}