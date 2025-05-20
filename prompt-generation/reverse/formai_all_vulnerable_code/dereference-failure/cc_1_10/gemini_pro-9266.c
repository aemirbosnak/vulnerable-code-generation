//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char *key;
    char *value;
} entry_t;

entry_t *db[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char *key, char *value) {
    if (num_entries == MAX_ENTRIES) {
        fprintf(stderr, "Database is full!\n");
        return;
    }

    entry_t *entry = malloc(sizeof(entry_t));
    entry->key = strdup(key);
    entry->value = strdup(value);

    db[num_entries++] = entry;
}

char *get_value(char *key) {
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(db[i]->key, key) == 0) {
            return db[i]->value;
        }
    }

    return NULL;
}

void print_db() {
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", db[i]->key, db[i]->value);
    }
}

int main() {
    add_entry("name", "John Doe");
    add_entry("age", "30");
    add_entry("city", "New York");

    printf("Name: %s\n", get_value("name"));
    printf("Age: %s\n", get_value("age"));
    printf("City: %s\n", get_value("city"));

    print_db();

    return 0;
}