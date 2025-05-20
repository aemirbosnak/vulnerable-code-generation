//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *key;
    int value;
} Entry;

Entry *table = NULL;
int size = 0;

// Function to create a new entry
void create_entry(char *key, int value) {
    Entry *new_entry = (Entry *)malloc(sizeof(Entry));
    if (new_entry == NULL) {
        printf("Out of memory!\n");
        exit(1);
    }

    new_entry->key = strdup(key);
    new_entry->value = value;

    if (size == MAX_SIZE) {
        printf("Table is full!\n");
        exit(1);
    }

    table = (Entry *)realloc(table, sizeof(Entry) * ++size);
    table[size - 1] = *new_entry;
}

// Function to search for an entry
Entry *search_entry(char *key) {
    int i;

    for (i = 0; i < size; i++) {
        if (strcmp(table[i].key, key) == 0) {
            return &table[i];
        }
    }

    return NULL;
}

// Function to delete an entry
void delete_entry(char *key) {
    Entry *entry = search_entry(key);

    if (entry == NULL) {
        printf("Entry not found!\n");
        return;
    }

    free(entry->key);
    memmove(entry, entry + 1, sizeof(Entry) * --size);
    table = (Entry *)realloc(table, sizeof(Entry) * size);
}

int main() {
    create_entry("apple", 10);
    create_entry("banana", 20);
    create_entry("cherry", 30);

    Entry *entry = search_entry("banana");
    if (entry!= NULL) {
        printf("Value of banana: %d\n", entry->value);
    } else {
        printf("Entry not found!\n");
    }

    delete_entry("banana");

    entry = search_entry("banana");
    if (entry!= NULL) {
        printf("Value of banana: %d\n", entry->value);
    } else {
        printf("Entry not found!\n");
    }

    return 0;
}