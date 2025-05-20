//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *name;
    char *email;
    struct node *next;
} node;

node *head = NULL;

void add_member(char *name, char *email) {
    node *new_node = malloc(sizeof(node));
    new_node->name = strdup(name);
    new_node->email = strdup(email);
    new_node->next = head;
    head = new_node;
}

void print_list() {
    node *current = head;
    while (current != NULL) {
        printf("%s (%s)\n", current->name, current->email);
        current = current->next;
    }
}

void remove_member(char *name) {
    node *current = head;
    node *previous = NULL;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current->name);
            free(current->email);
            free(current);
            break;
        }
        previous = current;
        current = current->next;
    }
}

int main() {
    add_member("John Doe", "john.doe@example.com");
    add_member("Jane Smith", "jane.smith@example.com");
    add_member("Bill Jones", "bill.jones@example.com");
    print_list();
    remove_member("John Doe");
    print_list();
    return 0;
}