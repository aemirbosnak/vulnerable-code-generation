//MISTRAL-7B DATASET v1.0 Category: Database Indexing System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 101
#define KEY_LENGTH 50

typedef struct Node {
    char key[KEY_LENGTH];
    void *data;
    struct Node *next;
} Node;

Node **hash_table;

void init_hash_table() {
    int i;
    hash_table = (Node **)calloc(TABLE_SIZE, sizeof(Node *));
    for (i = 0; i < TABLE_SIZE; i++) {
        hash_table[i] = NULL;
    }
}

unsigned long hash_func(char *key) {
    unsigned long hash = 5381;
    int c;

    while ((c = *key++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % TABLE_SIZE;
}

void insert(char *key, void *data) {
    unsigned long index = hash_func(key);
    Node *new_node = (Node *)malloc(sizeof(Node));
    strcpy(new_node->key, key);
    new_node->data = data;
    new_node->next = hash_table[index];
    hash_table[index] = new_node;
}

void *search(char *key) {
    unsigned long index = hash_func(key);
    Node *current = hash_table[index];

    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->data;
        }
        current = current->next;
    }

    return NULL;
}

int main() {
    init_hash_table();

    // Sample data
    char keys[5][50] = {"apple", "banana", "cherry", "date", "elderberry"};
    int numbers[5] = {1, 2, 3, 4, 5};

    int i;
    for (i = 0; i < 5; i++) {
        insert(keys[i], &numbers[i]);
    }

    for (i = 0; i < 5; i++) {
        printf("Key: %s, Value: %d\n", keys[i], *(int *)search(keys[i]));
    }

    return 0;
}