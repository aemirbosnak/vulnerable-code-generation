//Gemma-7B DATASET v1.0 Category: Cryptographic hash function ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define HASH_SIZE 16

typedef struct HashNode {
    uint32_t key;
    struct HashNode* next;
} HashNode;

HashNode* hash_insert(HashNode* head, uint32_t key) {
    HashNode* newNode = malloc(sizeof(HashNode));
    newNode->key = key;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        HashNode* current = head;
        HashNode* previous = NULL;
        while (current) {
            if (key < current->key) {
                previous = current;
                current = current->next;
            } else if (key == current->key) {
                return NULL;
            }
        }
        previous->next = newNode;
    }

    return head;
}

uint32_t hash_search(HashNode* head, uint32_t key) {
    HashNode* current = head;
    while (current) {
        if (key == current->key) {
            return current->key;
        } else if (key < current->key) {
            current = current->next;
        }
    }

    return -1;
}

int main() {
    HashNode* head = NULL;
    head = hash_insert(head, 10);
    head = hash_insert(head, 20);
    head = hash_insert(head, 30);
    head = hash_insert(head, 40);
    head = hash_insert(head, 50);

    uint32_t result = hash_search(head, 20);
    if (result != -1) {
        printf("Key found: %d\n", result);
    } else {
        printf("Key not found\n");
    }

    return 0;
}