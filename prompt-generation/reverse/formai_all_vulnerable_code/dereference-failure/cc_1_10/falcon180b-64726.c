//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 50
#define MAX_VALUE_LENGTH 200
#define MAX_NUM_KEYS 100

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} KeyValue;

typedef struct {
    KeyValue *keys;
    int num_keys;
} Database;

void init_database(Database *db) {
    db->keys = (KeyValue *)malloc(MAX_NUM_KEYS * sizeof(KeyValue));
    db->num_keys = 0;
}

void destroy_database(Database *db) {
    free(db->keys);
}

int add_key_value(Database *db, char *key, char *value) {
    if (db->num_keys >= MAX_NUM_KEYS) {
        printf("Error: database is full\n");
        return -1;
    }

    KeyValue *kv = &db->keys[db->num_keys];
    strcpy(kv->key, key);
    strcpy(kv->value, value);

    db->num_keys++;

    return 0;
}

int search_key(Database *db, char *key) {
    for (int i = 0; i < db->num_keys; i++) {
        if (strcmp(db->keys[i].key, key) == 0) {
            printf("Value for key '%s': %s\n", key, db->keys[i].value);
            return 0;
        }
    }

    printf("Key not found\n");
    return -1;
}

int main() {
    Database db;
    init_database(&db);

    add_key_value(&db, "name", "John Doe");
    add_key_value(&db, "age", "30");
    add_key_value(&db, "city", "New York");

    search_key(&db, "name");
    search_key(&db, "age");
    search_key(&db, "city");

    destroy_database(&db);

    return 0;
}