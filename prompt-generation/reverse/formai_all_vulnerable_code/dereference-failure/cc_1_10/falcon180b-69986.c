//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 100
#define MAX_VALUE_LEN 200
#define MAX_NUM_KEYS 100
#define MAX_NUM_VALUES 1000

typedef struct {
    char key[MAX_KEY_LEN];
    char value[MAX_VALUE_LEN];
} KeyValue;

typedef struct {
    KeyValue *keys;
    KeyValue *values;
    int num_keys;
    int num_values;
} Database;

void init_database(Database *db) {
    db->keys = (KeyValue *) malloc(MAX_NUM_KEYS * sizeof(KeyValue));
    db->values = (KeyValue *) malloc(MAX_NUM_VALUES * sizeof(KeyValue));
    db->num_keys = 0;
    db->num_values = 0;
}

void add_key(Database *db, char *key) {
    KeyValue *kv = &db->keys[db->num_keys];
    strcpy(kv->key, key);
    db->num_keys++;
}

void add_value(Database *db, char *value) {
    KeyValue *kv = &db->values[db->num_values];
    strcpy(kv->value, value);
    db->num_values++;
}

void print_database(Database *db) {
    for (int i = 0; i < db->num_keys; i++) {
        printf("Key: %s\n", db->keys[i].key);
    }
    for (int i = 0; i < db->num_values; i++) {
        printf("Value: %s\n", db->values[i].value);
    }
}

void search_database(Database *db, char *key) {
    for (int i = 0; i < db->num_keys; i++) {
        if (strcmp(db->keys[i].key, key) == 0) {
            printf("Found key: %s\n", key);
            printf("Value: %s\n", db->values[i].value);
            return;
        }
    }
    printf("Key not found\n");
}

int main() {
    Database db;
    init_database(&db);
    add_key(&db, "Name");
    add_key(&db, "Age");
    add_key(&db, "Gender");
    add_value(&db, "John");
    add_value(&db, "25");
    add_value(&db, "Male");
    print_database(&db);
    search_database(&db, "Name");
    search_database(&db, "Age");
    search_database(&db, "Gender");
    return 0;
}