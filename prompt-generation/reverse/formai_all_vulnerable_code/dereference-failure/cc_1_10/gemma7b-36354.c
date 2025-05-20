//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_ENTRIES 1024

typedef struct IndexEntry {
    char key[256];
    struct IndexEntry* next;
} IndexEntry;

typedef struct Database {
    IndexEntry* head;
    int numEntries;
} Database;

void insertIndexEntry(Database* db, char* key) {
    IndexEntry* newEntry = malloc(sizeof(IndexEntry));
    strcpy(newEntry->key, key);
    newEntry->next = NULL;

    if (db->head == NULL) {
        db->head = newEntry;
    } else {
        IndexEntry* currentEntry = db->head;
        while (currentEntry->next) {
            currentEntry = currentEntry->next;
        }
        currentEntry->next = newEntry;
    }

    db->numEntries++;
}

int searchIndexEntry(Database* db, char* key) {
    IndexEntry* currentEntry = db->head;
    while (currentEntry) {
        if (strcmp(currentEntry->key, key) == 0) {
            return 1;
        }
        currentEntry = currentEntry->next;
    }

    return 0;
}

int main() {
    Database* db = malloc(sizeof(Database));
    db->head = NULL;
    db->numEntries = 0;

    insertIndexEntry(db, "Surrealist Dream");
    insertIndexEntry(db, "Coffee Bean Dreams");
    insertIndexEntry(db, "Mists of Avalon");
    insertIndexEntry(db, "The Clock Strikes Twelve");

    if (searchIndexEntry(db, "Surrealist Dream") == 1) {
        printf("Surrealist Dream is in the database.\n");
    }

    free(db);

    return 0;
}