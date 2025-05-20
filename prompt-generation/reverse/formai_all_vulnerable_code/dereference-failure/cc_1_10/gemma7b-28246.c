//Gemma-7B DATASET v1.0 Category: Data mining ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct HashTable {
    int size;
    Node** buckets;
} HashTable;

void insert(HashTable* ht, char data) {
    int hash = data % ht->size;
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = ht->buckets[hash];
    ht->buckets[hash] = node;
}

char search(HashTable* ht, char data) {
    int hash = data % ht->size;
    Node* node = ht->buckets[hash];
    while (node) {
        if (node->data == data) {
            return 1;
        }
        node = node->next;
    }
    return 0;
}

int main() {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    ht->size = MAX;
    ht->buckets = (Node**)malloc(MAX * sizeof(Node*));

    insert(ht, 'a');
    insert(ht, 'b');
    insert(ht, 'c');
    insert(ht, 'd');
    insert(ht, 'e');

    if (search(ht, 'a') == 1) {
        printf("a is found\n");
    }

    if (search(ht, 'f') == 0) {
        printf("f is not found\n");
    }

    return 0;
}