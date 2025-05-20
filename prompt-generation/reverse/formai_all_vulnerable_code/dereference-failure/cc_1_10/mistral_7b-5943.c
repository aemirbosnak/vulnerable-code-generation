//MISTRAL-7B DATASET v1.0 Category: Database Indexing System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 101

typedef struct {
    char key[256];
    int value;
} Record;

typedef struct HashNode {
    Record data;
    struct HashNode *next;
} HashNode;

typedef struct HashTable {
    HashNode **nodes;
} HashTable;

unsigned int hash_func(const char *key) {
    unsigned int hash = 5381;
    int c;

    while ((c = *key++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % TABLE_SIZE;
}

HashTable *create_hash_table() {
    HashTable *ht = malloc(sizeof(HashTable));
    ht->nodes = calloc(TABLE_SIZE, sizeof(HashNode *));
    return ht;
}

void put(HashTable *ht, const char *key, int value) {
    unsigned int index = hash_func(key);
    HashNode *new_node = malloc(sizeof(HashNode));

    strcpy(new_node->data.key, key);
    new_node->data.value = value;
    new_node->next = ht->nodes[index];
    ht->nodes[index] = new_node;
}

int get(HashTable *ht, const char *key) {
    unsigned int index = hash_func(key);
    HashNode *current = ht->nodes[index];

    while (current != NULL) {
        if (strcmp(current->data.key, key) == 0)
            return current->data.value;
        current = current->next;
    }

    return -1;
}

void destroy_hash_table(HashTable *ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        HashNode *current = ht->nodes[i];
        HashNode *next;

        while (current != NULL) {
            next = current->next;
            free(current);
            current = next;
        }
    }

    free(ht->nodes);
    free(ht);
}

int main() {
    HashTable *db = create_hash_table();

    put(db, "John", 25);
    put(db, "Alice", 30);
    put(db, "Bob", 22);

    printf("John's age is %d\n", get(db, "John"));
    printf("Alice's age is %d\n", get(db, "Alice"));
    printf("Bob's age is %d\n", get(db, "Bob"));

    destroy_hash_table(db);

    return 0;
}