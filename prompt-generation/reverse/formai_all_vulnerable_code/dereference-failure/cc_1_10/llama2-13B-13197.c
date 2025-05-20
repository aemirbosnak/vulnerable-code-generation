//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/mman.h>

#define MAX_DB_SIZE 100000
#define MAX_KEY_LEN 20
#define MAX_VAL_LEN 50

typedef struct {
    char *key;
    char *val;
} db_entry_t;

typedef struct {
    char *name;
    size_t size;
    db_entry_t *data;
} db_t;

db_t *create_db(const char *name) {
    db_t *db = malloc(sizeof(db_t));
    db->name = strdup(name);
    db->size = 0;
    db->data = malloc(sizeof(db_entry_t) * MAX_DB_SIZE);
    return db;
}

void insert_db(db_t *db, const char *key, const char *val) {
    size_t len = strlen(key) + 1;
    if (len > MAX_KEY_LEN) {
        fprintf(stderr, "Key too long (max %zu bytes)\n", MAX_KEY_LEN);
        return;
    }
    if (db->size == MAX_DB_SIZE) {
        fprintf(stderr, "Database is full (%zu bytes)\n", db->size);
        return;
    }
    db_entry_t *entry = &db->data[db->size];
    entry->key = malloc(len);
    strcpy(entry->key, key);
    entry->val = malloc(strlen(val) + 1);
    strcpy(entry->val, val);
    db->size++;
}

void query_db(db_t *db, const char *key) {
    size_t len = strlen(key) + 1;
    if (len > MAX_KEY_LEN) {
        fprintf(stderr, "Key too long (max %zu bytes)\n", MAX_KEY_LEN);
        return;
    }
    for (size_t i = 0; i < db->size; i++) {
        if (strcmp(key, db->data[i].key) == 0) {
            printf("Found key %s with value %s\n", db->data[i].key, db->data[i].val);
            return;
        }
    }
    printf("Key not found\n");
}

void destroy_db(db_t *db) {
    for (size_t i = 0; i < db->size; i++) {
        free(db->data[i].key);
        free(db->data[i].val);
    }
    free(db->data);
    free(db);
}

int main() {
    srand(time(NULL));
    db_t *db = create_db("my_db");
    for (size_t i = 0; i < 10; i++) {
        const char *key = "key";
        const char *val = "value";
        insert_db(db, key, val);
    }
    for (size_t i = 0; i < 10; i++) {
        const char *key = "key";
        query_db(db, key);
    }
    destroy_db(db);
    return 0;
}