//FormAI DATASET v1.0 Category: Database Indexing System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int key;
    int value;
    struct node* next;
};

struct hash_table {
    int size;
    struct node** table;
};

int hash(int key, int size) {
    return key % size;
}

struct hash_table* init_table(int size) {
    struct hash_table* table = malloc(sizeof(struct hash_table));
    table->size = size;
    table->table = malloc(sizeof(struct node*) * size);
    memset(table->table, 0, sizeof(struct node*) * size);
    return table;
}

void insert(struct hash_table* table, int key, int value) {
    int index = hash(key, table->size);
    struct node* new_node = malloc(sizeof(struct node));
    new_node->key = key;
    new_node->value = value;
    new_node->next = table->table[index];
    table->table[index] = new_node;
}

int* find(struct hash_table* table, int key) {
    int index = hash(key, table->size);
    struct node* current = table->table[index];
    while (current != NULL) {
        if (current->key == key) {
            return &(current->value);
        }
        current = current->next;
    }
    return NULL;
}

int main() {
    struct hash_table* table = init_table(10);
    insert(table, 1, 10);
    insert(table, 11, 20);
    insert(table, 5, 30);
    int* value = find(table, 1);
    if (value != NULL) {
        printf("Value is %d\n", *value);
    }
    value = find(table, 2);
    if (value == NULL) {
        printf("Key not found\n");
    }
    return 0;
}