//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1024
#define MAX_ENTRY_LENGTH 256

typedef struct {
    char *key;
    char *value;
} Entry;

int num_entries = 0;
Entry *entries = NULL;

void add_entry(char *key, char *value) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: too many entries\n");
        return;
    }
    Entry *new_entry = malloc(sizeof(Entry));
    new_entry->key = strdup(key);
    new_entry->value = strdup(value);
    entries = realloc(entries, sizeof(Entry) * ++num_entries);
    entries[num_entries - 1] = *new_entry;
}

void print_entries() {
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", entries[i].key, entries[i].value);
    }
}

void free_entries() {
    for (int i = 0; i < num_entries; i++) {
        free(entries[i].key);
        free(entries[i].value);
    }
    free(entries);
    entries = NULL;
    num_entries = 0;
}

int main() {
    add_entry("name", "John Doe");
    add_entry("age", "30");
    add_entry("address", "123 Main St");
    print_entries();
    free_entries();
    return 0;
}