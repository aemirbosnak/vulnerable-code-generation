//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char *key;
    char *value;
} entry_t;

entry_t entries[MAX_ENTRIES];
int num_entries = 0;

int compare(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void add_entry(char *key, char *value) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: database is full\n");
        return;
    }

    entry_t *entry = &entries[num_entries];
    entry->key = strdup(key);
    entry->value = strdup(value);

    num_entries++;
}

void delete_entry(char *key) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].key, key) == 0) {
            free(entries[i].key);
            free(entries[i].value);

            num_entries--;

            if (i < num_entries) {
                entries[i] = entries[num_entries];
            }

            break;
        }
    }
}

void search_entries(char *key) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].key, key) == 0) {
            printf("%s = %s\n", key, entries[i].value);
        }
    }
}

int main() {
    add_entry("name", "John Doe");
    add_entry("age", "30");
    add_entry("city", "New York");

    search_entries("age");

    delete_entry("city");

    search_entries("city");

    return 0;
}