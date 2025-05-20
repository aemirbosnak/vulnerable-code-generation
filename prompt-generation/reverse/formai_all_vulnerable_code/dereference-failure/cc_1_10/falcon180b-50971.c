//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100000
#define MAX_ENTRY_SIZE 1000

typedef struct {
    char *name;
    int age;
    char *email;
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

int compare_entries(const void *a, const void *b) {
    Entry *entry_a = (Entry *)a;
    Entry *entry_b = (Entry *)b;

    int result = strcmp(entry_a->name, entry_b->name);
    if (result == 0) {
        result = strcmp(entry_a->email, entry_b->email);
    }

    return result;
}

void add_entry(char *name, int age, char *email) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: database is full\n");
        return;
    }

    Entry *entry = &entries[num_entries];
    entry->name = strdup(name);
    entry->age = age;
    entry->email = strdup(email);

    num_entries++;
}

void print_entries() {
    qsort(entries, num_entries, sizeof(Entry), compare_entries);

    for (int i = 0; i < num_entries; i++) {
        Entry *entry = &entries[i];
        printf("%s (%d) - %s\n", entry->name, entry->age, entry->email);
    }
}

void search_entries(char *name) {
    for (int i = 0; i < num_entries; i++) {
        Entry *entry = &entries[i];

        if (strcmp(entry->name, name) == 0) {
            printf("Found entry: %s (%d) - %s\n", entry->name, entry->age, entry->email);
            return;
        }
    }

    printf("Entry not found\n");
}

int main() {
    add_entry("John Doe", 25, "john.doe@example.com");
    add_entry("Jane Doe", 30, "jane.doe@example.com");

    print_entries();

    search_entries("John Doe");
    search_entries("Jane Doe");
    search_entries("Unknown");

    return 0;
}