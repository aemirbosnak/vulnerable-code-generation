//Gemma-7B DATASET v1.0 Category: Cryptographic hash function ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <openssl/sha.h>

#define HASH_SIZE 256

typedef struct HashNode {
    char *data;
    struct HashNode *next;
} HashNode;

void hash_add(HashNode **head, char *data) {
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
    while (head) {
        if (strcmp(head->data, data) == 0) {
            return 1;
        }
        head = head->next;
    }

    return 0;
}

int main() {
    HashNode *head = NULL;
    char *data = "Hello, world!";

    hash_add(head, data);

    if (hash_search(head, data) == 1) {
        printf("Data found!\n");
    } else {
        printf("Data not found.\n");
    }

    return 0;
}