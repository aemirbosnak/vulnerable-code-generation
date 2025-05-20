//Gemma-7B DATASET v1.0 Category: Cryptographic hash function ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define HASH_SIZE 1024
#define HASH_PRIME 3

typedef struct HashNode {
    char data[1024];
    struct HashNode* next;
} HashNode;

void hash_init(HashNode** hashTable) {
    *hashTable = NULL;
}

void hash_insert(HashNode** hashTable, char* data) {
    int hash = hash_calc(data);
    HashNode* newNode = malloc(sizeof(HashNode));
    strcpy(newNode->data, data);
    newNode->next = NULL;

    if (*hashTable == NULL) {
        *hashTable = newNode;
    } else {
        HashNode* current = *hashTable;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

int hash_calc(char* data) {
    int hash = 0;
    for (int i = 0; data[i] != '\0'; i++) {
        hash = (hash * HASH_PRIME) + data[i];
    }
    return hash % HASH_SIZE;
}

int main() {
    HashNode* hashTable;
    hash_init(&hashTable);

    char* data = "Hello, world!";
    hash_insert(&hashTable, data);

    data = "Goodbye, cruel world!";
    hash_insert(&hashTable, data);

    data = "Testing, 1, 2, 3!";
    hash_insert(&hashTable, data);

    for (HashNode* current = hashTable; current; current = current->next) {
        printf("%s\n", current->data);
    }

    return 0;
}