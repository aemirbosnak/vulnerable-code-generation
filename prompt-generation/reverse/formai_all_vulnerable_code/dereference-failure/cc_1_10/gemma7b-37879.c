//Gemma-7B DATASET v1.0 Category: Data structures visualization ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct HashTable {
    int size;
    Node** buckets;
} HashTable;

void insert(HashTable* ht, char key) {
    int hash = key % ht->size;
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = key;
    node->next = ht->buckets[hash];
    ht->buckets[hash] = node;
}

void search(HashTable* ht, char key) {
    int hash = key % ht->size;
    Node* current = ht->buckets[hash];
    while (current) {
        if (current->data == key) {
            printf("Key found: %c\n", key);
            return;
        }
        current = current->next;
    }
    printf("Key not found: %c\n", key);
}

int main() {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    ht->size = MAX_SIZE;
    ht->buckets = (Node**)malloc(MAX_SIZE * sizeof(Node*));

    insert(ht, 'a');
    insert(ht, 'b');
    insert(ht, 'c');
    insert(ht, 'd');
    insert(ht, 'e');

    search(ht, 'b');
    search(ht, 'f');

    return 0;
}