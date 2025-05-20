//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 100
#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_ENTRY_LENGTH];
} entry_t;

typedef struct {
    int num_entries;
    entry_t entries[MAX_ENTRIES];
} database_t;

database_t* create_database() {
    database_t* db = (database_t*)malloc(sizeof(database_t));
    db->num_entries = 0;
    return db;
}

void destroy_database(database_t* db) {
    free(db);
}

int add_entry(database_t* db, char* key, char* value) {
    if (db->num_entries >= MAX_ENTRIES) {
        return 0;
    }

    strncpy(db->entries[db->num_entries].key, key, MAX_KEY_LENGTH);
    strncpy(db->entries[db->num_entries].value, value, MAX_ENTRY_LENGTH);

    db->num_entries++;

    return 1;
}

int search_entry(database_t* db, char* key, char* value) {
    int i;

    for (i = 0; i < db->num_entries; i++) {
        if (strcmp(db->entries[i].key, key) == 0) {
            strncpy(value, db->entries[i].value, MAX_ENTRY_LENGTH);
            return 1;
        }
    }

    return 0;
}

int main() {
    database_t* db = create_database();

    add_entry(db, "John", "123 Main St");
    add_entry(db, "Jane", "456 Elm St");

    char value[MAX_ENTRY_LENGTH];
    search_entry(db, "John", value);
    printf("%s\n", value);

    destroy_database(db);

    return 0;
}