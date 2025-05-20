//Gemma-7B DATASET v1.0 Category: Checksum Calculator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct HashNode {
    char *key;
    int hashValue;
    struct HashNode *next;
} HashNode;

typedef struct HashTable {
    HashNode **buckets;
    int size;
    int capacity;
} HashTable;

int hashFunction(char *key) {
    int hashValue = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        hashValue = (hashValue * 33) + key[i];
    }
    return hashValue % MAX_BUFFER_SIZE;
}

void insertIntoHash(HashTable *table, char *key) {
    int hashValue = hashFunction(key);
    HashNode *newNode = malloc(sizeof(HashNode));
    newNode->key = strdup(key);
    newNode->hashValue = hashValue;
    newNode->next = NULL;

    if (table->buckets[hashValue] == NULL) {
        table->buckets[hashValue] = newNode;
    } else {
        HashNode *current = table->buckets[hashValue];
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

int main() {
    HashTable *table = malloc(sizeof(HashTable));
    table->buckets = malloc(MAX_BUFFER_SIZE * sizeof(HashNode *));
    table->size = 0;
    table->capacity = MAX_BUFFER_SIZE;

    insertIntoHash(table, "a");
    insertIntoHash(table, "b");
    insertIntoHash(table, "c");
    insertIntoHash(table, "d");

    for (int i = 0; i < MAX_BUFFER_SIZE; i++) {
        if (table->buckets[i] != NULL) {
            printf("Key: %s, Hash Value: %d\n", table->buckets[i]->key, table->buckets[i]->hashValue);
        }
    }

    return 0;
}