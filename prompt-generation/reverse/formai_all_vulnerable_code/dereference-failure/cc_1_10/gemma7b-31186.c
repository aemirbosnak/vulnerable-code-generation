//Gemma-7B DATASET v1.0 Category: Cryptographic hash function ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define HASH_SIZE 1024

typedef struct HashNode {
    char *data;
    struct HashNode *next;
} HashNode;

void hash_init(HashNode **head) {
    *head = NULL;
}

void hash_insert(HashNode **head, char *data) {
    HashNode *newNode = malloc(sizeof(HashNode));
    newNode->data = strdup(data);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

int hash_search(HashNode *head, char *data) {
    for (HashNode *node = head; node != NULL; node = node->next) {
        if (strcmp(node->data, data) == 0) {
            return 1;
        }
    }

    return 0;
}

int main() {
    HashNode *head = NULL;

    hash_init(&head);
    hash_insert(&head, "Alice");
    hash_insert(&head, "Bob");
    hash_insert(&head, "Charlie");

    if (hash_search(head, "Alice") == 1) {
        printf("Alice is in the hash table.\n");
    }

    if (hash_search(head, "Dave") == 0) {
        printf("Dave is not in the hash table.\n");
    }

    return 0;
}