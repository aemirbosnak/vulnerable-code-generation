//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LEN 100
#define MAX_VAL_LEN 1000
#define MAX_DB_SIZE 10000

typedef struct {
    char key[MAX_KEY_LEN];
    char val[MAX_VAL_LEN];
} db_entry;

typedef struct {
    db_entry entries[MAX_DB_SIZE];
    int num_entries;
} db;

db *db_create() {
    db *d = (db *) malloc(sizeof(db));
    d->num_entries = 0;
    return d;
}

void db_destroy(db *d) {
    free(d);
}

int db_add(db *d, char *key, char *val) {
    if (d->num_entries >= MAX_DB_SIZE) {
        printf("Error: Database is full.\n");
        return -1;
    }

    db_entry *e = &d->entries[d->num_entries];
    strcpy(e->key, key);
    strcpy(e->val, val);
    d->num_entries++;

    return 0;
}

void db_print(db *d) {
    for (int i = 0; i < d->num_entries; i++) {
        printf("%s: %s\n", d->entries[i].key, d->entries[i].val);
    }
}

int main() {
    db *db = db_create();
    db_add(db, "apple", "red");
    db_add(db, "banana", "yellow");
    db_add(db, "cherry", "red");
    db_print(db);
    db_destroy(db);

    return 0;
}