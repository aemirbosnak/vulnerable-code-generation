//FormAI DATASET v1.0 Category: Database Indexing System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key;
    int data;
    struct node *next;
} Node;

typedef struct {
    Node **table;
    int size;
} HashTable;

HashTable *createHashTable(int size) {
    HashTable *table = (HashTable*)malloc(sizeof(HashTable));
    table->size = size;
    table->table = (Node**)calloc(size, sizeof(Node*));
    return table;
}

int hash(HashTable *table, int key) {
    return key % table->size;
}

void insert(HashTable *table, int key, int data) {
    int index = hash(table, key);
    Node *node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->data = data;
    node->next = table->table[index];
    table->table[index] = node;
}

int *get(HashTable *table, int key) {
    int index = hash(table, key);
    Node *node = table->table[index];
    while (node != NULL && node->key != key) {
        node = node->next;
    }
    if (node == NULL) {
        return NULL;
    } else {
        return &(node->data);
    }
}

int main() {
    HashTable *table = createHashTable(10);
    insert(table, 5, 10);
    insert(table, 7, 20);
    int *value = get(table, 5);
    if (value != NULL) {
        printf("Value for key 5 is %d\n", *value);
    } else {
        printf("Key 5 not found\n");
    }
    value = get(table, 2);
    if (value != NULL) {
        printf("Value for key 2 is %d\n", *value);
    } else {
        printf("Key 2 not found\n");
    }
    return 0;
}