//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define DB_FILE "mydatabase"
#define DB_SIZE 1024*1024*10

typedef struct {
    char *key;
    char *value;
} db_entry;

typedef struct {
    db_entry **entries;
    int num_entries;
    int capacity;
} db;

void init_db(db *dbp) {
    dbp->entries = calloc(10, sizeof(db_entry *));
    dbp->num_entries = 0;
    dbp->capacity = 10;
}

void insert_db(db *dbp, char *key, char *value) {
    if (dbp->num_entries >= dbp->capacity) {
        int i;
        db_entry **new_entries = realloc(dbp->entries, (dbp->capacity *= 2) * sizeof(db_entry *));
        for (i = 0; i < dbp->num_entries; i++) {
            new_entries[i] = dbp->entries[i];
        }
        free(dbp->entries);
        dbp->entries = new_entries;
    }
    dbp->entries[dbp->num_entries++] = malloc(sizeof(db_entry));
    dbp->entries[dbp->num_entries - 1]->key = key;
    dbp->entries[dbp->num_entries - 1]->value = value;
}

char *get_db(db *dbp, char *key) {
    int i;
    for (i = 0; i < dbp->num_entries; i++) {
        if (strcmp(dbp->entries[i]->key, key) == 0) {
            return dbp->entries[i]->value;
        }
    }
    return NULL;
}

void delete_db(db *dbp, char *key) {
    int i;
    for (i = 0; i < dbp->num_entries; i++) {
        if (strcmp(dbp->entries[i]->key, key) == 0) {
            free(dbp->entries[i]->value);
            dbp->entries[i] = NULL;
            break;
        }
    }
}

int main() {
    db dbp;
    init_db(&dbp);

    char *key1 = "key1";
    char *value1 = "value1";
    char *key2 = "key2";
    char *value2 = "value2";

    insert_db(&dbp, key1, value1);
    insert_db(&dbp, key2, value2);

    char *val = get_db(&dbp, key1);
    assert(val != NULL);
    assert(strcmp(val, value1) == 0);

    val = get_db(&dbp, key2);
    assert(val != NULL);
    assert(strcmp(val, value2) == 0);

    delete_db(&dbp, key1);

    val = get_db(&dbp, key1);
    assert(val == NULL);

    return 0;
}