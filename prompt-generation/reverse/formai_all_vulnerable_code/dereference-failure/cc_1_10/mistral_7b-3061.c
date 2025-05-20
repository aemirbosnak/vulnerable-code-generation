//MISTRAL-7B DATASET v1.0 Category: Database Indexing System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TABLE_SIZE 101
#define KEY_LENGTH 50

typedef struct {
    char key[KEY_LENGTH];
    int value;
} Record;

unsigned long hash(char *str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; /* hash * 31 + c */
    }

    return hash % TABLE_SIZE;
}

void insert(Record *table, char *key, int value) {
    unsigned long index = hash(key);

    if (table[index].value == -1) {
        strcpy(table[index].key, key);
        table[index].value = value;
    } else {
        printf("Error: Key already exists!\n");
    }
}

Record *search(Record *table, char *key) {
    unsigned long index = hash(key);

    if (table[index].value == -1) {
        printf("Error: Key not found!\n");
        return NULL;
    } else {
        return &table[index];
    }
}

int main() {
    Record *database = malloc(TABLE_SIZE * sizeof(Record));

    for (int i = 0; i < TABLE_SIZE; i++) {
        database[i].value = -1;
    }

    insert(database, "apple", 1);
    insert(database, "banana", 2);
    insert(database, "orange", 3);
    insert(database, "kiwi", 4);

    Record *found;

    found = search(database, "apple");
    printf("Key: %s, Value: %d\n", found->key, found->value);

    found = search(database, "orange");
    printf("Key: %s, Value: %d\n", found->key, found->value);

    found = search(database, "grape");
    printf("Key: %s, Value: %d\n", found->key, found->value);

    free(database);

    return 0;
}