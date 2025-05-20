//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEYS 10000 // Maximum number of keys that can be stored in the table

// Node structure for the hash table
typedef struct node {
    char *key;
    int value;
    struct node *next;
} Node;

// Hash table structure
typedef struct {
    Node **table;
    int size;
} HashTable;

// Function to initialize the hash table
void init(HashTable *ht, int size) {
    ht->table = (Node **)malloc(size * sizeof(Node *));
    ht->size = size;
    for (int i = 0; i < size; i++) {
        ht->table[i] = NULL;
    }
}

// Function to insert a key-value pair into the hash table
void insert(HashTable *ht, char *key, int value) {
    int index = hash(key) % ht->size;
    Node *node = ht->table[index];
    while (node!= NULL) {
        if (strcmp(node->key, key) == 0) {
            node->value = value;
            return;
        }
        node = node->next;
    }
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = strdup(key);
    newNode->value = value;
    newNode->next = ht->table[index];
    ht->table[index] = newNode;
}

// Function to delete a key-value pair from the hash table
void delete(HashTable *ht, char *key) {
    int index = hash(key) % ht->size;
    Node *node = ht->table[index];
    while (node!= NULL) {
        if (strcmp(node->key, key) == 0) {
            free(node->key);
            free(node);
            ht->table[index] = node->next;
            return;
        }
        node = node->next;
    }
}

// Function to search for a key in the hash table
int search(HashTable *ht, char *key) {
    int index = hash(key) % ht->size;
    Node *node = ht->table[index];
    while (node!= NULL) {
        if (strcmp(node->key, key) == 0) {
            return node->value;
        }
        node = node->next;
    }
    return -1; // Key not found
}

// Hash function
int hash(char *key) {
    int hash = 0;
    for (int i = 0; i < strlen(key); i++) {
        hash = (hash * 31 + key[i]) % MAX_KEYS;
    }
    return hash;
}

int main() {
    HashTable ht;
    init(&ht, 100);
    insert(&ht, "apple", 1);
    insert(&ht, "banana", 2);
    insert(&ht, "cherry", 3);
    int value = search(&ht, "banana");
    printf("%d\n", value);
    delete(&ht, "banana");
    value = search(&ht, "banana");
    printf("%d\n", value);
    return 0;
}