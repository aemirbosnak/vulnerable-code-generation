//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *name;
    char *number;
    struct node *next;
} node;

typedef struct phonebook {
    node *head;
    node *tail;
    int size;
} phonebook;

phonebook *create_phonebook() {
    phonebook *pb = malloc(sizeof(phonebook));
    pb->head = NULL;
    pb->tail = NULL;
    pb->size = 0;
    return pb;
}

void destroy_phonebook(phonebook *pb) {
    node *current = pb->head;
    while (current != NULL) {
        node *next = current->next;
        free(current->name);
        free(current->number);
        free(current);
        current = next;
    }
    free(pb);
}

void add_entry(phonebook *pb, char *name, char *number) {
    node *new_node = malloc(sizeof(node));
    new_node->name = strdup(name);
    new_node->number = strdup(number);
    new_node->next = NULL;

    if (pb->head == NULL) {
        pb->head = new_node;
        pb->tail = new_node;
    } else {
        pb->tail->next = new_node;
        pb->tail = new_node;
    }

    pb->size++;
}

void remove_entry(phonebook *pb, char *name) {
    node *current = pb->head;
    node *previous = NULL;

    while (current != NULL && strcmp(current->name, name) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        return;
    }

    if (previous == NULL) {
        pb->head = current->next;
        if (pb->head == NULL) {
            pb->tail = NULL;
        }
    } else {
        previous->next = current->next;
        if (current == pb->tail) {
            pb->tail = previous;
        }
    }

    free(current->name);
    free(current->number);
    free(current);

    pb->size--;
}

void find_entry(phonebook *pb, char *name) {
    node *current = pb->head;

    while (current != NULL && strcmp(current->name, name) != 0) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Entry not found.\n");
    } else {
        printf("%s: %s\n", current->name, current->number);
    }
}

void print_phonebook(phonebook *pb) {
    node *current = pb->head;

    while (current != NULL) {
        printf("%s: %s\n", current->name, current->number);
        current = current->next;
    }
}

int main() {
    phonebook *pb = create_phonebook();

    add_entry(pb, "Alice", "555-1212");
    add_entry(pb, "Bob", "555-1213");
    add_entry(pb, "Charlie", "555-1214");

    print_phonebook(pb);

    find_entry(pb, "Bob");

    remove_entry(pb, "Alice");

    print_phonebook(pb);

    destroy_phonebook(pb);

    return 0;
}