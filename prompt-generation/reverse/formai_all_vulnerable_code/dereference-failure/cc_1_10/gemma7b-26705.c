//Gemma-7B DATASET v1.0 Category: Cryptographic hash function ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char data[MAX_BUFFER_SIZE];
    struct Node* next;
} Node;

Node* InsertNode(Node* head, char* data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
        head = newNode;
    }

    strcpy(newNode->data, data);

    return head;
}

int HashFunction(Node* head) {
    int hash = 0;
    Node* current = head;

    while (current) {
        hash = (hash << 1) ^ hash + strlen(current->data);
        current = current->next;
    }

    return hash;
}

int main() {
    Node* head = NULL;

    InsertNode(head, "John Doe");
    InsertNode(head, "Jane Doe");
    InsertNode(head, "Peter Pan");

    int hash = HashFunction(head);

    printf("Hash: %d", hash);

    return 0;
}