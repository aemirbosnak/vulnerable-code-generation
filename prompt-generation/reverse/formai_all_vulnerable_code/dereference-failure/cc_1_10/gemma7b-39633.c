//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_SIZE 100

typedef struct IndexNode {
    char key[MAX_INDEX_SIZE];
    struct IndexNode* next;
} IndexNode;

typedef struct Database {
    IndexNode** buckets;
    int size;
} Database;

Database* createDatabase() {
    Database* db = malloc(sizeof(Database));
    db->buckets = NULL;
    db->size = 0;
    return db;
}

void insertIndex(Database* db, char* key) {
    IndexNode* newNode = malloc(sizeof(IndexNode));
    strcpy(newNode->key, key);
    newNode->next = NULL;

    if (db->buckets == NULL) {
        db->buckets = malloc(sizeof(IndexNode*) * MAX_INDEX_SIZE);
        db->buckets[0] = newNode;
    } else {
        IndexNode* lastNode = db->buckets[db->size - 1];
        lastNode->next = newNode;
        db->size++;
    }
}

int searchIndex(Database* db, char* key) {
    for (int i = 0; i < db->size; i++) {
        if (strcmp(db->buckets[i]->key, key) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    Database* db = createDatabase();
    insertIndex(db, "John Doe");
    insertIndex(db, "Jane Doe");
    insertIndex(db, "Bill Smith");

    if (searchIndex(db, "John Doe") == 1) {
        printf("John Doe is in the database.\n");
    }

    if (searchIndex(db, "Bob Smith") == 0) {
        printf("Bob Smith is not in the database.\n");
    }

    return 0;
}