//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 1000

typedef struct {
    int data;
    int key;
} Node;

typedef struct {
    Node *array;
    int size;
} HashTable;

void init(HashTable *hashTable) {
    hashTable->array = (Node*)malloc(MAX_SIZE*sizeof(Node));
    hashTable->size = 0;
}

int hash(int key, int size) {
    return key % size;
}

void insert(HashTable *hashTable, int key, int data) {
    int index = hash(key, hashTable->size);
    Node *node = &hashTable->array[index];
    while (node->key!= -1) {
        if (node->key == key) {
            node->data = data;
            return;
        }
        node = (node + 1);
    }
    node->key = key;
    node->data = data;
    hashTable->size++;
}

int search(HashTable *hashTable, int key) {
    int index = hash(key, hashTable->size);
    Node *node = &hashTable->array[index];
    while (node->key!= -1) {
        if (node->key == key) {
            return node->data;
        }
        node = (node + 1);
    }
    return -1;
}

int main() {
    HashTable hashTable;
    init(&hashTable);

    insert(&hashTable, 10, 100);
    insert(&hashTable, 20, 200);
    insert(&hashTable, 30, 300);
    insert(&hashTable, 40, 400);
    insert(&hashTable, 50, 500);

    printf("Search for 20: %d\n", search(&hashTable, 20));
    printf("Search for 30: %d\n", search(&hashTable, 30));
    printf("Search for 40: %d\n", search(&hashTable, 40));
    printf("Search for 50: %d\n", search(&hashTable, 50));
    printf("Search for 60: %d\n", search(&hashTable, 60));

    return 0;
}