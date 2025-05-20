//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for the mailing list
typedef struct node {
    char *email;
    struct node *next;
} node_t;

// Head of the mailing list
node_t *head = NULL;

// Function to add a new email address to the mailing list
void add_email(char *email) {
    // Create a new node for the email address
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->email = strdup(email);
    new_node->next = NULL;

    // Add the new node to the mailing list
    if (head == NULL) {
        head = new_node;
    } else {
        node_t *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Function to remove an email address from the mailing list
void remove_email(char *email) {
    // Find the node for the email address
    node_t *current = head;
    node_t *previous = NULL;
    while (current != NULL && strcmp(current->email, email) != 0) {
        previous = current;
        current = current->next;
    }

    // If the email address was found, remove it from the mailing list
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

// Function to send a message to all email addresses in the mailing list
void send_message(char *message) {
    // Iterate over the mailing list and send the message to each email address
    node_t *current = head;
    while (current != NULL) {
        // Send the message to the email address
        printf("Sending message to %s\n", current->email);
        current = current->next;
    }
}

// Function to print the mailing list
void print_mailing_list() {
    // Iterate over the mailing list and print each email address
    node_t *current = head;
    while (current != NULL) {
        printf("%s\n", current->email);
        current = current->next;
    }
}

// Main function
int main() {
    // Add some email addresses to the mailing list
    add_email("john@example.com");
    add_email("mary@example.com");
    add_email("bob@example.com");

    // Print the mailing list
    printf("Mailing list:\n");
    print_mailing_list();

    // Send a message to the mailing list
    printf("\nSending message to mailing list:\n");
    send_message("Hello, world!");

    // Remove an email address from the mailing list
    printf("\nRemoving \"bob@example.com\" from mailing list:\n");
    remove_email("bob@example.com");

    // Print the mailing list
    printf("\nMailing list after removing \"bob@example.com\":\n");
    print_mailing_list();

    return 0;
}