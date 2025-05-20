//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: mind-bending
// A C-ian Odyssey: A Surreal Database Indexing System

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

// Structures to encapsulate our mind-bending reality
typedef struct {
    char* key;
    int value;
} KV; // Key-Value Pair

typedef struct {
    KV* data;
    int size, capacity;
} DB; // Database

// A mad scientist's formula to create a database
DB* dbCreate() {
    DB* db = malloc(sizeof(DB));
    db->size = 0;
    db->capacity = 2;
    db->data = malloc(db->capacity * sizeof(KV));
    return db;
}

// A magic spell to add a pair to the database
void dbInsert(DB* db, char* key, int value) {
    if (db->size == db->capacity) {
        db->capacity *= 2;
        db->data = realloc(db->data, db->capacity * sizeof(KV));
    }
    db->data[db->size++] = (KV){.key = strdup(key), .value = value};
}

// A ritual to search for a key-value pair
KV* dbSearch(DB* db, char* key) {
    for (int i = 0; i < db->size; i++) {
        if (strcmp(db->data[i].key, key) == 0) {
            return &db->data[i];
        }
    }
    return NULL;
}

// A peculiar algorithm to delete a key-value pair
void dbDelete(DB* db, char* key) {
    KV* kv = dbSearch(db, key);
    if (kv) {
        int index = kv - db->data;
        free(kv->key);
        for (int i = index + 1; i < db->size; i++) {
            db->data[i - 1] = db->data[i];
        }
        db->size--;
    }
}

// A mesmerizing dance to traverse the database
void dbTraverse(DB* db, void (*visit)(KV*)) {
    for (int i = 0; i < db->size; i++) {
        visit(&db->data[i]);
    }
}

// A clandestine ritual to print a key-value pair
void printKV(KV* kv) {
    printf("{%s: %d}\n", kv->key, kv->value);
}

// A whirlwind of actions to showcase our database wizardry
int main() {
    DB* db = dbCreate();
    dbInsert(db, "Alice", 24);
    dbInsert(db, "Bob", 30);
    dbInsert(db, "Carol", 27);
    printf("Mind-bending database:\n");
    dbTraverse(db, &printKV);
    printf("Oh, the wonders of a key-value universe!\n");
    return 0;
}