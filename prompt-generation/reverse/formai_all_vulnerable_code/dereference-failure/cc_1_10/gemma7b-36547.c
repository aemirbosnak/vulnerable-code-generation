//Gemma-7B DATASET v1.0 Category: Cryptographic hash function ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define HASH_SIZE 16

typedef struct HashNode {
    char data[HASH_SIZE];
    struct HashNode* next;
} HashNode;

void hash_add(HashNode** head, char* data) {
    HashNode* newNode = malloc(sizeof(HashNode));
    newNode->data[0] = '\0';
    strcpy(newNode->data, data);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

int hash_find(HashNode* head, char* data) {
    for (HashNode* node = head; node; node = node->next) {
        if (strcmp(node->data, data) == 0) {
            return 1;
        }
    }

    return 0;
}

int main() {
    HashNode* head = NULL;
    char data[] = "Hello, world!";

    hash_add(&head, data);

    if (hash_find(head, data)) {
        printf("Data found!\n");
    } else {
        printf("Data not found.\n");
    }

    return 0;
}