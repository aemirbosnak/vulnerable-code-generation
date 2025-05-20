//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_ENTRIES 1000

typedef struct Entry {
    char name[256];
    int index;
    struct Entry* next;
} Entry;

Entry* head = NULL;

pthread_mutex_t mutex;

void insert(char* name) {
    pthread_mutex_lock(&mutex);

    Entry* newEntry = malloc(sizeof(Entry));
    strcpy(newEntry->name, name);
    newEntry->index = head ? head->index + 1 : 0;
    newEntry->next = NULL;

    if (head) {
        head->next = newEntry;
    } else {
        head = newEntry;
    }

    pthread_mutex_unlock(&mutex);
}

int search(char* name) {
    pthread_mutex_lock(&mutex);

    Entry* current = head;
    while (current) {
        if (strcmp(current->name, name) == 0) {
            return current->index;
        }
        current = current->next;
    }

    return -1;
}

int main() {
    insert("John Doe");
    insert("Jane Doe");
    insert("Jack Doe");

    int index = search("Jane Doe");
    if (index != -1) {
        printf("Index of Jane Doe: %d\n", index);
    } else {
        printf("Jane Doe not found\n");
    }

    return 0;
}