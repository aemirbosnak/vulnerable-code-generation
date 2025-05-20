//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 100
#define MAX_VALUE_LENGTH 1000
#define MAX_NUM_KEYS 1000
#define MAX_NUM_VALUES 10000

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} KeyValuePair;

typedef struct {
    KeyValuePair *keys;
    KeyValuePair *values;
    int numKeys;
    int numValues;
} Database;

void initDatabase(Database *db) {
    db->keys = (KeyValuePair *)malloc(MAX_NUM_KEYS * sizeof(KeyValuePair));
    db->values = (KeyValuePair *)malloc(MAX_NUM_VALUES * sizeof(KeyValuePair));
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

    KeyValuePair *newKey = &db->keys[db->numKeys];
    strcpy(newKey->key, key);
    db->numKeys++;

    return 0;
}

int addValue(Database *db, char *value) {
    if (db->numValues >= MAX_NUM_VALUES) {
        printf("Error: Maximum number of values reached.\n");
        return -1;
    }

    KeyValuePair *newValue = &db->values[db->numValues];
    strcpy(newValue->value, value);
    db->numValues++;

    return 0;
}

int searchValue(Database *db, char *key, char *value) {
    int i;
    for (i = 0; i < db->numKeys; i++) {
        if (strcmp(db->keys[i].key, key) == 0) {
            int j;
            for (j = 0; j < db->numValues; j++) {
                if (strcmp(db->values[j].value, value) == 0) {
                    printf("Value found!\n");
                    return 0;
                }
            }
        }
    }

    printf("Value not found.\n");
    return -1;
}

int main() {
    Database db;
    initDatabase(&db);

    addKey(&db, "Name");
    addKey(&db, "Age");
    addKey(&db, "Gender");

    addValue(&db, "John");
    addValue(&db, "25");
    addValue(&db, "Male");

    searchValue(&db, "Name", "John");
    searchValue(&db, "Age", "25");
    searchValue(&db, "Gender", "Male");

    destroyDatabase(&db);

    return 0;
}