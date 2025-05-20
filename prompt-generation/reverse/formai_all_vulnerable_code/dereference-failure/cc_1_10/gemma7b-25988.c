//Gemma-7B DATASET v1.0 Category: Cryptographic hash function ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#define MAX_HASH_SIZE 64

typedef struct HashNode {
    char *data;
    struct HashNode *next;
} HashNode;

void hash_init(HashNode **head) {
    *head = NULL;
}

int hash_insert(HashNode **head, char *data) {
    HashNode *newNode = malloc(sizeof(HashNode));
    newNode->data = strdup(data);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }

    return 0;
}

char *hash_search(HashNode *head, char *data) {
    while (head) {
        if (strcmp(head->data, data) == 0) {
            return head->data;
        }
        head = head->next;
    }

    return NULL;
}

int main() {
    HashNode *head = NULL;
    hash_init(&head);

    hash_insert(&head, "John Doe");
    hash_insert(&head, "Jane Doe");
    hash_insert(&head, "Bill Smith");

    char *result = hash_search(head, "Jane Doe");

    if (result) {
        printf("Found: %s\n", result);
    } else {
        printf("Not found\n");
    }

    return 0;
}