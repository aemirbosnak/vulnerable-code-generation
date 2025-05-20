//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_ENTRIES 1024

typedef struct Entry {
    char name[256];
    struct Entry* next;
} Entry;

Entry* insert_entry(Entry* head, char* name) {
    Entry* new_entry = malloc(sizeof(Entry));
    strcpy(new_entry->name, name);
    new_entry->next = NULL;

    if (head == NULL) {
        head = new_entry;
    } else {
        head->next = insert_entry(head->next, name);
    }

    return head;
}

Entry* find_entry(Entry* head, char* name) {
    for (Entry* current = head; current; current = current->next) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
    }

    return NULL;
}

int main() {
    Entry* head = NULL;

    // Insert entries
    insert_entry(head, "John Doe");
    insert_entry(head, "Jane Doe");
    insert_entry(head, "Bob Smith");

    // Find entries
    Entry* entry = find_entry(head, "John Doe");
    if (entry) {
        printf("Found entry: %s\n", entry->name);
    } else {
        printf("Entry not found.\n");
    }

    return 0;
}