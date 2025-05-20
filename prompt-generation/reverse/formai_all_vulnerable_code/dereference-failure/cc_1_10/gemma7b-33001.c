//Gemma-7B DATASET v1.0 Category: Cryptographic hash function ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define HASH_SIZE 1024

struct hash_node {
    char *data;
    struct hash_node *next;
};

struct hash_table {
    struct hash_node **buckets;
    int size;
    int load_factor;
};

void hash_init(struct hash_table *ht) {
    ht->buckets = (struct hash_node **)malloc(ht->size * sizeof(struct hash_node *));
    for (int i = 0; i < ht->size; i++) {
        ht->buckets[i] = NULL;
    }
}

int hash_insert(struct hash_table *ht, char *data) {
    int hash = hash_func(data);
    struct hash_node *node = malloc(sizeof(struct hash_node));
    node->data = strdup(data);
    node->next = ht->buckets[hash];
    ht->buckets[hash] = node;
    return 0;
}

char *hash_search(struct hash_table *ht, char *data) {
    int hash = hash_func(data);
    struct hash_node *node = ht->buckets[hash];
    while (node) {
        if (strcmp(node->data, data) == 0) {
            return node->data;
        }
        node = node->next;
    }
    return NULL;
}

int hash_func(char *str) {
    int hash = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        hash = (hash * 33) + str[i];
    }
    return hash % HASH_SIZE;
}

int main() {
    struct hash_table *ht = malloc(sizeof(struct hash_table));
    ht->size = HASH_SIZE;
    ht->load_factor = 0.75;
    hash_init(ht);

    hash_insert(ht, "Alice");
    hash_insert(ht, "Bob");
    hash_insert(ht, "Charlie");
    hash_insert(ht, "Dave");

    char *data = hash_search(ht, "Bob");
    if (data) {
        printf("Data: %s\n", data);
    } else {
        printf("Data not found\n");
    }

    return 0;
}