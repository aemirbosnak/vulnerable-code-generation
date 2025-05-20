//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#define MAX_INDEX_ENTRIES 1024

typedef struct IndexEntry {
    char key[256];
    int data_ptr;
    struct IndexEntry* next;
} IndexEntry;

IndexEntry* head = NULL;

void insert_index_entry(char* key, int data_ptr) {
    IndexEntry* new_entry = (IndexEntry*)malloc(sizeof(IndexEntry));
    strcpy(new_entry->key, key);
    new_entry->data_ptr = data_ptr;
    new_entry->next = NULL;

    if (head == NULL) {
        head = new_entry;
    } else {
        IndexEntry* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_entry;
    }
}

int search_index(char* key) {
    IndexEntry* current = head;
    while (current) {
        if (strcmp(current->key, key) == 0) {
            return current->data_ptr;
        }
        current = current->next;
    }
    return -1;
}

int main() {
    insert_index_entry("John Doe", 10);
    insert_index_entry("Jane Doe", 20);
    insert_index_entry("Bill Smith", 30);

    int data_ptr = search_index("Jane Doe");
    if (data_ptr != -1) {
        printf("Data pointer for Jane Doe: %d\n", data_ptr);
    } else {
        printf("Key not found.\n");
    }

    return 0;
}