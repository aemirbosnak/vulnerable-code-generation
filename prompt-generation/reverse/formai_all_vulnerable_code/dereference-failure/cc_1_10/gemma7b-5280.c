//Gemma-7B DATASET v1.0 Category: Cryptographic hash function ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define HASH_SIZE 256
#define HASH_PRIME 11

typedef struct HashNode {
    uint32_t key;
    struct HashNode* next;
} HashNode;

HashNode* hash_insert(HashNode* head, uint32_t key) {
    int hash = key % HASH_SIZE;
    HashNode* node = malloc(sizeof(HashNode));
    node->key = key;
    node->next = NULL;

    if (head == NULL) {
        head = node;
    } else {
        HashNode* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = node;
    }

    return head;
}

uint32_t hash_lookup(HashNode* head, uint32_t key) {
    int hash = key % HASH_SIZE;
    HashNode* current = head;

    while (current) {
        if (current->key == key) {
            return 1;
        }
        current = current->next;
    }

    return 0;
}

int main() {
    HashNode* head = NULL;
    hash_insert(head, 10);
    hash_insert(head, 20);
    hash_insert(head, 30);
    hash_insert(head, 40);

    if (hash_lookup(head, 20) == 1) {
        printf("Key 20 found!\n");
    }

    return 0;
}