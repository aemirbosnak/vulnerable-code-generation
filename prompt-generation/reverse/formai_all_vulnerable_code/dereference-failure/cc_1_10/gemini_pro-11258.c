//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *key;
    int value;
} Pair;

typedef struct {
    Pair *pairs;
    int size;
    int capacity;
} Database;

Database *createDatabase() {
    Database *db = malloc(sizeof(Database));
    db->pairs = malloc(sizeof(Pair) * 10);
    db->size = 0;
    db->capacity = 10;
    return db;
}

void destroyDatabase(Database *db) {
    for (int i = 0; i < db->size; i++) {
        free(db->pairs[i].key);
    }
    free(db->pairs);
    free(db);
}

void insert(Database *db, char *key, int value) {
    if (db->size == db->capacity) {
        db->pairs = realloc(db->pairs, sizeof(Pair) * db->capacity * 2);
        db->capacity *= 2;
    }
    db->pairs[db->size].key = strdup(key);
    db->pairs[db->size].value = value;
    db->size++;
}

int get(Database *db, char *key) {
    for (int i = 0; i < db->size; i++) {
        if (strcmp(db->pairs[i].key, key) == 0) {
            return db->pairs[i].value;
        }
    }
    return -1;
}

int main() {
    Database *db = createDatabase();
    insert(db, "Alan Turing", 100);
    insert(db, "Ada Lovelace", 200);
    insert(db, "Grace Hopper", 300);
    printf("%d\n", get(db, "Alan Turing")); // 100
    printf("%d\n", get(db, "Ada Lovelace")); // 200
    printf("%d\n", get(db, "Grace Hopper")); // 300
    destroyDatabase(db);
    return 0;
}