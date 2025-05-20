//Gemma-7B DATASET v1.0 Category: Cryptographic hash function ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 256

typedef struct HashNode {
    char *key;
    struct HashNode *next;
} HashNode;

void hash_insert(HashNode **head, char *key) {
    HashNode *newNode = malloc(sizeof(HashNode));
    newNode->key = strdup(key);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        HashNode *current = *head;
        HashNode *previous = NULL;
        while (current) {
            if (strcmp(newNode->key, current->key) == 0) {
                return;
            } else if (previous == NULL) {
                *head = newNode;
            } else {
                previous = current;
                current = current->next;
            }
        }
        previous->next = newNode;
    }
}

int hash_search(HashNode *head, char *key) {
    HashNode *current = head;
    while (current) {
        if (strcmp(key, current->key) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int main() {
    HashNode *head = NULL;
    hash_insert(&head, "a");
    hash_insert(&head, "b");
    hash_insert(&head, "c");
    hash_insert(&head, "d");

    if (hash_search(head, "b") == 1) {
        printf("b is in the hash table.\n");
    }

    return 0;
}