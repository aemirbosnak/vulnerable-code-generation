//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: creative
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

void print_list() {
    node_t *current = head;
    while (current != NULL) {
        printf("%s\n", current->email);
        current = current->next;
    }
}

void remove_email(char *email) {
    node_t *current = head;
    node_t *previous = NULL;
    while (current != NULL) {
        if (strcmp(current->email, email) == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

int main() {
    // Add some emails to the list
    add_email("john@example.com");
    add_email("mary@example.com");
    add_email("bob@example.com");

    // Print the list
    print_list();

    // Remove an email from the list
    remove_email("bob@example.com");

    // Print the list again
    print_list();

    return 0;
}