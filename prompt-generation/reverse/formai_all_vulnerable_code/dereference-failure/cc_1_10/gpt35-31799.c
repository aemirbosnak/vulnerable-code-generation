//FormAI DATASET v1.0 Category: Database Indexing System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *key;
    int value;
} Entry;

typedef struct {
    Entry *data;
    int dataSize;
    int capacity;
} HashTable;

void initTable(HashTable *table, int capacity) {
    table->data = (Entry*)malloc(sizeof(Entry) * capacity);
    table->dataSize = 0;
    table->capacity = capacity;
    for(int i = 0; i < capacity; i++) {
        table->data[i].key = NULL;
        table->data[i].value = -1;
    }
}

int hash(char *key, int capacity) {
    int hash = 0;
    for(int i = 0; i < strlen(key); i++) {
        hash += key[i];
    }
    return hash % capacity;
}

void insert(HashTable *table, char *key, int value) {
    int index = hash(key, table->capacity);
    while(table->data[index].value != -1 && strcmp(table->data[index].key, key) != 0) {
        index++;
        index = index % table->capacity;
    }
    table->data[index].key = key;
    table->data[index].value = value;
    table->dataSize++;
}

int find(HashTable *table, char *key) {
    int index = hash(key, table->capacity);
    while(table->data[index].key != NULL) {
        if(strcmp(table->data[index].key, key) == 0) {
            return table->data[index].value;
        }
        index++;
        index = index % table->capacity;
    }
    return -1;
}

void printTable(HashTable *table) {
    printf("Data:\n");
    for(int i = 0; i < table->capacity; i++) {
        if(table->data[i].value != -1) {
            printf("%s - %d\n", table->data[i].key, table->data[i].value);
        }
    }
}

int main() {
    HashTable table;
    initTable(&table, 10);
    insert(&table, "apple", 1);
    insert(&table, "banana", 2);
    insert(&table, "orange", 3);
    insert(&table, "grape", 4);
    insert(&table, "kiwi", 5);
    printTable(&table);
    printf("Find value for apple: %d\n", find(&table, "apple"));
    printf("Find value for banana: %d\n", find(&table, "banana"));
    printf("Find value for watermelon: %d\n", find(&table, "watermelon"));
    return 0;
}