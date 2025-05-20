//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_KEY_LEN 50
#define MAX_VAL_LEN 100

typedef struct {
    char key[MAX_KEY_LEN];
    char value[MAX_VAL_LEN];
} Record;

typedef struct {
    Record *records[MAX_RECORDS];
    int count;
} Index;

Index* create_index() {
    Index* idx = (Index*)malloc(sizeof(Index));
    idx->count = 0;
    for (int i = 0; i < MAX_RECORDS; i++) {
        idx->records[i] = NULL;
    }
    return idx;
}

void free_index(Index* idx) {
    for (int i = 0; i < idx->count; i++) {
        free(idx->records[i]);
    }
    free(idx);
}

int hash_key(const char* key) {
    int hash = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        hash += key[i];
    }
    return hash % MAX_RECORDS;
}

void insert_record(Index* idx, const char* key, const char* value) {
    if (idx->count >= MAX_RECORDS) {
        printf("Index is full! Cannot insert more records.\n");
        return;
    }
    
    Record* record = (Record*)malloc(sizeof(Record));
    strcpy(record->key, key);
    strcpy(record->value, value);
    
    int hash = hash_key(key);

    while (idx->records[hash] != NULL) {
        hash = (hash + 1) % MAX_RECORDS; // Linear probing
    }

    idx->records[hash] = record;
    idx->count++;
}

char* search_index(Index* idx, const char* key) {
    int hash = hash_key(key);

    while (idx->records[hash] != NULL) {
        if (strcmp(idx->records[hash]->key, key) == 0) {
            return idx->records[hash]->value;
        }
        hash = (hash + 1) % MAX_RECORDS;
    }

    return NULL; // Not found
}

void display_index(Index* idx) {
    for (int i = 0; i < MAX_RECORDS; i++) {
        if (idx->records[i] != NULL) {
            printf("Index[%d]: Key = %s, Value = %s\n", i, idx->records[i]->key, idx->records[i]->value);
        }
    }
}

int main() {
    Index* idx = create_index();
    
    printf("Welcome to the C Database Indexing System!\n");
    
    insert_record(idx, "name", "Alice");
    insert_record(idx, "age", "30");
    insert_record(idx, "city", "Wonderland");
    insert_record(idx, "profession", "Developer");
    
    printf("\nCurrent Records:\n");
    display_index(idx);
    
    printf("\nSearching for 'age'...\n");
    char* value = search_index(idx, "age");
    if (value) {
        printf("Found! Value = %s\n", value);
    } else {
        printf("Key not found!\n");
    }

    // Attempt to insert more records beyond the limit
    for (int i = 0; i < 110; i++) {
        char key[10], val[10];
        sprintf(key, "key%d", i);
        sprintf(val, "value%d", i);
        insert_record(idx, key, val);
    }
    
    printf("\nAfter Attempts to Overfill Index:\n");
    display_index(idx);
    
    free_index(idx);
    return 0;
}