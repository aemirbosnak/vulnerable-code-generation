//Gemma-7B DATASET v1.0 Category: Cryptographic hash function ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

#define HASH_SIZE 16
#define HASH_PRIME 3

typedef struct HashNode {
    uint64_t key;
    struct HashNode* next;
} HashNode;

void hash_init(HashNode** head) {
    *head = NULL;
}

void hash_add(HashNode** head, uint64_t key) {
    HashNode* newNode = malloc(sizeof(HashNode));
    newNode->key = key;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        HashNode* current = *head;
        HashNode* previous = NULL;
        while (current) {
            if (key < current->key) {
                previous = current;
                current = current->next;
            } else if (key == current->key) {
                printf("Error: key already exists.\n");
                return;
            }
        }

        previous->next = newNode;
    }
}

uint64_t hash_get(HashNode* head, uint64_t key) {
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
    hash_init(&head);

    hash_add(&head, 10);
    hash_add(&head, 20);
    hash_add(&head, 30);
    hash_add(&head, 40);

    uint64_t result = hash_get(head, 20);

    if (result != -1) {
        printf("Key found: %ld\n", result);
    } else {
        printf("Key not found.\n");
    }

    return 0;
}