//Gemma-7B DATASET v1.0 Category: Cryptographic hash function ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIGITS 32

typedef struct HashNode {
    char data[MAX_DIGITS];
    struct HashNode* next;
} HashNode;

HashNode* insert(HashNode* head, char* str) {
    HashNode* newNode = malloc(sizeof(HashNode));
    strcpy(newNode->data, str);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        HashNode* traverse = head;
        while (traverse->next) {
            traverse = traverse->next;
        }
        traverse->next = newNode;
    }

    return head;
}

int hashFunction(HashNode* head, char* str) {
    int hashValue = 0;
    char* traverse = str;
    HashNode* current = head;

    while (*traverse) {
        int digit = *traverse - 'a' + 1;
        hashValue = (hashValue * MAX_DIGITS) + digit;
        traverse++;
    }

    return hashValue;
}

int main() {
    HashNode* head = NULL;
    insert(head, "abc");
    insert(head, "bcd");
    insert(head, "cde");

    char* str = "bcd";
    int hashValue = hashFunction(head, str);

    printf("Hash value for str %s is %d\n", str, hashValue);

    return 0;
}