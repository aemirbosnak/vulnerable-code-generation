//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_INDEX_SIZE 100

typedef struct IndexEntry {
    char key[MAX_INDEX_SIZE];
    struct IndexEntry* next;
} IndexEntry;

pthread_mutex_t mutex;

IndexEntry* head = NULL;

void insertIndexEntry(char* key) {
    pthread_mutex_lock(&mutex);

    IndexEntry* newEntry = malloc(sizeof(IndexEntry));
    strcpy(newEntry->key, key);

    if (head == NULL) {
        head = newEntry;
    } else {
        IndexEntry* currentEntry = head;
        while (currentEntry->next) {
            currentEntry = currentEntry->next;
        }
        currentEntry->next = newEntry;
    }

    pthread_mutex_unlock(&mutex);
}

int searchIndexEntry(char* key) {
    pthread_mutex_lock(&mutex);

    IndexEntry* currentEntry = head;
    while (currentEntry) {
        if (strcmp(currentEntry->key, key) == 0) {
            return 1;
        }
        currentEntry = currentEntry->next;
    }

    return 0;
}

int main() {
    insertIndexEntry("John Doe");
    insertIndexEntry("Jane Doe");
    insertIndexEntry("Peter Pan");

    if (searchIndexEntry("John Doe") == 1) {
        printf("John Doe is in the index.\n");
    }

    if (searchIndexEntry("Peter Pan") == 1) {
        printf("Peter Pan is in the index.\n");
    }

    return 0;
}