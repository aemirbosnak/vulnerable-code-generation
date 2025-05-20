//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 100
#define MAX_VALUE_SIZE 1000
#define MAX_NUM_KEYS 1000

typedef struct {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
} KeyValuePair;

typedef struct {
    KeyValuePair *pairs;
    int numKeys;
} Database;

void initDatabase(Database *db) {
    db->pairs = (KeyValuePair *)malloc(MAX_NUM_KEYS * sizeof(KeyValuePair));
    db->numKeys = 0;
}

void destroyDatabase(Database *db) {
    free(db->pairs);
}

int addKeyValuePair(Database *db, const char *key, const char *value) {
    if (db->numKeys >= MAX_NUM_KEYS) {
        printf("Error: Maximum number of key-value pairs reached.\n");
        return -1;
    }

    strncpy(db->pairs[db->numKeys].key, key, MAX_KEY_SIZE);
    strncpy(db->pairs[db->numKeys].value, value, MAX_VALUE_SIZE);
    db->numKeys++;

    return 0;
}

int searchKey(Database *db, const char *key) {
    int i;

    for (i = 0; i < db->numKeys; i++) {
        if (strcmp(db->pairs[i].key, key) == 0) {
            printf("%s\n", db->pairs[i].value);
            return 0;
        }
    }

    printf("Key not found.\n");
    return -1;
}

int main() {
    Database db;
    initDatabase(&db);

    addKeyValuePair(&db, "Name", "John");
    addKeyValuePair(&db, "Age", "30");
    addKeyValuePair(&db, "City", "New York");

    searchKey(&db, "Name");
    searchKey(&db, "Age");
    searchKey(&db, "City");

    destroyDatabase(&db);

    return 0;
}