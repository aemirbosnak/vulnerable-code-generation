//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 100
#define MAX_VALUE_LEN 1000
#define MAX_NUM_KEYS 100

typedef struct {
    char key[MAX_KEY_LEN];
    char value[MAX_VALUE_LEN];
} KeyValuePair;

typedef struct {
    KeyValuePair *keyValuePairs;
    int numKeyValuePairs;
} Database;

void initDatabase(Database *db) {
    db->keyValuePairs = NULL;
    db->numKeyValuePairs = 0;
}

void addKeyValuePair(Database *db, char *key, char *value) {
    KeyValuePair *newPair = malloc(sizeof(KeyValuePair));
    strncpy(newPair->key, key, MAX_KEY_LEN);
    strncpy(newPair->value, value, MAX_VALUE_LEN);
    db->keyValuePairs = realloc(db->keyValuePairs, sizeof(KeyValuePair) * (db->numKeyValuePairs + 1));
    db->keyValuePairs[db->numKeyValuePairs] = *newPair;
    db->numKeyValuePairs++;
}

int searchDatabase(Database *db, char *key) {
    for (int i = 0; i < db->numKeyValuePairs; i++) {
        if (strcmp(db->keyValuePairs[i].key, key) == 0) {
            printf("%s\n", db->keyValuePairs[i].value);
            return 1;
        }
    }
    return 0;
}

int main() {
    Database db;
    initDatabase(&db);

    addKeyValuePair(&db, "apple", "red");
    addKeyValuePair(&db, "banana", "yellow");
    addKeyValuePair(&db, "cherry", "red");

    searchDatabase(&db, "apple");
    searchDatabase(&db, "orange");

    return 0;
}