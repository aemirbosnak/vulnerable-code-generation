//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_VALUE_LENGTH 1000
#define MAX_NUM_KEYS 100
#define MAX_NUM_VALUES 1000

typedef struct {
    char *key;
    char *value;
} KeyValue;

typedef struct {
    KeyValue *keys;
    KeyValue *values;
    int numKeys;
    int numValues;
} Database;

void initDatabase(Database *db) {
    db->keys = malloc(MAX_NUM_KEYS * sizeof(KeyValue));
    db->values = malloc(MAX_NUM_VALUES * sizeof(KeyValue));
    db->numKeys = 0;
    db->numValues = 0;
}

void destroyDatabase(Database *db) {
    free(db->keys);
    free(db->values);
}

int addKey(Database *db, char *key) {
    if (db->numKeys >= MAX_NUM_KEYS) {
        printf("Error: Maximum number of keys reached.\n");
        return -1;
    }
    KeyValue *kv = malloc(sizeof(KeyValue));
    kv->key = strdup(key);
    kv->value = NULL;
    db->keys[db->numKeys++] = *kv;
    return 0;
}

int addValue(Database *db, char *key, char *value) {
    int i;
    for (i = 0; i < db->numKeys; i++) {
        if (strcmp(db->keys[i].key, key) == 0) {
            db->values[db->numValues++] = (KeyValue) {.key = strdup(key),.value = strdup(value) };
            return 0;
        }
    }
    printf("Error: Key not found.\n");
    return -1;
}

int search(Database *db, char *key) {
    int i;
    for (i = 0; i < db->numKeys; i++) {
        if (strcmp(db->keys[i].key, key) == 0) {
            printf("%s = %s\n", key, db->values[i].value);
            return 0;
        }
    }
    printf("Error: Key not found.\n");
    return -1;
}

int main() {
    Database db;
    initDatabase(&db);
    addKey(&db, "name");
    addKey(&db, "age");
    addValue(&db, "name", "John");
    addValue(&db, "age", "30");
    search(&db, "name");
    search(&db, "age");
    destroyDatabase(&db);
    return 0;
}