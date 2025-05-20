//Gemma-7B DATASET v1.0 Category: Cryptographic hash function ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define HASH_SIZE 1024

typedef struct HashNode {
    char *data;
    struct HashNode *next;
} HashNode;

void hash_init(HashNode **head) {
    *head = NULL;
}

int hash_add(HashNode **head, char *data) {
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

    hash_init(&head);

    hash_add(head, "John Doe");
    hash_add(head, "Jane Doe");
    hash_add(head, "Bill Smith");

    if (hash_search(head, "John Doe")) {
        printf("John Doe is in the hash table.\n");
    }

    if (hash_search(head, "Bob Smith")) {
        printf("Bob Smith is not in the hash table.\n");
    }

    return 0;
}