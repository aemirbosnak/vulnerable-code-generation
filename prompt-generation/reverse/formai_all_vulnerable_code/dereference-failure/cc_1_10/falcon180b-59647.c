//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 100
#define MAX_VALUE_SIZE 1000
#define MAX_NUM_KEYS 1000
#define MAX_NUM_VALUES 10000

typedef struct {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
} KeyValue;

typedef struct {
    KeyValue *keys;
    KeyValue *values;
    int num_keys;
    int num_values;
} Database;

void initialize_database(Database *db) {
    db->keys = (KeyValue *) malloc(MAX_NUM_KEYS * sizeof(KeyValue));
    db->values = (KeyValue *) malloc(MAX_NUM_VALUES * sizeof(KeyValue));
    db->num_keys = 0;
    db->num_values = 0;
}

void destroy_database(Database *db) {
    free(db->keys);
    free(db->values);
}

int add_key_value(Database *db, char *key, char *value) {
    if (db->num_keys >= MAX_NUM_KEYS) {
        printf("Error: Maximum number of keys reached.\n");
        return -1;
    }
    if (db->num_values >= MAX_NUM_VALUES) {
        printf("Error: Maximum number of values reached.\n");
        return -1;
    }
    strncpy(db->keys[db->num_keys].key, key, MAX_KEY_SIZE);
    strncpy(db->values[db->num_values].value, value, MAX_VALUE_SIZE);
    db->num_keys++;
    db->num_values++;
    return 0;
}

int search_key(Database *db, char *key) {
    int i;
    for (i = 0; i < db->num_keys; i++) {
        if (strcmp(db->keys[i].key, key) == 0) {
            printf("%s\n", db->values[i].value);
            return 0;
        }
    }
    printf("Key not found.\n");
    return -1;
}

int main() {
    Database db;
    initialize_database(&db);
    add_key_value(&db, "apple", "red");
    add_key_value(&db, "banana", "yellow");
    add_key_value(&db, "orange", "orange");
    search_key(&db, "apple");
    search_key(&db, "grape");
    destroy_database(&db);
    return 0;
}