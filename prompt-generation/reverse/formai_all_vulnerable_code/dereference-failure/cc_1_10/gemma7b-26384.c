//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Node {
    char name[MAX_SIZE];
    struct Node* next;
} Node;

struct HashTable {
    Node** buckets;
    int size;
    int collisions;
};

void insert(struct HashTable* ht, char* name) {
    int hash = hashFunction(name);
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = ht->buckets[hash] ? ht->buckets[hash] : NULL;
    ht->buckets[hash] = newNode;
    ht->collisions++;
}

int hashFunction(char* name) {
    return (int)name[0] % MAX_SIZE;
}

void printIndex(struct HashTable* ht) {
    for (int i = 0; i < ht->size; i++) {
        Node* current = ht->buckets[i];
        while (current) {
            printf("%s ", current->name);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    struct HashTable* ht = malloc(sizeof(struct HashTable));
    ht->size = MAX_SIZE;
    ht->buckets = (Node**)malloc(MAX_SIZE * sizeof(Node));
    ht->collisions = 0;

    insert(ht, "Romeo");
    insert(ht, "Juliet");
    insert(ht, "Benvolio");
    insert(ht, "Mercutio");
    insert(ht, "Tybalt");
    insert(ht, "Friar Lawrence");

    printIndex(ht);

    return 0;
}