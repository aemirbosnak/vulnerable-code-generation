//Gemma-7B DATASET v1.0 Category: Cryptographic hash function ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define HASH_SIZE 512
#define HASH_PRIME 11

#define MAX_MESSAGE_SIZE 1024

typedef struct HashNode {
    char *message;
    struct HashNode *next;
} HashNode;

HashNode *hash_insert(HashNode *head, char *message) {
    int hash = hash_function(message);
    HashNode *newNode = malloc(sizeof(HashNode));
    newNode->message = strdup(message);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        HashNode *traverse = head;
        while (traverse->next) {
            traverse = traverse->next;
        }
        traverse->next = newNode;
    }

    return head;
}

int hash_function(char *message) {
    int hash = 0;
    for (int i = 0; message[i] != '\0'; i++) {
        hash = (hash * HASH_PRIME) + message[i];
    }

    return hash % HASH_SIZE;
}

int main() {
    HashNode *head = NULL;
    char message[MAX_MESSAGE_SIZE];

    printf("Enter a message: ");
    fgets(message, MAX_MESSAGE_SIZE, stdin);

    head = hash_insert(head, message);

    printf("Hash of the message: %d\n", hash_function(message));

    return 0;
}