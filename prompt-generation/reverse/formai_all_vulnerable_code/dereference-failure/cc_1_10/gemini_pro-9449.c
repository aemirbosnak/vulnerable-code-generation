//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *key;
    int value;
    struct Node *next;
} Node;

typedef struct HashTable {
    int size;
    Node **table;
} HashTable;

HashTable *create_hash_table(int size) {
    HashTable *hash_table = malloc(sizeof(HashTable));
    hash_table->size = size;
    hash_table->table = malloc(sizeof(Node *) * size);
    for (int i = 0; i < size; i++) {
        hash_table->table[i] = NULL;
    }
    return hash_table;
}

int hash_function(char *key, int size) {
    int hash = 0;
    for (int i = 0; i < strlen(key); i++) {
        hash += key[i];
    }
    return hash % size;
}

void insert_into_hash_table(HashTable *hash_table, char *key, int value) {
    int hash = hash_function(key, hash_table->size);
    Node *new_node = malloc(sizeof(Node));
    new_node->key = strdup(key);
    new_node->value = value;
    new_node->next = hash_table->table[hash];
    hash_table->table[hash] = new_node;
}

int get_from_hash_table(HashTable *hash_table, char *key) {
    int hash = hash_function(key, hash_table->size);
    Node *current_node = hash_table->table[hash];
    while (current_node != NULL) {
        if (strcmp(current_node->key, key) == 0) {
            return current_node->value;
        }
        current_node = current_node->next;
    }
    return -1;
}

void delete_from_hash_table(HashTable *hash_table, char *key) {
    int hash = hash_function(key, hash_table->size);
    Node *current_node = hash_table->table[hash];
    Node *previous_node = NULL;
    while (current_node != NULL) {
        if (strcmp(current_node->key, key) == 0) {
            if (previous_node == NULL) {
                hash_table->table[hash] = current_node->next;
            } else {
                previous_node->next = current_node->next;
            }
            free(current_node->key);
            free(current_node);
            return;
        }
        previous_node = current_node;
        current_node = current_node->next;
    }
}

void destroy_hash_table(HashTable *hash_table) {
    for (int i = 0; i < hash_table->size; i++) {
        Node *current_node = hash_table->table[i];
        while (current_node != NULL) {
            Node *next_node = current_node->next;
            free(current_node->key);
            free(current_node);
            current_node = next_node;
        }
    }
    free(hash_table->table);
    free(hash_table);
}

int main() {
    HashTable *hash_table = create_hash_table(10);
    insert_into_hash_table(hash_table, "John", 20);
    insert_into_hash_table(hash_table, "Mary", 25);
    insert_into_hash_table(hash_table, "Bob", 30);
    int age = get_from_hash_table(hash_table, "John");
    printf("John's age is %d\n", age);
    delete_from_hash_table(hash_table, "Mary");
    destroy_hash_table(hash_table);
    return 0;
}