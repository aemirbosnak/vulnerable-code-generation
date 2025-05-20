//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INDEX_SIZE 1024

typedef struct Node {
    char key[20];
    struct Node* next;
} Node;

struct HashTable {
    Node** buckets;
    int size;
    int count;
};

int hash(char* key) {
    int hash_value = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        hash_value = (hash_value * 33) + key[i];
    }
    return hash_value % MAX_INDEX_SIZE;
}

void insert(struct HashTable* ht, char* key) {
    int bucket_index = hash(key);
    Node* new_node = malloc(sizeof(Node));
    strcpy(new_node->key, key);
    new_node->next = NULL;

    if (ht->buckets[bucket_index] == NULL) {
        ht->buckets[bucket_index] = new_node;
    } else {
        Node* current_node = ht->buckets[bucket_index];
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }

    ht->count++;
}

int search(struct HashTable* ht, char* key) {
    int bucket_index = hash(key);
    Node* current_node = ht->buckets[bucket_index];

    while (current_node) {
        if (strcmp(current_node->key, key) == 0) {
            return 1;
        }
        current_node = current_node->next;
    }

    return 0;
}

int main() {
    struct HashTable* ht = malloc(sizeof(struct HashTable));
    ht->size = MAX_INDEX_SIZE;
    ht->buckets = (Node**)malloc(sizeof(Node*) * MAX_INDEX_SIZE);
    ht->count = 0;

    insert(ht, "John Doe");
    insert(ht, "Jane Doe");
    insert(ht, "Peter Pan");
    insert(ht, "Mary Poppins");

    if (search(ht, "John Doe")) {
        printf("John Doe is in the hash table.\n");
    }

    if (search(ht, "Mary Poppins")) {
        printf("Mary Poppins is in the hash table.\n");
    }

    return 0;
}