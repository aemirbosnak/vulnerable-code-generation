//Gemma-7B DATASET v1.0 Category: Simple Web Server ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char data;
    struct Node* next;
} Node;

struct HashTable {
    int size;
    Node** buckets;
};

void insert(struct HashTable* hashTable, char data) {
    int index = data % hashTable->size;
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = hashTable->buckets[index];
    hashTable->buckets[index] = newNode;
}

int search(struct HashTable* hashTable, char data) {
    int index = data % hashTable->size;
    Node* current = hashTable->buckets[index];
    while (current) {
        if (current->data == data) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int main() {
    struct HashTable* hashTable = malloc(sizeof(struct HashTable));
    hashTable->size = 10;
    hashTable->buckets = malloc(hashTable->size * sizeof(Node*));

    insert(hashTable, 'a');
    insert(hashTable, 'b');
    insert(hashTable, 'c');
    insert(hashTable, 'd');

    if (search(hashTable, 'a') == 1) {
        printf("a is in the hash table\n");
    }

    free(hashTable->buckets);
    free(hashTable);

    return 0;
}