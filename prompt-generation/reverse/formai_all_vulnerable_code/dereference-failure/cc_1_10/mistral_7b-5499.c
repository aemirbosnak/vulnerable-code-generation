//MISTRAL-7B DATASET v1.0 Category: Database Indexing System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 1000

typedef struct {
    char key[10];
    int value;
} Data;

typedef struct HashNode {
    Data data;
    struct HashNode *next;
} HashNode;

unsigned int hash_function(char *key) {
    unsigned int hash = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        hash += hash * 31 + key[i];
    }
    return hash % TABLE_SIZE;
}

void insert(HashNode **table, Data data) {
    unsigned int hash = hash_function(data.key);
    HashNode *node = (HashNode *)malloc(sizeof(HashNode));
    node->data = data;
    node->next = table[hash];
    table[hash] = node;
}

Data *search(HashNode **table, char *key) {
    unsigned int hash = hash_function(key);
    HashNode *current = table[hash];

    while (current != NULL) {
        if (strcmp(current->data.key, key) == 0) {
            return &current->data;
        }
        current = current->next;
    }

    return NULL;
}

int main() {
    HashNode *table[TABLE_SIZE] = {NULL};

    Data records[10] = {
        {"apple", 1},
        {"banana", 2},
        {"cherry", 3},
        {"date", 4},
        {"elderberry", 5},
        {"fig", 6},
        {"grape", 7},
        {"honeydew", 8},
        {"kiwi", 9},
        {"lemon", 10}};

    for (int i = 0; i < 10; i++) {
        insert(table, records[i]);
    }

    Data *found_data;

    for (int i = 0; i < 10; i++) {
        found_data = search(table, records[i].key);
        if (found_data != NULL) {
            printf("Found data with key %s and value %d\n", found_data->key, found_data->value);
        }
    }

    return 0;
}