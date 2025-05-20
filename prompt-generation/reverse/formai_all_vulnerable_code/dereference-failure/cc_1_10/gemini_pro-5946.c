//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

typedef struct {
    char *key;
    int value;
} table_entry;

table_entry table[TABLE_SIZE];

int hash(char *key) {
    int h = 0;
    for (char *p = key; *p; p++) {
        h = (h << 5) - h + *p;
    }
    return h % TABLE_SIZE;
}

void insert(char *key, int value) {
    int h = hash(key);
    while (table[h].key != NULL) {
        h = (h + 1) % TABLE_SIZE;
    }
    table[h].key = strdup(key);
    table[h].value = value;
}

int get(char *key) {
    int h = hash(key);
    while (table[h].key != NULL) {
        if (strcmp(table[h].key, key) == 0) {
            return table[h].value;
        }
        h = (h + 1) % TABLE_SIZE;
    }
    return -1;
}

int main() {
    insert("foo", 42);
    insert("bar", 123);
    insert("baz", 456);

    printf("foo: %d\n", get("foo"));
    printf("bar: %d\n", get("bar"));
    printf("baz: %d\n", get("baz"));

    return 0;
}