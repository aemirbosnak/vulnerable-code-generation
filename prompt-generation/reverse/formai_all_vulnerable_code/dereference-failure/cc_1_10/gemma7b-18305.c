//Gemma-7B DATASET v1.0 Category: Cryptographic hash function ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define HASH_SIZE 1024

struct HashNode {
    char *data;
    struct HashNode *next;
};

void hash_insert(struct HashNode **head, char *data) {
    struct HashNode *newNode = malloc(sizeof(struct HashNode));
    newNode->data = strdup(data);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct HashNode *temp = *head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int hash_search(struct HashNode *head, char *data) {
    struct HashNode *temp = head;
    while (temp) {
        if (strcmp(temp->data, data) == 0) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int main() {
    struct HashNode *head = NULL;
    hash_insert(&head, "a");
    hash_insert(&head, "b");
    hash_insert(&head, "c");
    hash_insert(&head, "d");

    if (hash_search(head, "b") == 1) {
        printf("b is in the hash table.\n");
    }

    return 0;
}