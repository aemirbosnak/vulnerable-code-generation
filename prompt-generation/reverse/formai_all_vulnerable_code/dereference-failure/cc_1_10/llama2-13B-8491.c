//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_DB_SIZE 1024 * 1024
#define MAX_KEY_LEN 64
#define MAX_VALUE_LEN 256

typedef struct {
    char *key;
    char *value;
} db_entry_t;

typedef struct {
    char *name;
    size_t size;
    db_entry_t *entries;
} db_t;

db_t *db_create(const char *name) {
    db_t *db = malloc(sizeof(db_t));
    db->name = strdup(name);
    db->size = 0;
    db->entries = NULL;
    return db;
}

void db_insert(db_t *db, const char *key, const char *value) {
    db_entry_t *entry = malloc(sizeof(db_entry_t));
    entry->key = strdup(key);
    entry->value = strdup(value);
    if (db->size == 0) {
        db->entries = malloc(sizeof(db_entry_t));
        db->entries[0] = *entry;
    } else {
        db->entries = realloc(db->entries, (db->size + 1) * sizeof(db_entry_t));
        db->entries[db->size] = *entry;
    }
    db->size++;
}

void db_delete(db_t *db, const char *key) {
    int i = 0;
    for (i = 0; i < db->size; i++) {
        if (strcmp(db->entries[i].key, key) == 0) {
            break;
        }
    }
    if (i != db->size) {
        memmove(&db->entries[i], &db->entries[i + 1], (db->size - i - 1) * sizeof(db_entry_t));
        db->size--;
    }
}

const char *db_get(db_t *db, const char *key) {
    int i = 0;
    for (i = 0; i < db->size; i++) {
        if (strcmp(db->entries[i].key, key) == 0) {
            return db->entries[i].value;
        }
    }
    return NULL;
}

void db_destroy(db_t *db) {
    free(db->name);
    free(db->entries);
    free(db);
}

int main() {
    db_t *db = db_create("my_db");
    db_insert(db, "key1", "value1");
    db_insert(db, "key2", "value2");
    db_insert(db, "key3", "value3");
    db_delete(db, "key2");
    const char *value = db_get(db, "key2");
    printf("%s\n", value);
    db_destroy(db);
    return 0;
}