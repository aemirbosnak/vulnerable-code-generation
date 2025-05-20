//Gemma-7B DATASET v1.0 Category: Cryptographic hash function ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define HASH_SIZE 1024

#define HASH_PRIME 3

typedef struct HashNode {
    char *key;
    int value;
    struct HashNode *next;
} HashNode;

HashNode **hash_table = NULL;

void hash_init() {
    hash_table = malloc(HASH_SIZE * sizeof(HashNode *));
    for (int i = 0; i < HASH_SIZE; i++) {
        hash_table[i] = NULL;
    }
}

int hash_insert(char *key, int value) {
    int hash_index = hash(key);
    HashNode *new_node = malloc(sizeof(HashNode));
    new_node->key = strdup(key);
    new_node->value = value;
    new_node->next = hash_table[hash_index];
    hash_table[hash_index] = new_node;
    return 0;
}

int hash(char *key) {
    unsigned int hash_value = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        hash_value = (hash_value * HASH_PRIME) + key[i];
    }
    return hash_value % HASH_SIZE;
}

int main() {
    hash_init();
    hash_insert("Alice", 12);
    hash_insert("Bob", 14);
    hash_insert("Charlie", 16);

    HashNode *node = hash_table[hash("Alice")];
    if (node) {
        printf("%s has a value of %d\n", node->key, node->value);
    }

    return 0;
}