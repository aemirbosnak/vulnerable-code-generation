//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TABLE_SIZE 10000

typedef struct {
    char *key;
    char *value;
} entry;

typedef struct {
    entry *entries;
    int size;
} table;

table *create_table(int size) {
    table *t = malloc(sizeof(table));
    t->entries = malloc(sizeof(entry) * size);
    t->size = size;
    return t;
}

void destroy_table(table *t) {
    for (int i = 0; i < t->size; i++) {
        free(t->entries[i].key);
        free(t->entries[i].value);
    }
    free(t->entries);
    free(t);
}

int hash(char *key) {
    int h = 0;
    for (int i = 0; i < strlen(key); i++) {
        h += key[i];
    }
    return h % MAX_TABLE_SIZE;
}

void insert(table *t, char *key, char *value) {
    int h = hash(key);
    for (int i = 0; i < t->size; i++) {
        if (t->entries[h].key == NULL) {
            t->entries[h].key = key;
            t->entries[h].value = value;
            return;
        }
        h = (h + 1) % t->size;
    }
    printf("Error: table is full\n");
}

char *lookup(table *t, char *key) {
    int h = hash(key);
    for (int i = 0; i < t->size; i++) {
        if (t->entries[h].key != NULL && strcmp(t->entries[h].key, key) == 0) {
            return t->entries[h].value;
        }
        h = (h + 1) % t->size;
    }
    return NULL;
}

int main() {
    table *t = create_table(MAX_TABLE_SIZE);

    insert(t, "hello", "world");
    insert(t, "foo", "bar");
    insert(t, "baz", "qux");

    printf("%s\n", lookup(t, "hello")); // prints "world"
    printf("%s\n", lookup(t, "foo")); // prints "bar"
    printf("%s\n", lookup(t, "baz")); // prints "qux"

    destroy_table(t);

    return 0;
}