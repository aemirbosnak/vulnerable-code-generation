//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 100
#define MAX_VALUE_LENGTH 200
#define MAX_NUM_KEYS 100

typedef struct {
    char *key;
    char *value;
} KeyValuePair;

typedef struct {
    KeyValuePair *keyValuePairs;
    int numKeyValuePairs;
} Database;

void initDatabase(Database *db) {
    db->keyValuePairs = malloc(MAX_NUM_KEYS * sizeof(KeyValuePair));
    db->numKeyValuePairs = 0;
}

void addKeyValuePair(Database *db, char *key, char *value) {
    if (db->numKeyValuePairs == MAX_NUM_KEYS) {
        printf("Error: Maximum number of key-value pairs reached.\n");
        return;
    }
    KeyValuePair *pair = &db->keyValuePairs[db->numKeyValuePairs];
    strcpy(pair->key, key);
    strcpy(pair->value, value);
    db->numKeyValuePairs++;
}

void printKeyValuePairs(Database *db) {
    for (int i = 0; i < db->numKeyValuePairs; i++) {
        printf("%s -> %s\n", db->keyValuePairs[i].key, db->keyValuePairs[i].value);
    }
}

void searchKeyValuePair(Database *db, char *key) {
    for (int i = 0; i < db->numKeyValuePairs; i++) {
        if (strcmp(db->keyValuePairs[i].key, key) == 0) {
            printf("%s -> %s\n", db->keyValuePairs[i].key, db->keyValuePairs[i].value);
            return;
        }
    }
    printf("Error: Key not found.\n");
}

void destroyDatabase(Database *db) {
    free(db->keyValuePairs);
}

int main() {
    Database db;
    initDatabase(&db);
    addKeyValuePair(&db, "Name", "John");
    addKeyValuePair(&db, "Age", "25");
    addKeyValuePair(&db, "City", "New York");
    printKeyValuePairs(&db);
    searchKeyValuePair(&db, "Age");
    destroyDatabase(&db);
    return 0;
}