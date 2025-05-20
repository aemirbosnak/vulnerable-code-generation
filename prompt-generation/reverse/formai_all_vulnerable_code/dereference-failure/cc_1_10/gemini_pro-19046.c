//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create a linked list node
typedef struct Node {
    char *key;
    int value;
    struct Node *next;
} Node;

// Create a hash table
typedef struct HashTable {
    int size;
    Node **table;
} HashTable;

// Create a new hash table
HashTable *create_hash_table(int size) {
    HashTable *hash_table = malloc(sizeof(HashTable));
    hash_table->size = size;
    hash_table->table = malloc(sizeof(Node *) * size);
    for (int i = 0; i < size; i++) {
        hash_table->table[i] = NULL;
    }
    return hash_table;
}

// Hash a string key
int hash(char *key, int size) {
    int hash_value = 0;
    for (int i = 0; i < strlen(key); i++) {
        hash_value += key[i];
    }
    return hash_value % size;
}

// Insert a key-value pair into the hash table
void insert(HashTable *hash_table, char *key, int value) {
    int hash_value = hash(key, hash_table->size);
    Node *new_node = malloc(sizeof(Node));
    new_node->key = strdup(key);
    new_node->value = value;
    new_node->next = hash_table->table[hash_value];
    hash_table->table[hash_value] = new_node;
}

// Get the value for a key from the hash table
int get(HashTable *hash_table, char *key) {
    int hash_value = hash(key, hash_table->size);
    Node *node = hash_table->table[hash_value];
    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {
            return node->value;
        }
        node = node->next;
    }
    return -1;
}

// Print the hash table
void print_hash_table(HashTable *hash_table) {
    for (int i = 0; i < hash_table->size; i++) {
        Node *node = hash_table->table[i];
        printf("%d: ", i);
        while (node != NULL) {
            printf("(%s, %d) -> ", node->key, node->value);
            node = node->next;
        }
        printf("\n");
    }
}

// Free the hash table
void free_hash_table(HashTable *hash_table) {
    for (int i = 0; i < hash_table->size; i++) {
        Node *node = hash_table->table[i];
        while (node != NULL) {
            Node *next = node->next;
            free(node->key);
            free(node);
            node = next;
        }
    }
    free(hash_table->table);
    free(hash_table);
}

int main() {
    HashTable *hash_table = create_hash_table(10);
    insert(hash_table, "hello", 1);
    insert(hash_table, "world", 2);
    insert(hash_table, "brave", 3);
    print_hash_table(hash_table);
    printf("The value for 'hello' is %d\n", get(hash_table, "hello"));
    printf("The value for 'world' is %d\n", get(hash_table, "world"));
    printf("The value for 'brave' is %d\n", get(hash_table, "brave"));
    free_hash_table(hash_table);
    return 0;
}