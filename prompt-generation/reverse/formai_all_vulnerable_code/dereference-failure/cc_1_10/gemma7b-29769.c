//Gemma-7B DATASET v1.0 Category: Cryptographic hash function ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 1024

typedef struct Node {
    struct Node* next;
    int data;
} Node;

void hash_insert(int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    Node* head = (Node*)malloc(sizeof(Node));
    if (head == NULL) {
        return;
    }

    if (head->next == NULL) {
        head->next = newNode;
    } else {
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

int hash_search(int data) {
    Node* head = (Node*)malloc(sizeof(Node));
    if (head == NULL) {
        return -1;
    }

    Node* current = head->next;
    while (current) {
        if (current->data == data) {
            return 1;
        }
        current = current->next;
    }

    return -1;
}

int main() {
    hash_insert(10);
    hash_insert(20);
    hash_insert(30);
    hash_insert(40);
    hash_insert(50);

    if (hash_search(20) == 1) {
        printf("20 found!\n");
    }

    if (hash_search(60) == -1) {
        printf("60 not found!\n");
    }

    return 0;
}