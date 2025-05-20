//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 50
#define MAX_VALUE_SIZE 500
#define MAX_NUM_KEYS 100
#define MAX_NUM_VALUES 1000

typedef struct {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
} KeyValue;

typedef struct {
    KeyValue *keys;
    KeyValue *values;
    int numKeys;
    int numValues;
} Database;

void createDatabase(Database *db) {
    db->keys = (KeyValue *)malloc(MAX_NUM_KEYS * sizeof(KeyValue));
    db->values = (KeyValue *)malloc(MAX_NUM_VALUES * sizeof(KeyValue));
    db->numKeys = 0;
    db->numValues = 0;
}

void addKeyValue(Database *db, char *key, char *value) {
    if (db->numKeys >= MAX_NUM_KEYS) {
        printf("Error: Maximum number of keys reached.\n");
        return;
    }
    if (db->numValues >= MAX_NUM_VALUES) {
        printf("Error: Maximum number of values reached.\n");
        return;
    }
    strcpy(db->keys[db->numKeys].key, key);
    strcpy(db->values[db->numValues].value, value);
    db->numKeys++;
    db->numValues++;
}

void printDatabase(Database *db) {
    int i;
    for (i = 0; i < db->numKeys; i++) {
        printf("%s -> %s\n", db->keys[i].key, db->values[i].value);
    }
}

int main() {
    Database db;
    createDatabase(&db);
    addKeyValue(&db, "apple", "red");
    addKeyValue(&db, "banana", "yellow");
    addKeyValue(&db, "cherry", "red");
    printDatabase(&db);
    return 0;
}