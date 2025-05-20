//Gemma-7B DATASET v1.0 Category: Cryptographic hash function ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define HASH_SIZE 256

typedef struct Node {
    uint32_t data;
    struct Node* next;
} Node;

Node* hash_insert(Node* head, uint32_t data) {
    Node* new_node = malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_node;
    }

    return head;
}

uint32_t hash_search(Node* head, uint32_t data) {
    Node* current = head;
    while (current) {
        if (current->data == data) {
            return 1;
        }
        current = current->next;
    }

    return 0;
}

uint32_t hash_function(char* str) {
    uint32_t hash = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        hash = (hash * 33) + str[i];
    }

    return hash;
}

int main() {
    Node* head = NULL;
    head = hash_insert(head, hash_function("abc"));
    head = hash_insert(head, hash_function("def"));
    head = hash_insert(head, hash_function("ghi"));

    if (hash_search(head, hash_function("abc")) == 1) {
        printf("abc is in the hash table\n");
    }

    if (hash_search(head, hash_function("xyz")) == 0) {
        printf("xyz is not in the hash table\n");
    }

    return 0;
}