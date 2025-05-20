//Gemma-7B DATASET v1.0 Category: Cryptographic hash function ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define HASH_SIZE 256

typedef struct Node {
    int key;
    struct Node* next;
} Node;

Node* hash_insert(int key, Node* head) {
    Node* newNode = malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }

    return head;
}

int hash_search(int key, Node* head) {
    Node* current = head;
    while (current) {
        if (current->key == key) {
            return 1;
        }
        current = current->next;
    }

    return 0;
}

int main() {
    Node* head = NULL;
    head = hash_insert(10, head);
    head = hash_insert(20, head);
    head = hash_insert(30, head);
    head = hash_insert(40, head);

    if (hash_search(20, head)) {
        printf("20 found!");
    }

    return 0;
}