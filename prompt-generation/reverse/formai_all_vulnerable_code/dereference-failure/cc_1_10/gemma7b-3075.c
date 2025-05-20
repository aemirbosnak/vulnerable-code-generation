//Gemma-7B DATASET v1.0 Category: Cryptographic hash function ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HASH_SIZE 1024

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

int hash_search(HashNode *head, char *data) {
    for (HashNode *curr = head; curr; curr = curr->next) {
        if (strcmp(curr->data, data) == 0) {
            return 1;
        }
    }

    return 0;
}

int main() {
    HashNode *head = NULL;
    hash_init(&head);

    hash_insert(&head, "abc");
    hash_insert(&head, "bcd");
    hash_insert(&head, "cde");
    hash_insert(&head, "def");

    if (hash_search(head, "bcd") == 1) {
        printf("bcd found!\n");
    }

    if (hash_search(head, "xyz") == 0) {
        printf("xyz not found!\n");
    }

    return 0;
}