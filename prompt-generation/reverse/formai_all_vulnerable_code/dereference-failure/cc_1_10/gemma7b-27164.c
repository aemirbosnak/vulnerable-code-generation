//Gemma-7B DATASET v1.0 Category: QR code generator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 256

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct HashTable {
    int size;
    Node** table;
} HashTable;

void insert(HashTable* ht, int data) {
    int hash = data % ht->size;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = ht->table[hash];
    ht->table[hash] = newNode;
}

int search(HashTable* ht, int data) {
    int hash = data % ht->size;
    Node* current = ht->table[hash];
    while (current) {
        if (current->data == data) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int main() {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    ht->size = MAX_SIZE;
    ht->table = (Node**)malloc(sizeof(Node*) * MAX_SIZE);

    insert(ht, 10);
    insert(ht, 20);
    insert(ht, 30);
    insert(ht, 40);
    insert(ht, 50);

    if (search(ht, 20)) {
        printf("Data found!\n");
    } else {
        printf("Data not found.\n");
    }

    return 0;
}