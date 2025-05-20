//Gemma-7B DATASET v1.0 Category: Cryptographic hash function ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_HASH_SIZE 1024

typedef struct Node {
    uint32_t hash_value;
    struct Node* next;
} Node;

Node* hash_insert(Node* head, uint32_t hash_value) {
    Node* new_node = malloc(sizeof(Node));
    new_node->hash_value = hash_value;
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

uint32_t hash(char* str) {
    uint32_t hash_value = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        hash_value = (hash_value * 33) + str[i];
    }

    return hash_value;
}

int main() {
    Node* head = NULL;

    char* str1 = "Donald Knuth";
    hash_insert(head, hash(str1));

    char* str2 = "SEDTA";
    hash_insert(head, hash(str2));

    char* str3 = "The quick brown fox jumps over the lazy dog";
    hash_insert(head, hash(str3));

    for (Node* current = head; current; current = current->next) {
        printf("Hash value for %s: %d\n", current->hash_value, current->hash_value);
    }

    return 0;
}