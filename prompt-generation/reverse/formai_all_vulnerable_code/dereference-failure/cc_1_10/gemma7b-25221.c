//Gemma-7B DATASET v1.0 Category: Data structures visualization ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    Node* node = malloc(sizeof(Node));
    node->data = key;
    node->next = NULL;

    if (ht->buckets[hash] == NULL) {
        ht->buckets[hash] = node;
    } else {
        Node* current = ht->buckets[hash];
        while (current->next) {
            current = current->next;
        }
        current->next = node;
    }
}

void print_hash_table(HashTable* ht) {
    for (int i = 0; i < ht->size; i++) {
        if (ht->buckets[i] != NULL) {
            Node* current = ht->buckets[i];
            printf("Bucket %d: ", i);
            while (current) {
                printf("%c ", current->data);
                current = current->next;
            }
            printf("\n");
        }
    }
}

int main() {
    HashTable* ht = malloc(sizeof(HashTable));
    ht->size = 10;
    ht->buckets = malloc(sizeof(Node*) * ht->size);

    insert(ht, 'a');
    insert(ht, 'b');
    insert(ht, 'c');
    insert(ht, 'd');
    insert(ht, 'e');

    print_hash_table(ht);

    return 0;
}