//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: surprised
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

void free_list() {
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
    char *emails[] = {"john@example.com", "mary@example.com", "bob@example.com"};

    for (int i = 0; i < sizeof(emails) / sizeof(char *); i++) {
        add_email(emails[i]);
    }

    printf("Mailing list:\n");
    print_list();

    printf("Freeing list...\n");
    free_list();

    return 0;
}