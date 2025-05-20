//MISTRAL-7B DATASET v1.0 Category: Database simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TABLE_SIZE 101

typedef struct {
    char key[256];
    char value[256];
} Entry;

unsigned long hash(const char *str, unsigned long table_size) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % table_size;
}

Entry *create_entry(const char *key, const char *value) {
    Entry *entry = (Entry *)calloc(1, sizeof(Entry));
    strcpy(entry->key, key);
    strcpy(entry->value, value);
    return entry;
}

void put(Entry **table, const char *key, const char *value) {
    unsigned long index = hash(key, TABLE_SIZE);

    if (table[index]) {
        printf("Error: Key already exists.\n");
        free(value);
        return;
    }

    table[index] = create_entry(key, value);
}

char *get(Entry **table, const char *key) {
    unsigned long index = hash(key, TABLE_SIZE);
    Entry *entry = table[index];

    if (!entry) {
        printf("Error: Key not found.\n");
        return NULL;
    }

    return strdup(entry->value);
}

void delete(Entry **table, const char *key) {
    unsigned long index = hash(key, TABLE_SIZE);
    Entry *entry = table[index];

    if (!entry) {
        printf("Error: Key not found.\n");
        return;
    }

    free(entry);
    table[index] = NULL;
}

int main() {
    Entry *table[TABLE_SIZE] = {0};

    put(table, "apple", "An edible fruit");
    put(table, "banana", "A long curved fruit");
    put(table, "orange", "A round citrus fruit");

    printf("Value for key 'apple': %s\n", get(table, "apple"));
    printf("Value for key 'banana': %s\n", get(table, "banana"));
    printf("Value for key 'orange': %s\n", get(table, "orange"));

    delete(table, "apple");

    printf("Value for key 'apple': %s\n", get(table, "apple"));

    return 0;
}