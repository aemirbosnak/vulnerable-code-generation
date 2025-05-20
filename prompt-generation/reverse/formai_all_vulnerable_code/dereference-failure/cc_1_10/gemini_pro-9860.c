//GEMINI-pro DATASET v1.0 Category: Cryptographic hash function ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom hash function:
unsigned long long hash(const char *str) {
    unsigned long long h = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        h = h * 31 + str[i];
    }
    return h;
}

// Scalable hash table:
typedef struct node {
    char *key;
    unsigned long long value;
    struct node *next;
} node_t;

typedef struct hash_table {
    int size;
    node_t **buckets;
} hash_table_t;

hash_table_t *create_hash_table(int size) {
    hash_table_t *table = malloc(sizeof(hash_table_t));
    table->size = size;
    table->buckets = malloc(sizeof(node_t *) * size);
    for (int i = 0; i < size; i++) {
        table->buckets[i] = NULL;
    }
    return table;
}

void insert_hash_table(hash_table_t *table, char *key, unsigned long long value) {
    int index = hash(key) % table->size;
    node_t *new_node = malloc(sizeof(node_t));
    new_node->key = key;
    new_node->value = value;
    new_node->next = table->buckets[index];
    table->buckets[index] = new_node;
}

unsigned long long get_hash_table(hash_table_t *table, char *key) {
    int index = hash(key) % table->size;
    node_t *node = table->buckets[index];
    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {
            return node->value;
        }
        node = node->next;
    }
    return 0;
}

void delete_hash_table(hash_table_t *table) {
    for (int i = 0; i < table->size; i++) {
        node_t *node = table->buckets[i];
        while (node != NULL) {
            node_t *next = node->next;
            free(node->key);
            free(node);
            node = next;
        }
    }
    free(table->buckets);
    free(table);
}

// Example usage:
int main() {
    hash_table_t *table = create_hash_table(100);

    insert_hash_table(table, "foo", 123);
    insert_hash_table(table, "bar", 456);

    printf("foo: %llu\n", get_hash_table(table, "foo"));
    printf("bar: %llu\n", get_hash_table(table, "bar"));
    printf("baz: %llu\n", get_hash_table(table, "baz"));

    delete_hash_table(table);

    return 0;
}