//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: calm
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
            free(current->email);
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

void print_list() {
    node_t *current = head;

    while (current != NULL) {
        printf("%s\n", current->email);
        current = current->next;
    }
}

int main() {
    add_email("john@example.com");
    add_email("mary@example.com");
    add_email("bob@example.com");

    print_list();

    remove_email("mary@example.com");

    print_list();

    return 0;
}