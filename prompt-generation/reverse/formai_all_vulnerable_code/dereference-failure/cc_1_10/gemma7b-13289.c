//Gemma-7B DATASET v1.0 Category: Cryptographic hash function ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 4096

typedef struct HashNode {
    char *key;
    struct HashNode *next;
} HashNode;

HashNode *insertHashNode(HashNode *head, char *key) {
    HashNode *newNode = malloc(sizeof(HashNode));
    newNode->key = strdup(key);
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

int hashFunction(char *key) {
    int hashValue = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        hashValue = (hashValue * 33) + key[i];
    }

    return hashValue;
}

int main() {
    HashNode *head = NULL;
    insertHashNode(head, "Alice");
    insertHashNode(head, "Bob");
    insertHashNode(head, "Charlie");

    int hashValue = hashFunction("Alice");
    printf("Hash value of Alice: %d\n", hashValue);

    return 0;
}