//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A node in our linked list
typedef struct node {
    char *email;
    struct node *next;
} node;

// The head of our linked list
node *head = NULL;

// Add a new email to the list
void add_email(char *email) {
    // Create a new node
    node *new_node = malloc(sizeof(node));
    new_node->email = strdup(email);
    new_node->next = NULL;

    // If the list is empty, make the new node the head
    if (head == NULL) {
        head = new_node;
        return;
    }

    // Otherwise, add the new node to the end of the list
    node *current_node = head;
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }
    current_node->next = new_node;
}

// Remove an email from the list
void remove_email(char *email) {
    // If the list is empty, return
    if (head == NULL) {
        return;
    }

    // If the first node is the one we want to remove, make the next node the head
    if (strcmp(head->email, email) == 0) {
        head = head->next;
        return;
    }

    // Otherwise, find the node we want to remove and remove it
    node *current_node = head;
    while (current_node->next != NULL) {
        if (strcmp(current_node->next->email, email) == 0) {
            node *temp = current_node->next;
            current_node->next = temp->next;
            free(temp);
            return;
        }
        current_node = current_node->next;
    }
}

// Print the list of emails
void print_list() {
    node *current_node = head;
    while (current_node != NULL) {
        printf("%s\n", current_node->email);
        current_node = current_node->next;
    }
}

// Free the list of emails
void free_list() {
    node *current_node = head;
    while (current_node != NULL) {
        node *temp = current_node;
        current_node = current_node->next;
        free(temp->email);
        free(temp);
    }
}

// Main function
int main() {
    // Add some emails to the list
    add_email("john.doe@example.com");
    add_email("jane.doe@example.com");
    add_email("bob.smith@example.com");

    // Print the list of emails
    print_list();

    // Remove an email from the list
    remove_email("bob.smith@example.com");

    // Print the list of emails again
    print_list();

    // Free the list of emails
    free_list();

    return 0;
}