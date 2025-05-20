//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_ENTRIES 1024

typedef struct Entry {
    char name[256];
    struct Entry* next;
} Entry;

Entry* head = NULL;

void insert(char* name) {
    Entry* new_entry = malloc(sizeof(Entry));
    strcpy(new_entry->name, name);
    new_entry->next = NULL;

    if (head == NULL) {
        head = new_entry;
    } else {
        Entry* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_entry;
    }
}

int search(char* name) {
    Entry* current = head;
    while (current) {
        if (strcmp(current->name, name) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int main() {
    insert("John Doe");
    insert("Jane Doe");
    insert("Bill Smith");
    insert("Mary Johnson");

    if (search("John Doe")) {
        printf("John Doe is in the list.\n");
    }

    if (search("Jane Doe")) {
        printf("Jane Doe is in the list.\n");
    }

    return 0;
}