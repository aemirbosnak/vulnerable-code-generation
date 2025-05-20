//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 100
#define MAX_VALUE_LENGTH 1000
#define MAX_NUM_KEYS 1000

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} KeyValue;

typedef struct {
    KeyValue *keys;
    int numKeys;
} Database;

int compareKeys(const void *a, const void *b) {
    return strcmp(((KeyValue *)a)->key, ((KeyValue *)b)->key);
}

void addKey(Database *db, const char *key, const char *value) {
    if (db->numKeys >= MAX_NUM_KEYS) {
        printf("Error: database is full.\n");
        return;
    }

    KeyValue *newKey = malloc(sizeof(KeyValue));
    strcpy(newKey->key, key);
    strcpy(newKey->value, value);

    qsort(db->keys, db->numKeys, sizeof(KeyValue), compareKeys);

    db->keys = realloc(db->keys, sizeof(KeyValue) * (db->numKeys + 1));
    db->keys[db->numKeys] = *newKey;
    db->numKeys++;
}

const char *getValue(Database *db, const char *key) {
    KeyValue keyValue = {.key = key };
    KeyValue *result = bsearch(&keyValue, db->keys, db->numKeys, sizeof(KeyValue), compareKeys);

    if (result == NULL) {
        return NULL;
    }

    return result->value;
}

int main() {
    Database db;
    db.keys = NULL;
    db.numKeys = 0;

    addKey(&db, "apple", "red");
    addKey(&db, "banana", "yellow");
    addKey(&db, "cherry", "red");

    const char *value1 = getValue(&db, "apple");
    const char *value2 = getValue(&db, "banana");
    const char *value3 = getValue(&db, "cherry");

    printf("apple: %s\n", value1);
    printf("banana: %s\n", value2);
    printf("cherry: %s\n", value3);

    return 0;
}