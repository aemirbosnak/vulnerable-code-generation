//Gemma-7B DATASET v1.0 Category: Cryptographic hash function ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1024

typedef struct HashNode {
    char *data;
    struct HashNode *next;
} HashNode;

HashNode *insert(HashNode *head, char *data) {
    HashNode *newNode = malloc(sizeof(HashNode));
    newNode->data = strdup(data);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        HashNode *currNode = head;
        while (currNode->next != NULL) {
            currNode = currNode->next;
        }
        currNode->next = newNode;
    }

    return head;
}

int hashFunction(char *str) {
    int hashValue = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        hashValue = (hashValue * 33) + str[i];
    }

    return hashValue;
}

int main() {
    HashNode *head = NULL;
    insert(head, "Alice");
    insert(head, "Bob");
    insert(head, "Charlie");
    insert(head, "Dave");

    char *str = "Alice";
    int hash = hashFunction(str);

    printf("Hash value for %s: %d\n", str, hash);

    return 0;
}