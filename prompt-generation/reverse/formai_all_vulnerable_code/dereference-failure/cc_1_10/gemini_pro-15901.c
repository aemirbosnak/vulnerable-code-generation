//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *name;
    char *number;
    struct node *next;
} node;

node *head = NULL;

void insert(char *name, char *number) {
    node *new_node = malloc(sizeof(node));
    new_node->name = strdup(name);
    new_node->number = strdup(number);
    new_node->next = NULL;

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

void search(char *name) {
    node *current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("%s: %s\n", current->name, current->number);
            return;
        }
        current = current->next;
    }
    printf("%s not found\n", name);
}

void delete(char *name) {
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
            free(current->number);
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("%s not found\n", name);
}

void print_all() {
    node *current = head;
    while (current != NULL) {
        printf("%s: %s\n", current->name, current->number);
        current = current->next;
    }
}

int main() {
    insert("John Doe", "555-1212");
    insert("Jane Doe", "555-1213");
    insert("Bob Smith", "555-1214");

    search("John Doe");
    search("Bob Smith");
    search("Alice Jones");

    delete("John Doe");

    print_all();

    return 0;
}