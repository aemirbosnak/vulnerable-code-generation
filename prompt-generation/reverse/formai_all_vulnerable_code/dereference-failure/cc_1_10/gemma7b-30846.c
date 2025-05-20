//Gemma-7B DATASET v1.0 Category: Data structures visualization ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a Node structure
typedef struct Node {
    char data;
    struct Node* next;
} Node;

// Define a Hash Table structure
typedef struct HashTable {
    int size;
    Node** buckets;
} HashTable;

// Function to insert a key-value pair into a Hash Table
void insert(HashTable* ht, char key, int value) {
    // Calculate the hash value of the key
    int hash = key % ht->size;

    // Create a new Node if necessary
    if (ht->buckets[hash] == NULL) {
        ht->buckets[hash] = malloc(sizeof(Node));
    }

    // Insert the Node into the bucket
    ht->buckets[hash]->data = key;
    ht->buckets[hash]->next = NULL;
}

int main() {
    // Create a Hash Table
    HashTable* ht = malloc(sizeof(HashTable));
    ht->size = 10;
    ht->buckets = (Node**)malloc(sizeof(Node*) * ht->size);

    // Insert key-value pairs
    insert(ht, 'a', 10);
    insert(ht, 'b', 20);
    insert(ht, 'c', 30);
    insert(ht, 'd', 40);

    // Print the key-value pairs
    for (int i = 0; i < ht->size; i++) {
        Node* node = ht->buckets[i];
        while (node) {
            printf("%c: %d\n", node->data, node->next);
            node = node->next;
        }
    }

    return 0;
}