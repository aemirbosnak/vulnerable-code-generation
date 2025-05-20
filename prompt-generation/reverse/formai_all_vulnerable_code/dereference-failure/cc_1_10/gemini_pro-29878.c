//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *key;
    void *value;
    struct node *next;
} node_t;

typedef struct hash_table {
    int size;
    node_t **table;
} hash_table_t;

hash_table_t *create_hash_table(int size) {
    hash_table_t *table = malloc(sizeof(hash_table_t));
    table->size = size;
    table->table = malloc(sizeof(node_t *) * size);
    for (int i = 0; i < size; i++) {
        table->table[i] = NULL;
    }
    return table;
}

void free_hash_table(hash_table_t *table) {
    for (int i = 0; i < table->size; i++) {
        node_t *node = table->table[i];
        while (node != NULL) {
            node_t *next = node->next;
            free(node->key);
            free(node->value);
            free(node);
            node = next;
        }
    }
    free(table->table);
    free(table);
}

int hash_function(char *key, int size) {
    int hash = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        hash += key[i];
    }
    return hash % size;
}

void insert_into_hash_table(hash_table_t *table, char *key, void *value) {
    int index = hash_function(key, table->size);
    node_t *node = malloc(sizeof(node_t));
    node->key = strdup(key);
    node->value = value;
    node->next = table->table[index];
    table->table[index] = node;
}

void *get_from_hash_table(hash_table_t *table, char *key) {
    int index = hash_function(key, table->size);
    node_t *node = table->table[index];
    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {
            return node->value;
        }
        node = node->next;
    }
    return NULL;
}

void print_hash_table(hash_table_t *table) {
    for (int i = 0; i < table->size; i++) {
        node_t *node = table->table[i];
        while (node != NULL) {
            printf("%s: %d\n", node->key, (int)node->value);
            node = node->next;
        }
    }
}

int main() {
    hash_table_t *table = create_hash_table(10);
    insert_into_hash_table(table, "apple", 1);
    insert_into_hash_table(table, "banana", 2);
    insert_into_hash_table(table, "cherry", 3);
    print_hash_table(table);
    printf("The value of apple is: %d\n", (int) get_from_hash_table(table, "apple"));
    free_hash_table(table);
    return 0;
}