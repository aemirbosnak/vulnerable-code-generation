//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    int index;
} Node;

typedef struct {
    Node* data;
    int size;
} HashTable;

void initHashTable(HashTable* ht) {
    ht->data = (Node*)malloc(MAX_SIZE * sizeof(Node));
    ht->size = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        ht->data[i].index = -1;
    }
}

int hash(int key, int size) {
    return key % size;
}

void insert(HashTable* ht, int key, int value) {
    int index = hash(key, ht->size);
    while (ht->data[index].index!= -1) {
        index = (index + 1) % ht->size;
    }
    ht->data[index].data = value;
    ht->data[index].index = key;
    ht->size++;
}

void display(HashTable* ht) {
    for (int i = 0; i < ht->size; i++) {
        if (ht->data[i].index!= -1) {
            printf("%d -> %d\n", ht->data[i].index, ht->data[i].data);
        }
    }
}

int main() {
    srand(time(NULL));
    HashTable ht;
    initHashTable(&ht);

    for (int i = 0; i < 10; i++) {
        int key = rand() % MAX_SIZE;
        int value = rand() % MAX_SIZE;
        insert(&ht, key, value);
    }

    display(&ht);

    return 0;
}