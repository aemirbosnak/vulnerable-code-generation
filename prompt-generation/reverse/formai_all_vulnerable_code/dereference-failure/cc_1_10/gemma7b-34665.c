//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1024

typedef struct Entry {
    char name[256];
    struct Entry *next;
} Entry;

Entry **index_create(void) {
    return NULL;
}

void index_insert(Entry **head, char *name) {
    Entry *new_entry = malloc(sizeof(Entry));
    strcpy(new_entry->name, name);
    new_entry->next = NULL;

    if (*head == NULL) {
        *head = new_entry;
    } else {
        (*head)->next = new_entry;
    }
}

Entry *index_search(Entry **head, char *name) {
    for (Entry *entry = *head; entry; entry = entry->next) {
        if (strcmp(entry->name, name) == 0) {
            return entry;
        }
    }

    return NULL;
}

int main() {
    Entry **index = index_create();

    index_insert(index, "John Doe");
    index_insert(index, "Jane Doe");
    index_insert(index, "Bill Smith");

    Entry *entry = index_search(index, "Jane Doe");

    if (entry) {
        printf("Name: %s\n", entry->name);
    } else {
        printf("Name not found.\n");
    }

    return 0;
}