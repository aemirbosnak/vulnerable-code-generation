//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: safe
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

    IndexEntry* newEntry = (IndexEntry*)malloc(sizeof(IndexEntry));
    strcpy(newEntry->key, key);
    newEntry->next = NULL;

    if (head == NULL) {
        head = newEntry;
    } else {
        IndexEntry* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newEntry;
    }

    pthread_mutex_unlock(&mutex);
}

int searchIndexEntry(char* key) {
    pthread_mutex_lock(&mutex);

    IndexEntry* current = head;
    while (current) {
        if (strcmp(current->key, key) == 0) {
            return 1;
        }
        current = current->next;
    }

    return 0;
}

int main() {
    insertIndexEntry("John Doe");
    insertIndexEntry("Jane Doe");
    insertIndexEntry("Bill Smith");

    if (searchIndexEntry("Jane Doe")) {
        printf("Jane Doe is in the index.\n");
    }

    return 0;
}