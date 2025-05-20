//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INDEX_SIZE 1024

typedef struct Node {
    char data[MAX_INDEX_SIZE];
    struct Node* next;
} Node;

struct HashTable {
    int size;
    Node** buckets;
};

void hash_table_init(struct HashTable* ht, int size) {
    ht->size = size;
    ht->buckets = (Node**)malloc(size * sizeof(Node*));
    for (int i = 0; i < size; i++) {
        ht->buckets[i] = NULL;
    }
}

void hash_table_insert(struct HashTable* ht, char* data) {
    int hash = hash_function(data);
    Node* node = (Node*)malloc(sizeof(Node));
    strcpy(node->data, data);
    node->next = ht->buckets[hash];
    ht->buckets[hash] = node;
}

char* hash_table_search(struct HashTable* ht, char* data) {
    int hash = hash_function(data);
    Node* current = ht->buckets[hash];
    while (current) {
        if (strcmp(current->data, data) == 0) {
            return current->data;
        }
        current = current->next;
    }
    return NULL;
}

int hash_function(char* data) {
    return (int)data % MAX_INDEX_SIZE;
}

int main() {
    struct HashTable* ht = malloc(sizeof(struct HashTable));
    hash_table_init(ht, 10);

    hash_table_insert(ht, "apple");
    hash_table_insert(ht, "banana");
    hash_table_insert(ht, "orange");
    hash_table_insert(ht, "peach");

    char* result = hash_table_search(ht, "banana");
    if (result) {
        printf("Found: %s\n", result);
    } else {
        printf("Not found.\n");
    }

    return 0;
}