//MISTRAL-7B DATASET v1.0 Category: Database Indexing System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100003
#define KEY_LENGTH 100

typedef struct {
    char key[KEY_LENGTH];
    int value;
} Record;

unsigned long hash(char *key) {
    unsigned long hash = 5381;
    int c;

    while ((c = *key++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % TABLE_SIZE;
}

struct HashTable {
    Record *records;
};

struct HashTable *createHashTable() {
    struct HashTable *table = malloc(sizeof(struct HashTable));
    table->records = calloc(TABLE_SIZE, sizeof(Record));
    return table;
}

void insertRecord(struct HashTable *table, char *key, int value) {
    unsigned long index = hash(key);

    if (table->records[index].value == 0) {
        strcpy(table->records[index].key, key);
        table->records[index].value = value;
    } else {
        // Handle collisions with chaining or open addressing
        printf("Key already exists: %s\n", key);
    }
}

int findRecord(struct HashTable *table, char *key) {
    unsigned long index = hash(key);

    if (table->records[index].value != 0) {
        if (strcpy(key, table->records[index].key) == NULL) {
            // Handle memory allocation errors
            printf("Memory allocation error\n");
            return -1;
        }

        return table->records[index].value;
    }

    return -1;
}

int main() {
    struct HashTable *table = createHashTable();

    insertRecord(table, "apple", 1);
    insertRecord(table, "banana", 2);
    insertRecord(table, "cherry", 3);

    int value = findRecord(table, "banana");
    printf("Value for key 'banana': %d\n", value);

    return 0;
}