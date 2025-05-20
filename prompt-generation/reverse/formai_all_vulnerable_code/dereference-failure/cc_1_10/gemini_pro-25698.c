//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: safe
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct entry {
    char *name;
    char *number;
    struct entry *next;
};

struct phonebook {
    struct entry *head;
    struct entry *tail;
};

struct phonebook *create_phonebook() {
    struct phonebook *pb = malloc(sizeof(struct phonebook));
    pb->head = NULL;
    pb->tail = NULL;
    return pb;
}

void add_entry(struct phonebook *pb, char *name, char *number) {
    struct entry *new_entry = malloc(sizeof(struct entry));
    new_entry->name = strdup(name);
    new_entry->number = strdup(number);
    new_entry->next = NULL;

    if (pb->tail == NULL) {
        pb->head = new_entry;
        pb->tail = new_entry;
    } else {
        pb->tail->next = new_entry;
        pb->tail = new_entry;
    }
}

char *get_number(struct phonebook *pb, char *name) {
    struct entry *current = pb->head;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current->number;
        }
        current = current->next;
    }

    return NULL;
}

void free_phonebook(struct phonebook *pb) {
    struct entry *current = pb->head;

    while (current != NULL) {
        struct entry *next = current->next;
        free(current->name);
        free(current->number);
        free(current);
        current = next;
    }

    free(pb);
}

int main() {
    struct phonebook *pb = create_phonebook();

    add_entry(pb, "John Doe", "555-1212");
    add_entry(pb, "Jane Doe", "555-1213");
    add_entry(pb, "Bill Smith", "555-1214");

    char *number = get_number(pb, "John Doe");
    printf("John Doe's number is %s\n", number);

    free_phonebook(pb);

    return 0;
}