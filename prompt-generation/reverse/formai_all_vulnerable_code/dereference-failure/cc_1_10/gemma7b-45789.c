//Gemma-7B DATASET v1.0 Category: Cryptographic hash function ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#define HASH_SIZE 64

typedef struct HashNode {
    char *data;
    struct HashNode *next;
} HashNode;

HashNode *insert(HashNode *head, char *data)
{
    HashNode *newNode = malloc(sizeof(HashNode));
    newNode->data = strdup(data);
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

int main()
{
    HashNode *head = NULL;

    char *data = "Hello, world!";
    insert(head, data);

    data = "Goodbye, cruel world!";
    insert(head, data);

    data = "This is a hash function!";
    insert(head, data);

    // Hash the data
    unsigned char hash[HASH_SIZE];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, head->data, strlen(head->data));
    SHA256_Final(hash, &sha256);

    // Print the hash
    for (int i = 0; i < HASH_SIZE; i++) {
        printf("%x ", hash[i]);
    }

    printf("\n");

    return 0;
}