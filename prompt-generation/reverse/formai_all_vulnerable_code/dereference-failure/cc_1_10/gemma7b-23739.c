//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Node {
    int data;
    struct Node* next;
} Node;

struct HashTable {
    Node** buckets;
    int size;
    int loadFactor;
    int capacity;
};

void insert(struct HashTable* hashTable, int data) {
    int bucketIndex = data % hashTable->size;
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (hashTable->buckets[bucketIndex] == NULL) {
        hashTable->buckets[bucketIndex] = newNode;
    } else {
        Node* current = hashTable->buckets[bucketIndex];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

int search(struct HashTable* hashTable, int data) {
    int bucketIndex = data % hashTable->size;
    Node* current = hashTable->buckets[bucketIndex];

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
    hashTable->buckets = malloc(sizeof(Node*) * hashTable->size);
    hashTable->loadFactor = 0;
    hashTable->capacity = 10;

    insert(hashTable, 10);
    insert(hashTable, 20);
    insert(hashTable, 30);
    insert(hashTable, 40);
    insert(hashTable, 50);

    if (search(hashTable, 40)) {
        printf("Data found.\n");
    } else {
        printf("Data not found.\n");
    }

    return 0;
}