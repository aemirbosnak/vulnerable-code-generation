//Gemma-7B DATASET v1.0 Category: Cryptographic hash function ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 10

#define HASH_PRIME 3

typedef struct HashNode {
    char *key;
    struct HashNode *next;
} HashNode;

HashNode *insert(HashNode *head, char *key) {
    HashNode *newNode = (HashNode *)malloc(sizeof(HashNode));
    newNode->key = strdup(key);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        HashNode *traversal = head;
        while (traversal->next) {
            traversal = traversal->next;
        }
        traversal->next = newNode;
    }

    return head;
}

int hash(char *key) {
    int hashValue = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        hashValue = (hashValue * HASH_PRIME) + key[i];
    }

    return hashValue % HASH_SIZE;
}

int main() {
    HashNode *head = NULL;
    insert(head, "abc");
    insert(head, "bcd");
    insert(head, "cde");

    int hashValue = hash("abc");
    printf("Hash value for 'abc': %d\n", hashValue);

    return 0;
}