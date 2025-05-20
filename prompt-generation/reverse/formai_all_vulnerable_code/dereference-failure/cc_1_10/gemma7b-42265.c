//Gemma-7B DATASET v1.0 Category: Cryptographic hash function ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_HASH_SIZE 1024

typedef struct HashNode {
    char *key;
    struct HashNode *next;
} HashNode;

typedef struct HashTable {
    HashNode **buckets;
    int size;
} HashTable;

void hash_init(HashTable *ht) {
    ht->buckets = (HashNode **)malloc(MAX_HASH_SIZE * sizeof(HashNode *));
    ht->size = MAX_HASH_SIZE;
}

int hash_insert(HashTable *ht, char *key) {
    int hash_index = hash(key);
    HashNode *node = (HashNode *)malloc(sizeof(HashNode));
    node->key = key;
    node->next = ht->buckets[hash_index] = node;
    return hash_index;
}

int hash(char *key) {
    int i = 0;
    int hash_value = 0;
    while (key[i] != '\0') {
        hash_value += key[i] * i;
        i++;
    }
    return hash_value % MAX_HASH_SIZE;
}

int main() {
    HashTable *ht = malloc(sizeof(HashTable));
    hash_init(ht);

    char *key1 = "Hello, world!";
    hash_insert(ht, key1);

    char *key2 = "Goodbye, cruel world!";
    hash_insert(ht, key2);

    char *key3 = "This is a random key";
    hash_insert(ht, key3);

    // Print the hash values of the keys
    for (int i = 0; i < ht->size; i++) {
        HashNode *node = ht->buckets[i];
        while (node) {
            printf("%s hash value: %d\n", node->key, hash(node->key));
            node = node->next;
        }
    }

    return 0;
}