//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 20
#define MAX_VAL_LEN 50

typedef struct {
    char key[MAX_KEY_LEN];
    char val[MAX_VAL_LEN];
} entry_t;

typedef struct {
    entry_t *entries;
    int num_entries;
    int max_entries;
} db_t;

db_t *db_init(int max_entries) {
    db_t *db = (db_t*) malloc(sizeof(db_t));
    db->entries = (entry_t*) malloc(sizeof(entry_t) * max_entries);
    db->num_entries = 0;
    db->max_entries = max_entries;
    return db;
}

void db_destroy(db_t *db) {
    free(db->entries);
    free(db);
}

void db_insert(db_t *db, char *key, char *val) {
    if (db->num_entries >= db->max_entries) {
        printf("Database is full!\n");
        return;
    }

    int i;
    for (i = 0; i < db->num_entries; i++) {
        if (strcmp(db->entries[i].key, key) == 0) {
            printf("Key already exists!\n");
            return;
        }
    }

    strcpy(db->entries[db->num_entries].key, key);
    strcpy(db->entries[db->num_entries].val, val);
    db->num_entries++;
}

void db_search(db_t *db, char *key) {
    int i;
    for (i = 0; i < db->num_entries; i++) {
        if (strcmp(db->entries[i].key, key) == 0) {
            printf("Value: %s\n", db->entries[i].val);
            return;
        }
    }

    printf("Key not found!\n");
}

int main() {
    db_t *db = db_init(10);

    db_insert(db, "name", "John");
    db_insert(db, "age", "30");
    db_insert(db, "city", "New York");

    db_search(db, "name");
    db_search(db, "age");
    db_search(db, "city");

    db_destroy(db);

    return 0;
}