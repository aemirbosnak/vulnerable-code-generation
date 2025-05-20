//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *key;
    int value;
} Index;

typedef struct {
    Index *index;
    int size;
} Database;

Database *create_database() {
    Database *db = malloc(sizeof(Database));
    db->index = NULL;
    db->size = 0;
    return db;
}

void insert_index(Database *db, char *key, int value) {
    db->index = realloc(db->index, sizeof(Index) * (db->size + 1));
    db->index[db->size].key = malloc(strlen(key) + 1);
    strcpy(db->index[db->size].key, key);
    db->index[db->size].value = value;
    db->size++;
}

int get_index(Database *db, char *key) {
    for (int i = 0; i < db->size; i++) {
        if (strcmp(db->index[i].key, key) == 0) {
            return db->index[i].value;
        }
    }
    return -1;
}

void print_database(Database *db) {
    for (int i = 0; i < db->size; i++) {
        printf("%s: %d\n", db->index[i].key, db->index[i].value);
    }
}

void free_database(Database *db) {
    for (int i = 0; i < db->size; i++) {
        free(db->index[i].key);
    }
    free(db->index);
    free(db);
}

int main() {
    Database *db = create_database();

    insert_index(db, "name", 1);
    insert_index(db, "age", 2);
    insert_index(db, "city", 3);

    print_database(db);

    int value = get_index(db, "name");
    printf("The value for the key 'name' is: %d\n", value);

    free_database(db);

    return 0;
}