//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 100
#define MAX_VALUE_LENGTH 1000
#define MAX_NUM_KEYS 100

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} KeyValuePair;

typedef struct {
    KeyValuePair *keyValuePairs;
    int numKeyValuePairs;
} Database;

void createDatabase(Database *db) {
    db->keyValuePairs = (KeyValuePair *)malloc(MAX_NUM_KEYS * sizeof(KeyValuePair));
    db->numKeyValuePairs = 0;
}

void destroyDatabase(Database *db) {
    free(db->keyValuePairs);
}

int addKeyValuePair(Database *db, char *key, char *value) {
    if (db->numKeyValuePairs >= MAX_NUM_KEYS) {
        return -1;
    }

    KeyValuePair *newPair = &db->keyValuePairs[db->numKeyValuePairs];
    strcpy(newPair->key, key);
    strcpy(newPair->value, value);

    db->numKeyValuePairs++;

    return 0;
}

int searchKeyValuePair(Database *db, char *key) {
    int i;
    for (i = 0; i < db->numKeyValuePairs; i++) {
        if (strcmp(db->keyValuePairs[i].key, key) == 0) {
            return i;
        }
    }

    return -1;
}

int main() {
    Database db;
    createDatabase(&db);

    addKeyValuePair(&db, "apple", "red");
    addKeyValuePair(&db, "banana", "yellow");
    addKeyValuePair(&db, "orange", "orange");

    int index = searchKeyValuePair(&db, "banana");
    if (index!= -1) {
        printf("Value for banana: %s\n", db.keyValuePairs[index].value);
    } else {
        printf("Banana not found.\n");
    }

    destroyDatabase(&db);

    return 0;
}