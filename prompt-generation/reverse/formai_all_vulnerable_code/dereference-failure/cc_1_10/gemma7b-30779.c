//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Node {
    int data;
    struct Node* next;
} Node;

struct HashTable {
    int size;
    Node** buckets;
};

void insert(struct HashTable* ht, int data) {
    int hash = data % ht->size;
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (ht->buckets[hash] == NULL) {
        ht->buckets[hash] = newNode;
    } else {
        Node* current = ht->buckets[hash];
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

int search(struct HashTable* ht, int data) {
    int hash = data % ht->size;
    Node* current = ht->buckets[hash];

    while (current) {
        if (current->data == data) {
            return 1;
        }
        current = current->next;
    }

    return 0;
}

int main() {
    struct HashTable* ht = malloc(sizeof(struct HashTable));
    ht->size = MAX_SIZE;
    ht->buckets = malloc(MAX_SIZE * sizeof(Node*));

    insert(ht, 10);
    insert(ht, 20);
    insert(ht, 30);
    insert(ht, 40);

    if (search(ht, 20) == 1) {
        printf("20 is found\n");
    }

    free(ht->buckets);
    free(ht);

    return 0;
}