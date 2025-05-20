//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *email;
    struct node *next;
} node_t;

node_t *head = NULL;

void add_email(char *email) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->email = strdup(email);
    new_node->next = head;
    head = new_node;
}

void print_emails() {
    node_t *current = head;
    while (current != NULL) {
        printf("%s\n", current->email);
        current = current->next;
    }
}

void free_emails() {
    node_t *current = head;
    while (current != NULL) {
        node_t *next = current->next;
        free(current->email);
        free(current);
        current = next;
    }
    head = NULL;
}

int main() {
    printf("Welcome to the most cheerful mailing list manager ever!\n");

    // Add some sample emails.
    add_email("alice@example.com");
    add_email("bob@example.com");
    add_email("charlie@example.com");
    add_email("dave@example.com");
    add_email("eve@example.com");

    // Print the emails.
    printf("Here are the emails in our list:\n");
    print_emails();

    // Free the emails.
    free_emails();

    return 0;
}