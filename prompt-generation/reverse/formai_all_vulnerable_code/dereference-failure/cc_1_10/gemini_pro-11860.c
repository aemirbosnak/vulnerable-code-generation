//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *key;
    void *value;
    struct node *next;
} node;

typedef struct hashtable {
    int size;
    node **table;
} hashtable;

hashtable *create_hashtable(int size) {
    hashtable *ht = malloc(sizeof(hashtable));
    ht->size = size;
    ht->table = malloc(sizeof(node *) * size);
    for (int i = 0; i < size; i++) {
        ht->table[i] = NULL;
    }
    return ht;
}

void insert(hashtable *ht, char *key, void *value) {
    int index = hash(key, ht->size);
    node *new_node = malloc(sizeof(node));
    new_node->key = key;
    new_node->value = value;
    new_node->next = ht->table[index];
    ht->table[index] = new_node;
}

void *get(hashtable *ht, char *key) {
    int index = hash(key, ht->size);
    node *current = ht->table[index];
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }
    return NULL;
}

int hash(char *key, int size) {
    int hash = 0;
    for (int i = 0; i < strlen(key); i++) {
        hash += key[i];
    }
    return hash % size;
}

int main() {
    hashtable *ht = create_hashtable(10);
    insert(ht, "key1", "value1");
    insert(ht, "key2", "value2");
    insert(ht, "key3", "value3");
    printf("%s\n", get(ht, "key1")); // value1
    printf("%s\n", get(ht, "key2")); // value2
    printf("%s\n", get(ht, "key3")); // value3
    return 0;
}